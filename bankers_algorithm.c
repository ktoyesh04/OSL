#include<stdio.h>
#include<stdbool.h>
#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

bool isSafeState(int available[], int max[][MAX_PROCESSES], int allocated[][MAX_PROCESSES], int n, int m){
    int work[MAX_RESOURCES], i, j, k, need[MAX_PROCESSES][MAX_RESOURCES], count=0;
    bool finish[MAX_PROCESSES]={false}, found;
    for(i=0; i<m; i++) 
        work[i] = available[i];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            need[i][j] = max[i][j] - allocated[i][j];
    while(count<n){
        found = false;
        for(i=0; i<n; i++){
            if(!finish[i]){
                for(j=0; j<m; j++)
                    if(need[i][j]>work[j]) 
                        break;
                if(j==m){
                    for(k=0; k<m; k++)
                        work[k] += allocated[i][k];
                    found = finish[i] = true;
                    count++;
                }
            }
        }
        if(!found) break;
    }
    return count==n;
}

bool allocatedResources(int available[], int max[][MAX_RESOURCES], int allocated[][MAX_RESOURCES], int n, int m, int process, int request[]){
    int need[MAX_PROCESSES][MAX_RESOURCES], i;
    for(i=0; i<m; i++)
        need[process][i] = max[process][i] - allocated[process][i];
    for(i=0; i<m; i++)
        if(request[i]>need[process][i] || request[i]>available[i])
            return false;
    for(i=0; i<m; i++){
        available[i] -= request[i];
        allocated[process][i] += request[i];
        need[process][i] -= request[i];
    }
    if(isSafeState(available, max, allocated, n, m)) return true;
    for(i=0; i<m; i++){
        available[i] += request[i];
        allocated[process][i] -= request[i];
        need[process][i] += request[i];
    }
    return false;
}

void main(){
    int n=5, m=3;
    int available[MAX_RESOURCES] = {3, 3, 2};
    int max[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int process = 1;
    int request[MAX_RESOURCES] = {1, 0, 2};
    if(allocatedResources(available, max, allocation, n, m, process, request))
        printf("Allocated\n");
    else
        printf("Not Allocated\n");
}
