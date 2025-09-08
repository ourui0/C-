//
// Created by 34021 on 2025/9/8.
//
#include <iostream>

using namespace std;
// TODO: 补全此函数
long long count(long long m, long long n) {
    // TODO
    if (m ==0||n == 1)return 1;
    if (m-n>=0) {
        return count(m-n, n) + count(m, n-1);
    }
    else {
        return count(m, n-1);
    }
}

long long main() {
    long long M, N;
    cin >> M >> N;
    cout << count(M, N);
    return 0;
}