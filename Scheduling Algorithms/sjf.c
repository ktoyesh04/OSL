#include<stdio.h>

typedef struct node{
    int no, at, bt, ct, wt, tat, status;
}node;


void main(){
    int i, j, n=5, time=0, sjb, sji, remain=n;
    node p[n], temp;
    int arr[] = {1, 3, 6, 7, 9};
    int burst[] = {7, 3, 2, 10, 8};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].bt = burst[i];
        p[i].status = 0;
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

    while(remain>0){
        sji = -1;
        sjb = 9999;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].bt<sjb && p[i].status==0){
                sji = i;
                sjb = p[i].bt;
            }
        }

        if(sji == -1){
            time++;
            continue;
        }
        time += sjb;
        remain--;
        p[sji].ct = time;
        p[sji].status = 1;
        p[sji].tat = time - p[sji].at;
        p[sji].wt = p[sji].tat - p[sji].bt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[sji].no,p[sji].at,p[sji].bt,p[sji].ct,p[sji].tat,p[sji].wt);
    }

}