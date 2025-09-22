//
// Created by 34021 on 2025/9/14.
//
#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n + 1);
    v[0] = 0;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        v[i] = x + v[i-1];
    }
    int a,b;
    while (cin>>a>>b) {
        cout<<v[b + 1] - v[a]<<endl;
    }
    return 0;
}