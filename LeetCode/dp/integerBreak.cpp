//
// Created by 34021 on 2025/9/16.
//
#include<iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> fibs(n + 1, 0);
    fibs[1] = 1;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j < i; j++) {
            if (max(fibs[i - j] * j,(i-j) * j)> temp) {
                temp = max(fibs[i - j] * j,(i-j) * j );
            }
        }
        fibs[i] = temp;
    }
    return fibs[n];
}
int main() {
    int n;
    cin>>n;
    cout<<integerBreak(n)<<endl;
    return 0;
}