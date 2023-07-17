#include<stdio.h>

void main(){
    int mem_size, page_size, np, rem_pages, offset, phy_add, i, j, no_processes, page_no;
    int process[10], page_table[10][10];
    printf("Enter memory size: ");
    scanf("%d", &mem_size);
    printf("Enter page size: ");
    scanf("%d", &page_size);
    np = mem_size/page_size;
    rem_pages = np;
    printf("No. of pages available are %d\n", np);
    printf("Enter no. of processes: ");
    scanf("%d", &no_processes);
    for(i=0; i<no_processes; i++){
        printf("Enter no. of pages required for process[%d]: ", i);
        scanf("%d", &process[i]);
        if(process[i] > rem_pages){
            printf("Memory is Full\n");
            continue;
        }
        rem_pages -= process[i];
        printf("Enter pagetable for process[%d]: ", i);
        for(j=0; j<process[i]; j++){
            scanf("%d", &page_table[i][j]);
        }
    }
    for(i=0; i<no_processes; i++){
        printf("Enter desired logical address page no., offset of %d: ", i);
        scanf("%d %d", &page_no, &offset);
        if(page_no>=process[i] || offset>=page_size){
            printf("Invalid Address\n");
        }
        else{
            phy_add = page_table[i][page_no]*page_size+offset;
            printf("The corresponding physical address is: %d\n", phy_add);
        }
    }
}