#include <iostream>
#include <string>
using namespace std;

int arr[51];
int score;
string result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1; i<=50; i++){
        cin >> arr[i];
    }
    cin >> score;
    int i = 1;
    while(arr[i] != score) i++;
    if(i>=1 && i<=5) result = "A+";
    else if(i>=6 && i<=15) result = "A0";
    else if(i>=16 && i<=30) result = "B+";
    else if(i>=31 && i<=35) result = "B0";
    else if(i>=36 && i<=45) result = "C+";
    else if(i>=46 && i<=48) result = "C0";
    else result = "F";
    cout << result;  
}