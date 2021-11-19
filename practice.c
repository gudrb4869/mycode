#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
struct node{
    int data;
    struct node *next;
} *arr;

int main(){
    int i;
    arr = (struct node *)malloc(sizeof(struct node) * 10);
    for(i=0; i<10; i++){
        arr[i].data = 0;
        arr[i].next = NULL;
    }
    if(arr[4]->next == NULL){
        printf("sibal\n");
    }
    printf("%d\n", arr[8].data);
}