#include <cstdio>

int main(){
    int sum = 0, b = 1;
    int i; char c;
    while(true){
        scanf("%d%c", &i, &c);
        sum += i * b;
        if(c == '-') b = -1;
        else if(c != '+') break;
    }
    printf("%d\n", sum);
    return 0;
}