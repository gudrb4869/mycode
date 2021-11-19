#include <iostream>
#include <ctime>
using namespace std;

int main(){
    time_t curr_time = time(NULL);
    struct tm *pLocal = localtime(&curr_time);
    cout << pLocal->tm_year + 1900 << '-';
    if(pLocal->tm_mon+1<10) cout << '0';
    cout << pLocal->tm_mon + 1 << '-';
    cout << pLocal->tm_mday << '\n';
}