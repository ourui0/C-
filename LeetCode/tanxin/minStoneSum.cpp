//
// Created by 34021 on 2026/1/9.
//
#include<bits/stdc++.h>
using namespace std;
int minStoneSum(vector<int>& piles, int k) {
    int max = 0;
    priority_queue<int> pile;
    for(int num : piles){
        max += num;
        pile.push(num);
    }
    int cnt = 0;
    while (cnt < k) {
        int cur = pile.top();
        max -= cur/2;
        pile.pop();
        pile.push((cur+1)/2);
        cnt++;
    }
    return max;
}
int main() {
    vector<int> piles = {10};
    cout << minStoneSum(piles,10);
    return 0;
}