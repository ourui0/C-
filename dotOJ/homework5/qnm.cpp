//
// Created by 34021 on 2025/10/17.
//
#include<bits/stdc++.h>
using namespace std;

bool isList(int n) {
    int count = 0;
    int u,v;
    for (int i = 1;i < n;i += 2) {
        int num;
        cout <<"? "<< i <<" "<< i + 1<<endl;
        cin >> num;
        if (num == 1) {
            u = i;
            v = i + 1;
            count++;
        }
    }
    if (count > 1) {
        return true;
    }
    else if (count == 1) {
        if (u == 1) {
            cout << "? " << u << " " << u + 2 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                cout << "? " << u << " " << u + 3 << endl;
                int num;
                cin >> num;
                if (num == 1)return false;
            }
        }
        else {
            cout << "? " << u << " " << u - 1 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                if (u - 2 >= 1) {
                    cout << "? " << u << " " << u - 2 << endl;
                    int num;
                    cin >> num;
                    if (num == 1)return false;
                }
                else if (u + 2 <= n) {
                    cout << "? " << u << " " << u + 2 << endl;
                    int num;
                    cin >> num;
                    if (num == 1)return false;
                }
            }
        }
        if (v == n) {
            cout << "? " << v << " " << v - 2 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                cout << "? " << v << " " << v - 3 << endl;
                int num;
                cin >> num;
                if (num == 1)return false;
            }
        }
        else{
            cout << "? " << v << " " << v + 1 << endl;
            int res;
            cin >> res;
            if (res == 1) {
                if (v - 2 >= 1) {
                    cout << "? " << v << " " << v - 2 << endl;
                    int num;
                    cin >> num;
                    if (num == 1)return false;
                }
                else if (v + 2 <= n) {
                    cout << "? " << v << " " << v + 2 << endl;
                    int num;
                    cin >> num;
                    if (num == 1)return false;
                }
            }
        }
        return true;
    }
    else {
        if (n % 2 !=0) {
            cout << "? " << n << " " << n - 1 << endl;
            int num;
            cin >> num;
            if (num == 1) {
                cout << "? " << n << " " << n - 2 << endl;
                int res;
                cin >> res;
                if (res == 1) {
                    cout << "? " << n << " " << n - 3 << endl;
                }
            }
        }
        return true;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (isList(n)) {
            cout << "! 1" << endl;
        }else {
            cout << "! 2" << endl;
        }
    }
}