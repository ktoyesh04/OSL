#include<stdio.h>

typedef struct node{
    int no, at, bt, ct, wt, tat, rt;
}node;

void main(){
    int i, j, n=6, time, sjb, remain=n, sji;
    node p[n], temp;
    int arr[] = {0, 1, 2, 3, 4, 5};
    int burst[] = {8, 4, 2, 1, 3, 2};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].rt = p[i].bt = burst[i];
    }    

     for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }

    printf("\n\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");

    for(time=0;remain>0;time++){
        sji = -1;
        sjb = 9999;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt<sjb && p[i].rt>0){
                sji = i;
                sjb = p[i].rt;
            }
        }

        if(sji == -1) continue;
        p[sji].rt--;
        if(p[sji].rt == 0){
            p[sji].ct = time+1;
            remain--;
            p[sji].tat = p[sji].ct - p[sji].at;
            p[sji].wt = p[sji].tat - p[sji].bt;
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[sji].no,p[sji].at,p[sji].bt,p[sji].ct,p[sji].tat,p[sji].wt);
        }
    }
}