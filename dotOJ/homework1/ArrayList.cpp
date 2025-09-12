#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        list<long long> nums;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            nums.push_back(x);
        }
        while (q--) {
            int op;
            cin >> op;
            list<long long> temp;
            auto it = nums.begin();
            for (int i = 1; i <= op; i++) {
                if (i % 2 == 1) {
                    it = nums.erase(it);
                } else {
                    temp.push_front(*it);
                    it = nums.erase(it);
                }
            }
            nums.splice(nums.begin(), temp);
        }
        for(long long i : nums) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}