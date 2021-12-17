// wait回收进程并且打印状态

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if(pid == -1){
		perror("fork error");
		exit(1);
	} else if(pid == 0){		//son
		printf("I'm process child, pid = %d\n", getpid());
		sleep(1);				
		exit(10);

	} else {
		wpid = wait(&status);	//传出参数

		if(WIFEXITED(status)){	//正常退出
			printf("parent process, child process %d exit normally\n", wpid);
			printf("return value:%d\n", WEXITSTATUS(status));	// 获取status，并打印，该status为进程退出返回的值

		} else if (WIFSIGNALED(status)) {	//异常退出
			printf("child process exit abnormally, killed by signal %d\n", WTERMSIG(status)); //获取信号编号
		} else {
			printf("other...\n");
		}
	}

	return 0;
}