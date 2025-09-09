//
// Created by 34021 on 2025/9/9.
//
#include <iostream>
using namespace std;
int main() {
    int N;
    cin>>N;
    int str[26] = {0};
    for(int i=0;i<N;i++) {
        string op;
        cin>>op;
        if(op=="add") {
            string word;
            cin>>word;
            int len=word.length();
            for(int j=0;j<len;j++) {
                str[word[j]-'a']++;
            }
        }
        else if(op=="query") {
            int max = 0;
            for(int j : str) {
                if(j>max) {
                    max = j;
                }
            }
            if (max!=0) {
                for(char j=0;j<26;j++) {
                    if(str[j]==max) {
                        cout<<char(j + 'a');
                    }
                }
                cout<<endl;
            }
            else {
                cout<<"null"<<endl;
            }
        }
    }
}