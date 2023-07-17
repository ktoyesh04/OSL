#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define fifoc "/tmp/fifo"

void main(){
    int fd;
    char buff[100], data[]="hello";

    mkfifo(fifoc, 0666);

    fd = open(fifoc, O_WRONLY);
    write(fd, data, sizeof(data));
    close(fd);

    fd = open(fifoc, O_RDONLY);
    read(fd, buff, sizeof(buff));
    printf("Data read from FIFO: %s", buff);
    close(fd);

    unlink(fifoc);
}
