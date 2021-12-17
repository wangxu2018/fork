# fork
## **进程相关的知识记录**

- **进程相关概述.md**
  - 进程和程序
  - MMU
  - 虚拟内存地址
  - 进程控制块
  - 父子进程
  - 僵尸进程、孤儿进程
  
- **C-相关函数.md**
  - fork
  - getpid
  - wait
  - waitpid
  
- **code**
  
  - simple-fork/a_create_fork.c
    - 创建进程练习
  - simple-fork/b_create_five_child_forks.c
    - 创建多进程
  - simple-fork/c_wait_child_process.c
    - wait阻塞回收子进程
  - simple-fork/d_create_proc_wait_check_status.c
    - wait阻塞回收子进程并且检查子进程返回的状态
  - simple-fork/e_waitpid_child_proc_noblock.c
    - waitpid非阻塞循环回收指定pid的子进程
  - simple-fork/f_waitpid_child_proc_block.c
    - waitpid阻塞回收指定pid的子进程
    
    

- **进程间通信方式-管道.md**
  - 详细请阅读该文档



- **进程间通信方式-mmap.md**
  - 详细请阅读该文档



- **进程间通信方式-信号.md**
  - 详细请阅读该文档



- **进程间通信方式-socket.md**
  - 详细请阅读该文档

