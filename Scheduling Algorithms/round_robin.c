#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int no, at, bt, ct, wt, tat, rt, status;
}node;

int q[20], n=5, front=-1, rear=-1;

void enq(int i){
    if(rear==10) exit(1);
    if(front==-1) front=0;
    q[++rear] = i;
}

int deq(){
    if(front==-1) exit(1);
    int temp = q[front];
    if(front == rear) front = rear = -1;
    else front++;
    return temp;
}

int inq(int x){
    for(int i=front;i<=rear; i++) if(q[i]==x) return 1;
    return 0;
}

void main(){
    int i, j, remaining=5, tq=3, time;
    node p[n], temp;
    int arr[] = {0, 1, 2, 3, 4};
    int burst[] = {5, 3, 1, 2, 3};
    for(i=0;i<n;i++){
        p[i].no = i+1;
        p[i].at = arr[i];
        p[i].rt = p[i].bt = burst[i];
        p[i].status = 0;
        
    }    

    for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++) if(p[j].at>p[j+1].at){
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
    }
    enq(0);
    printf("\n\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
    for(time=p[0].at;remaining>0;){
        i = deq();
        // printf("%d ", i);
        if(p[i].rt<=tq){
            time += p[i].rt;
            // printf("-> P%d",p[i].no);
            p[i].ct = time;
            p[i].rt = 0;
            p[i].status = 1;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            remaining--;
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
            for(j=0;j<n;j++) if(p[j].at<=time && inq(j)!=1 && p[j].status==0) enq(j);
        }
        else{
            time += tq;
            p[i].rt -= tq;
            for(j=0;j<n;j++) if(p[j].at<=time && i!=j &&inq(j)!=1 && p[j].status==0) enq(j);
            enq(i);
        }
    }
}
