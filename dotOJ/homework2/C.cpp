//
// Created by 34021 on 2025/9/19.
//
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int Count = 1;//设为全局变量，表示添加到第几个L
void OpMap(vector<vector<int>> &map) {
    if (map.size() == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (map[i][j] == -1) {
                    map[i][j] = Count;
                }
            }
        }
        Count++;
        return;
    }
    int n = map[0].size() / 2;
    vector<vector<int>> map2(n, vector<int>(n, -1));
    vector<vector<int>> map3(n, vector<int>(n, -1));
    vector<vector<int>> map4(n, vector<int>(n, -1));
    vector<vector<int>> map5(n, vector<int>(n, -1));//分成四份
    int index1 = 0,index2 = 0,index3 = 0,index4 = 0;//确认是否已经存在零
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map2[i][j] = map[i][j];//第一个
            if (map[i][j] != -1) {
                index1 = 1;
            }
        }
    }
    if (index1 != 1) {
        map2[n - 1][n - 1] = Count;
    }//在边角加一个L
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            map3[i - n][j - n] = map[i][j];//第二个
            if (map[i][j] != -1) {
                index2 = 1;
            }
        }
    }
    if (index2 != 1) {
        map3[0][0] = Count;
    }
    for (int i = 0; i < n; i++) {
        for (int j = n; j < n * 2; j++) {
            map4[i][j - n] = map[i][j];
            if (map[i][j] != -1) {
                index3 = 1;
            }
        }
    }
    if (index3 != 1) {
        map4[n-1][0] = Count;
    }
    for (int i = n; i < n * 2; i++) {
        for (int j = 0; j < n; j++) {
            map5[i - n][j] = map[i][j];
            if (map[i][j] != -1) {
                index4 = 1;
            }
        }
    }
    if (index4 != 1) {
        map5[0][n - 1] = Count;
    }
    Count++;
    OpMap(map2);
    OpMap(map3);
    OpMap(map4);
    OpMap(map5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = map2[i][j];
        }
    }
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            map[i][j] = map3[i - n][j - n];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n; j < n * 2; j++) {
            map[i][j] = map4[i][j - n];
        }
    }
    for (int i = n; i < n * 2; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = map5[i - n][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        int k,x,y;
        cin>>k>>x>>y;
        Count = 1;
        vector<vector<int>> map(1 << k,vector<int>(1 << k,-1));//地图
        map[x - 1][y - 1] = 0;
        OpMap(map);
        for (int i = 0;i< 1<<k;i++) {
            for (int j = 0;j< 1<<k;j++) {
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}