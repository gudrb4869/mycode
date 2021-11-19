    #include <iostream>
    using namespace std;

    long long int func(int a, int b, int c){
        bool odd=(b&1)==1?true:false;
        if(b==0) return 1;
        if(odd) return a*func(a,b-1,c)%c;
        else{
            long long int tmp=func(a,b/2,c);
            return ((tmp%c)*(tmp%c))%c;
        }
    }

    int main(){
        long long int a,b,c;
        cin >> a >> b >> c;
        cout << func(a,b,c) << '\n';
        return 0;
    }