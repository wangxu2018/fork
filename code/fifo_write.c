// 实现fifo非血缘关系进程之间的通信
// 该文件实现的写端

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

    fd = open("mytestfifo", O_WRONLY);      // 打开管道文件
    if (fd < 0) {
        sys_err("open error");
    }

    int i = 0;
    while (1) {
        sprintf(buf, "hello num %d\n", i++);
        write(fd, buf, strlen(buf));        
        sleep(2);
    }
    close(fd);

    return 0;
}
