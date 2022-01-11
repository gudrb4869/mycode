#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

struct inode{
    unsigned int x[128];
};

int main(void){
    struct inode bitmap;
    memset(&bitmap, 0, sizeof(struct inode));
    bitmap.x[0] = 15;
    printf("%d\n", BIT_CHECK(bitmap.x[0], 0));
    return 0;
}