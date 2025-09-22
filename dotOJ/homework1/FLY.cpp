//
// Created by 34021 on 2025/9/12.
//
#include<iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    queue <string> q;

    for(int i=0;i<n;i++) {
        int op = 0;
        cin>>op;
        if(op==1) {
            if (q.size() < m) {
                string s;
                cin>>s;
                q.push(s);
            }
            else {
                string s;
                cin>>s;
                cout<<"full"<<"\n";
            }
        }
        else if(op==2) {
            if (q.size() > 0) {
                string s  = q.front();
                cout<<s<<"\n";
                q.pop();
            }
            else {
                cout<<"empty"<<"\n";
            }
        }
        else if(op==3) {
            cout<<q.size()<<"\n";
        }
    }
    return 0;
}