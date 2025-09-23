//
// Created by 34021 on 2025/9/17.
//
#include<iostream>
#include <stack>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> s;
    vector<int> result(temperatures.size(),0);
    s.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
        if (temperatures[i] > temperatures[s.top()]) {
            while (!s.empty()&&temperatures[s.top()] < temperatures[i]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
        }
        s.push(i);
    }
    return result;
}
int main() {
    vector temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(temperatures);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}