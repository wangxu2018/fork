// wait阻塞等待回收进程

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid, wpid;

	pid = fork();

	if(pid == -1){
		perror("fork error");
		exit(1);
	} else if(pid == 0){
		printf("child process, pid = %d\n", getpid());
		sleep(7);
	} else {
		wpid = wait(NULL);
		if(wpid == -1){
			perror("wait error");
			return -1;
		}
		printf("parent process, catched child process, pid = %d\n", wpid);
	}

	return 0;
}