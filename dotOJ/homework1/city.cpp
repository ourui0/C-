//
// Created by 34021 on 2025/9/12.
//
#include<iostream>
#include <stack>
#include <vector>
using namespace std;
long long city(vector<long long> arr) {
    stack<pair<long long, int>> st;
    long long ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (!st.empty() && st.top().first < arr[i]) {
            ans += st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first == arr[i]) {
            ans += st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        if (!st.empty()) {
            ans++;
        }
        st.push({arr[i], cnt});
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<long long> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        long long ans = city(arr);
        cout << ans << "\n";
    }
}