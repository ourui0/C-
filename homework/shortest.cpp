#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int min_length = INT_MAX;
    int min_sum = INT_MAX;

    for (int i = 0; i < N; i++) {
        long long s = prefix[i] + target;
        auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), s);
        if (it != prefix.end()) {
            int idx = it - prefix.begin();
            int current_length = idx - i;
            int current_sum;
            if (current_length != 1) {
                current_sum = i + idx - 1;
            }
            else {
                current_sum = idx - 1;
            }
            if (current_length < min_length) {
                min_length = current_length;
                min_sum = current_sum;
            } else if (current_length == min_length) {
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
    }


    if (min_length == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << min_sum << endl;
    }

    return 0;
}