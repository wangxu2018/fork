// 循环创建5个子进程

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = 5;						//默认创建5个子进程

	int i;
	for (i = 0; i < n; i++) {		//出口1, 父进程专用出口, 循环结束
		if(fork() == 0) { break; }	//出口2, 子进程出口, 判断时子进程直接退出，避免子进程再重复创建子进程
	} 		

	if (n == i) {
		sleep(n);
		printf("parent, pid = %d\n", getpid());
	} else {
		sleep(i);
		printf("%dth child, pid = %d\n", i+1, getpid());
	}

	return 0;
}
