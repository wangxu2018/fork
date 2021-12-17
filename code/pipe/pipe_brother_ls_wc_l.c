// 兄弟进程之间实现 ls | wc -l 操作

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int fd[2], i;
	
	pipe(fd);

	for (i = 0; i < 2; i++) {
		if((pid = fork()) == 0) {
			break;
        }
    }

	if (i == 0) {						// 兄进程
		close(fd[0]);					// 写,关闭读端
		dup2(fd[1], STDOUT_FILENO);		// 重定向fd[1]为标准输出，即输出到屏幕上	
		execlp("ls", "ls", NULL);		// 兄进程执行ls操作，并且传入到管道中
	} else if (i == 1) {				// 弟进程
		close(fd[1]);					// 读，关闭写端
		dup2(fd[0], STDIN_FILENO);		// 重定向fd[0]为标准输入，即从屏幕上读取数据
		execlp("wc", "wc", "-l", NULL);	// 对于读取的数据执行wc -l 操作
	} else {
        close(fd[0]);					// 父进程关闭读端写端，使得管道只有一个写端一个读端
        close(fd[1]);
		for(i = 0; i < 2; i++) {		// 阻塞回收两个子进程
			wait(NULL);
		}
	}

	return 0;
}
