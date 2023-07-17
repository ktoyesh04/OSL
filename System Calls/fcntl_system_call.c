#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

void main(){
    int fd = open("file1.txt", O_RDONLY);
    if(fd == -1){
        perror("Error");
        return;
    }
    int flags = fcntl(fd, F_GETFL);
    if(flags == -1){
        perror("Error");
        close(fd);
        return;
    }
    if((flags & O_ACCMODE) == O_RDONLY)
        printf("File is read only\n");
    else if((flags & O_ACCMODE) == O_WRONLY)
        printf("File is write only\n");
    else if((flags & O_ACCMODE) == O_RDWR)
        printf("File is read write\n");
    else
        printf("File access mode unknown\n");
    close(fd);
}
