#include<stdio.h>

typedef struct node{
    int no, at, bt, ct, wt, tat, status, pri;
}node;


void main(){
    int i, j, n=7, time=0, maxp, maxi, remain=n;
    node p[n], temp;
    int arr[] = {0, 1, 3, 4, 5, 6, 10};
    int burst[] = {8, 2, 4, 1, 6, 5, 1};
    int priority[] = {3, 4, 4, 5, 2, 6, 1};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].bt = burst[i];
        p[i].pri = priority[i];
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

    printf("\n\nProcess\t\tPriority\tAT\tBT\tCT\tTAT\tWT\n");

    while(remain>0){
        maxi = -1;
        maxp = 9999;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].pri<maxp && p[i].status==0){
                maxi = i;
                maxp = p[i].pri;
            }
        }

        if(maxi == -1){
            time++;
            continue;
        }
        time += p[maxi].bt;
        remain--;
        p[maxi].ct = time;
        p[maxi].status = 1;
        p[maxi].tat = time - p[maxi].at;
        p[maxi].wt = p[maxi].tat - p[maxi].bt;
        // printf("P%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p[maxi].no,p[maxi].pri,p[maxi].at,p[maxi].bt,p[maxi].ct,p[maxi].tat,p[maxi].wt);
    }
    for(maxi=0; maxi<n; maxi++) 
    printf("P%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p[maxi].no,p[maxi].pri,p[maxi].at,p[maxi].bt,p[maxi].ct,p[maxi].tat,p[maxi].wt);
}