//
// Created by 34021 on 2025/9/12.
//
#include<iostream>
#include <stack>
#include <vector>
using namespace std;
long long city(vector<long long> arr) {
    int n = arr.size();
    long long ans = 0;
    stack<pair<int,int>> st;
    st.push({arr[0],1});
    for (int i = 1; i < n;i++){
        int cnt = 1;//记录相同楼层数
        while (!st.empty()&&st.top().first < arr[i]){
            ans += st.top().second;//与arr[i]组成一对新的
            st.pop();
        }
        if (!st.empty()&&st.top().first == arr[i]){
            ans += st.top().second;//二者本身就可以组成新的
            cnt += st.top().second;
            st.pop();
        }
        if (!st.empty()){
            ans++;//栈顶的和即将推入的也可以组成一对
        }
        st.push({arr[i],cnt});
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