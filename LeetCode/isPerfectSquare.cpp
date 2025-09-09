//
// Created by 34021 on 2025/9/9.
//
#include<iostream>
using namespace std;
bool isPerfectSquare(int x) {
    if(x == 0) return true;
    int low = 1,high = x;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (x / mid == mid&& x%mid==0) {
            return true;
        }
        else if(x / mid < mid) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return false;
}
int main() {
    int x;
    cin>>x;
    cout<<isPerfectSquare(x)<<endl;
}