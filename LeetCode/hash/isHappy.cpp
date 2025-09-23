//
// Created by 34021 on 2025/9/21.
//
#include<iostream>
#include <unordered_set>
#include<cmath>
using namespace std;
bool isHappy(int num) {
    unordered_set<int> set;
    while (true) {
        int newNum = 0;
        while (num > 0) {
            newNum += pow(num % 10,2);
            num = num / 10;
        }
        num = newNum;
        if (num == 1) {
            return true;
        }
        if (set.find(newNum) != set.end()) {
            return false;
        }
        set.insert(newNum);
    }

}
int main() {
    int num;
    cin >> num;
    cout << (bool)isHappy(num);
    return 0;
}