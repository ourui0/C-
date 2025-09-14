//
// Created by 34021 on 2025/9/13.
//
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int i = 1;//填充数
    int index = 0;//用于记录到哪条边了
    int count = 0;//用于记录第几次循环
    while (i <= n * n) {
        if (index % 4 == 0) {
            for (int j = count; j < n - 1 -count; j++,i++) {
                matrix[count][j] = i;
            }
            index++;
        }//水平向右方向的填充
        if (index % 4 == 1) {
            for (int j = count; j < n - 1 -count; j++,i++) {
                matrix[j][n - 1 - count] = i;
            }
            index++;
        }//竖直向下的填充
        if (index % 4 == 2) {
            for (int j = count; j < n - 1 -count; j++,i++) {
                matrix[n - 1 - count][n - 1-j] = i;
            }
            index++;
        }//水平向左方向的填充
        if (index % 4 == 3) {
            index = 0;//更新回到第一条边
            for (int j = count; j < n - 1 -count; j++,i++) {
                matrix[n - 1 - j][count] = i;
            }
            count++;//下一个循环
        }//竖直向上的填充
        if (n % 2 == 1 && i == n * n) {
            matrix[n/2][n/2] = n*n;
            i++;
        }
    }
    return matrix;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    matrix = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}