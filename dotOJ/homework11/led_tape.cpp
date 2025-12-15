//
// Created by 34021 on 2025/12/14.
//
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> leds(n);
    for (int i = 0;i < n;i++) {
        cin >> leds[i];
    }
    int cnt = 0;
    stack<int> st;
    st.push(0);
    for (int i = 1;i < n;i++) {
        while(!st.empty()&&leds[i] < leds[st.top()]) {
            cnt++;
            st.pop();
        }
        if (!st.empty()&&leds[i] == leds[st.top()]) {
            st.pop();
        }
        st.push(i);
    }
    if (!st.empty()) {
        cnt += st.size();
    }
    cout << cnt <<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}