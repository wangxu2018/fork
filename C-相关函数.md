# **C 相关函数**

- **pid_t fork(void)**

```
- 创建子进程，父子进程各自返回
- 创建成功后，父进程返回子进程pid，子进程返回0
```

- **getpid()，getppid()**

```
- 获取父进程的id、父父继承的id
```

- **wait：阻塞回收子进程退出资源，回收任意一个**

```
pid_t wait(int *status)
参数：（传出）回收进程的状态。
返回值：成功返回回收进程的pid；失败返回-1，errno

- 作用1：阻塞等待子进程退出（只回收一个子进程）
- 作用2：清理子进程残留在内核的 pcb 资源
- 作用3：通过传出参数，得到子进程结束状态

	
获取子进程正常终止的状态：
	WIFEXITED(status) --> 为真 --> 调用 WEXITSTATUS(status) --> 得到 子进程 退出值。

获取导致子进程异常终止信号：
	WIFSIGNALED(status) --> 为真 --> 调用 WTERMSIG(status) --> 得到 导致子进程异常终止的信号编号。
```

- **waitpid：指定回收某一进程资源，可以设置非阻塞**

```
pid_t waitpid(pid_t pid, int *status, int options)
参数：
	pid：指定回收子进程pid的资源
		>0: 待回收的子进程pid
		-1：任意子进程
		0：同组的子进程。
	status：（传出） 回收进程的状态。
	options：WNOHANG指定回收方式为非阻塞。

返回值：
    >0: 表成功回收的子进程pid
     0: 函数调用时，参3 指定了WNOHANG，没有子进程结束。
    -1: 失败，errno
```

