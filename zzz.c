#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    FILE *fp;
    fp = fopen("C:\\Users\\user\\Desktop\\C++WorkSpace\\1.txt", "r");
    if(fp == NULL){
        printf("can't open\n");
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("size : %d\n", size);
    fclose(fp);
}