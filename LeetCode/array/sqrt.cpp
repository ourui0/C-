//
// Created by 34021 on 2025/9/8.
//
#include<iostream>
using namespace std;
int mySqrt(int x) {
    if(x == 0)return 0;
    int low = 1, high = x;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(x /mid == mid) {
            return mid;
        }
        else if(mid * mid > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}
int main() {
    int x;
    cin>>x;

    cout<<mySqrt(x)<<endl;
    return 0;
}
