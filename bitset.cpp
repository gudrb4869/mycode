#include <iostream>
#include <bitset>

int main(){
    int a = 0b1100;
    std::cout << std::bitset<4>(~a);
}