#include<stdio.h>
#include<stdlib.h>

int mutex=1, full=0, empty=3, x=0;

int wait(int s){
    return s-1;
}

int signal(int s){
    return s+1;
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("producer produces the item %d\n", ++x);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumed item %d\n", x--);
    mutex = signal(mutex);
}

void main(){
    int choice;
    printf("1. producer\n2. consumer\n3. exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else
                    printf("Buffer is full\n");
                break;
            case 2:
                if(mutex==1 && full!=0)
                    consumer();
                else
                    printf("Buffer is empty\n");
                break;
            case 3:
                exit(0);
                break;
        }
    }
}
