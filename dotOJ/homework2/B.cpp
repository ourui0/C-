//
// Created by 34021 on 2025/9/19.
//
#include<iostream>
#include <vector>
#include<climits>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        long long sum = 0;
        long long Min = 0;//不能设为INT_MAX,要确保前缀和小于0
        long long Max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            sum += x;
            Max = max(Max, sum - Min);
            Min  = min(Min, sum);
        }
        cout<<Max<<endl;
    }
    return 0;
}