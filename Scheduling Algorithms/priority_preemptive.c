#include<stdio.h>

typedef struct node{
    int no, at, bt, ct, wt, tat, rt, pri;
}node;


void main(){
    int i, j, n=5, time, maxp, maxi, remain=n;
    node p[n], temp;
    int arr[] = {0, 1, 2, 3, 5};
    int burst[] = {3, 4, 6, 4, 2};
    int priority[] = {3, 2, 4, 6, 10};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].rt = p[i].bt = burst[i];
        p[i].pri = priority[i];
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

    for(time=0;remain>0;time++){
        maxi = -1;
        maxp = 9999;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].pri<maxp && p[i].rt>0){
                maxi = i;
                maxp = p[i].pri;
            }
        }

        if(maxi == -1) continue;
        p[maxi].rt--;
        if(p[maxi].rt==0){
            remain--;
            p[maxi].ct = time+1;
            p[maxi].tat = p[maxi].ct - p[maxi].at;
            p[maxi].wt = p[maxi].tat - p[maxi].bt;
            // printf("P%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p[maxi].no,p[maxi].pri,p[maxi].at,p[maxi].bt,p[maxi].ct,p[maxi].tat,p[maxi].wt);
        }
    }
    for(maxi=0; maxi<n; maxi++) 
    printf("P%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p[maxi].no,p[maxi].pri,p[maxi].at,p[maxi].bt,p[maxi].ct,p[maxi].tat,p[maxi].wt);
}