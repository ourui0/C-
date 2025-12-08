#include <iostream>
<<<<<<< HEAD
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
=======
#include <string>
#include <chrono>
#include <random>

// 你的方法（前向插入）
std::string replaceForward(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            s[i] = 'r';
            s.insert(i, "numbe");
            i += 5;
        }
    }
    return s;
}

// 优化方法（后向插入）
std::string replaceBackward(const std::string& input) {
    int digitCount = 0;
    for (char c : input) {
        if (c >= '0' && c <= '9') digitCount++;
    }

    std::string result;
    result.resize(input.size() + digitCount * 5);

    int i = input.size() - 1;
    int j = result.size() - 1;

    while (i >= 0) {
        if (input[i] >= '0' && input[i] <= '9') {
            result[j--] = 'r';
            result[j--] = 'e';
            result[j--] = 'b';
            result[j--] = 'm';
            result[j--] = 'u';
            result[j--] = 'n';
        } else {
            result[j--] = input[i];
        }
        i--;
    }

    return result;
}

// 生成测试数据
std::string generateTestString(int length, double digitRatio) {
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < length; i++) {
        if (dis(gen) < digitRatio) {
            result += '0' + (i % 10);
        } else {
            result += 'a' + (i % 26);
        }
    }
    return result;
}

void benchmark() {
    // 测试不同规模的数据
    std::vector<int> sizes = {1000, 5000, 10000, 50000};
    std::vector<double> ratios = {0.1, 0.5, 0.9}; // 数字比例

    for (int size : sizes) {
        for (double ratio : ratios) {
            auto testStr = generateTestString(size, ratio);

            auto start = std::chrono::high_resolution_clock::now();
            auto result1 = replaceForward(testStr);
            auto end = std::chrono::high_resolution_clock::now();
            auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            start = std::chrono::high_resolution_clock::now();
            auto result2 = replaceBackward(testStr);
            end = std::chrono::high_resolution_clock::now();
            auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            std::cout << "Size: " << size << ", Digit ratio: " << ratio
                      << " | Forward: " << time1.count() << "μs"
                      << " | Backward: " << time2.count() << "μs"
                      << " | Ratio: " << (time1.count() * 1.0 / time2.count()) << "x"
                      << std::endl;
        }
    }
}
>>>>>>> 095ba499753f30d7f15bfae8725601e4f7ccc660

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
<<<<<<< HEAD
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
=======
    benchmark();
>>>>>>> 095ba499753f30d7f15bfae8725601e4f7ccc660
}