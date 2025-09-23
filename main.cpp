#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <stack>
=======
#include <climits>
#include <cmath>
>>>>>>> e73e10c2b2fdc97dcb56736553dcf4316e0c3666
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // 初始化结果数组，全部为-1
    stack<int> st; // 单调栈，存储的是元素的索引

<<<<<<< HEAD
    // 遍历数组
    for (int i = 0; i < n; i++) {
        // 当栈不为空且当前元素大于栈顶元素对应的值时
        while (!st.empty() && nums[i] > nums[st.top()]) {
            // 栈顶元素的下一个更大元素就是当前元素
            result[st.top()] = nums[i];
            st.pop(); // 弹出栈顶元素
        }
        // 将当前元素的索引入栈
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> result = nextGreaterElement(nums);

    cout << "输入数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "下一个更大元素: ";
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

=======
int main() {
    int N;
    cin>>N;

    vector<int> M(N);
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin>>M[i];
    }
    for (int i = 0; i < N; i++) {
        cin>>L[i];
    }
    int length_M = M.size(),length_L = L.size();
    for (int i = 0; i < N - 1; i++) {
        //小明删除
        int min = INT_MAX,min_P = 0;
        for (int j = 0; j < length_M; j++) {
            for (int k = 0; k < length_L; k++) {
                if (abs(M[j] - L[k]) < min) {
                    min = abs(M[j] - L[k]);
                    min_P = j;
                }
            }
        }
        length_M--;
        M.erase(M.begin() + min_P);
        int max = INT_MIN,max_P = 0;
        for (int j = 0; j < length_L; j++) {
            for (int k = 0; k < length_M; k++) {
                if (abs(L[j] - M[k]) > max) {
                    max = abs(L[j] - M[k]);
                    max_P = j;
                }
            }
        }
        L.erase(L.begin() + max_P);
        length_L--;
    }
    cout<<abs(M[0] - L[0])<<endl;
>>>>>>> e73e10c2b2fdc97dcb56736553dcf4316e0c3666
    return 0;
}