#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;


int main() {
    int N;
    cin>>N;

    vector<int> M(N);
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin>>M[i];
    }
    for (int i = 0; i < N; i++) {
        cin>>L[i];
    }
    int length_M = M.size(),length_L = L.size();
    for (int i = 0; i < N - 1; i++) {
        //小明删除
        int min = INT_MAX,min_P = 0;
        for (int j = 0; j < length_M; j++) {
            for (int k = 0; k < length_L; k++) {
                if (abs(M[j] - L[k]) < min) {
                    min = abs(M[j] - L[k]);
                    min_P = j;
                }
            }
        }
        length_M--;
        M.erase(M.begin() + min_P);
        int max = INT_MIN,max_P = 0;
        for (int j = 0; j < length_L; j++) {
            for (int k = 0; k < length_M; k++) {
                if (abs(L[j] - M[k]) > max) {
                    max = abs(L[j] - M[k]);
                    max_P = j;
                }
            }
        }
        L.erase(L.begin() + max_P);
        length_L--;
    }
    cout<<abs(M[0] - L[0])<<endl;
    return 0;
}