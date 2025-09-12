#include <iostream>
#include <vector>
using namespace std;

struct op {
    string s;
    string c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<op> q(k);

    for (int i = 0; i < n; i++) {
        cin >> q[i].s >> q[i].c;
    }





    int i = 0;
    while (i < k) {
        if (q[i].s.empty()) {
            return 0;
        }
        if (q[i].s == "echo") {
            cout << q[i].c;
        } else if (q[i].s == "cp") {
            for (int j = 0; j < stoi(q[i].c) && n < k; j++) {
                q[n++] = q[j];
            }
        }
        i++;
    }
    return 0;
}