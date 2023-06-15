#include<stdio.h>

typedef struct node{
    int no, at, bt, ct, wt, tat;
}node;


void main(){
    int i, j, n=6, time;
    node p[n], temp;
    int arr[] = {0, 1, 1, 1, 2, 3};
    int burst[] = {9, 3, 2, 4, 3, 2};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].bt = burst[i];
    }    

    for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) if(p[j].at>p[j+1].at){
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
    }

    printf("\n\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");

    time = p[0].at;
    for(i=0;i<n;){
        if(p[i].at<=time){
            time += p[i].bt;
            p[i].ct = time;
            p[i].tat = time - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
            i++;
        }
        else time++;
    }

}