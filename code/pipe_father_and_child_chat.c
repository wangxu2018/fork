// 创建管道，实现父子进程之间通信 

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(void)
{
    pid_t pid;
    int fd[2];
    
   if (pipe(fd) == -1) 
       sys_err("pipe");

   pid = fork();
   if (pid < 0) {
       sys_err("fork err");
   } else if (pid == 0) {   // 子进程读取写入数据
        close(fd[1]);
        char buf[1024];
        int len = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        close(fd[0]);
   } else {                 // 父进程管道中写入并且阻塞等待回收子进程
       close(fd[0]);
       char *strs = "test for pipe\n";
       write(fd[1], strs, strlen(strs));
       wait(NULL);
       close(fd[1]);
   }
    
    return 0;
}
