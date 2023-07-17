#include<stdio.h>

void main(){
    int mem_size, no_segments, no_pages=0, offset, phy_add, i, j, no_processes, seg_no, remp_pages;
    int seg_size[10], seg_base[10], process[10];
    printf("Enter memory size: ");
    scanf("%d", &mem_size);
    printf("Enter no. of segments: ");
    scanf("%d", &no_segments);
    for(i=0; i<no_segments; i++){
        printf("Enter base address and size of segment[%d]: ", i);
        scanf("%d %d", &seg_base[i], &seg_size[i]);
        no_pages += seg_size[i];
    }
    printf("No. of available pages are %d\n", no_pages);
    remp_pages = no_pages;
    printf("Enter no. of processes: ");
    scanf("%d", &no_processes);
    for(i=0; i<no_processes; i++){
        printf("Enter no. of segments required for process[%d]: ", i);
        scanf("%d", &process[i]);
        if(process[i]>remp_pages){
            printf("Memory is Full\n");
            continue;
        }
        remp_pages -= process[i];
    }
    for(i=0; i<no_processes; i++){
        printf("Enter desired logical address segment no., offset of %d: ", i);
        scanf("%d %d", &seg_no, &offset);
        if(seg_no>=process[i] || offset>=seg_size[seg_no]){
            printf("Invalid Address\n");
        }
        else{
            phy_add = seg_base[seg_no]+offset;
            printf("The corresponding physical address is: %d\n", phy_add);
        }
    }
}
