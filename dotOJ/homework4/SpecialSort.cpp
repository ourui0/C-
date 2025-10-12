//
// Created by 34021 on 2025/10/10.
//
#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
bool compare(ull a, ull b) {
    cout << "?\n";
    cout << a << " " << b << '\n';
    cout.flush();

    char op;
    cin >> op;
    return op == '<';
}
void merge(vector<ull>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ull> L(n1), R(n2);


    for (int i = 0; i < n1; i++) {
        L[i] = nums[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (!compare(L[i] ,R[j])) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<ull>& nums, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums, left, mid, right);
}
int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ull> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        mergeSort(nums, 0, n - 1);

        cout << "!\n";
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            if (i < n - 1) cout << " ";
        }
        cout << '\n';
        cout.flush();
    }
    return 0;
}