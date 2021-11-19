#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    for(int i=0; i<20; i++){
        int num = (int)(rand()<<15|rand())%100000;
        printf("%d\n",num);
    }
    return 0;
}