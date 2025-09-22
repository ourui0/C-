#include <iostream>
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

int main() {
    benchmark();
}