#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s={2,3,6,9};
set<int>::iterator it;

int main(){
    cout << *s.lower_bound(10) << '\n';
}