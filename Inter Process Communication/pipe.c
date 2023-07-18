#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>

void main(){
    int fd[2], pid;
    char buff[100];
    printf("Pipe is created\x1B");
    if(pipe(fd)==-1) perror("Error in creating pipe");
    if((pid=fork())==-1) perror("Error in fork");
    if(pid>0){
        close(fd[0]);
        write(fd[1], "\x1B Parent writing data into buffer", 50);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        sleep(10000);
        read(fd[0], buff, 50);
        close(fd[0]);
        printf("Child reading data from buffer: %s", buff);
    }
}
