#include<stdio.h>
#include<sys/stat.h>

void main(){
    struct stat fileStat;
    const char* filename = "file1.txt";
    if(stat(filename, &fileStat) == -1){
        perror("stat");
        return;
    }
    printf("Information for %s\n", filename);
    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n", fileStat.st_size);
    printf("Number of Links: \t%ld\n", fileStat.st_nlink);
    printf("File inode: \t\t%ld\n", fileStat.st_ino);
    printf("File Permissions: \t%o\n", fileStat.st_mode&0777);
    printf("Owner UID: \t\t%d\n", fileStat.st_uid);
    printf("Owner GID: \t\t%d\n", fileStat.st_gid);
    printf("Device ID: \t\t%d\n", fileStat.st_dev);
    printf("Last Accessed: \t\t%d\n", fileStat.st_atime);
    printf("Last Modified: \t\t%d\n", fileStat.st_mtime);
    printf("Last Status Change: \t%d\n", fileStat.st_ctime);
}
