#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main(){
    time_t timer=time(NULL);
    struct tm *t=localtime(&timer);
    cout << t->tm_year +1900 <<'\n';
    cout << setw(2) << setfill('0') << t->tm_mon+1 << '\n';
    cout << setw(2) << setfill('0') << t->tm_mday << '\n';
    return 0;
}