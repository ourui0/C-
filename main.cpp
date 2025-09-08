#include <iostream>
using namespace std;


long long main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;//输入n

    long long x;
    for (long long i = 0; i < n; i++) {
        cin >> x;
        cout << x<< endl;
    }

    return 0;
}