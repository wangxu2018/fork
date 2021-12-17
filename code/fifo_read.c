// 实现fifo非血缘关系进程之间的通信
// 该文件实现的创建fifo、读端

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void sys_err(char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char *argv[])
{
    int fd, len;
    char buf[4096];

    int ret = mkfifo("mytestfifo", 0664);
    if (ret == -1) {
        sys_err("mkfifo error");
    }

    fd = open("mytestfifo", O_RDONLY);      // 打开管道文件
    if (fd < 0) {
        sys_err("open error");
    }

    while (1) {
        len = read(fd, buf, sizeof(buf));   // 从管道的读端获取数据
        write(STDOUT_FILENO, buf, len);     // 打印到屏幕上
        sleep(2);                           // 多個读端时应增加睡眠秒数,放大效果.
    }
    close(fd);

    return 0;
}
