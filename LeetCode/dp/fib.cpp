//
// Created by 34021 on 2025/9/16.
//
#include<iostream>
#include <vector>
using namespace std;
int fib(int n) {
    vector<int> fibs(n + 2,0);//多开一位防止出现0
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
    return fibs[n];
}
int main() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}