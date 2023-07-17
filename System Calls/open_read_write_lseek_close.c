#include<unistd.h>
#include<stdio.h>
#define O_RDWR 02

void main(){
    int f;
    char buff[50];
    f = open("file1.txt", O_RDWR);
    read(f, buff, 10);
    write(1, buff, 10);
    lseek(f, -5, SEEK_END);
    read(f, buff, 5);
    write(1, buff, 5);
    write(f, "Hello", 5);
    close(f);
}