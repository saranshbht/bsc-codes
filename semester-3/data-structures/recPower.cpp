#include<iostream>
using namespace std;

long long power(long b, long e){
    //cout << b << " " << e << endl;
    if(b == 0 || b == 1)
        return b;
    if(e == 0)
        return 1;
    if(e == 1)
        return b;
    long long x = power(b, e / 2);
    if(e & 1)
        return b * x * x;
    else
        return x * x;
}

int main(){
    long b, e;
    cout << "Enter base(b) and exponent(e)(e >= 0): ";
    cin >> b >> e;
    cout << "b ^ e = " << power(b, e) << endl;
    return 0;
}

