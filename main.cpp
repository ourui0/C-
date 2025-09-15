#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // 初始化结果数组，全部为-1
    stack<int> st; // 单调栈，存储的是元素的索引

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

    return 0;
}