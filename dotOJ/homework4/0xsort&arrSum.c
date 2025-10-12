//
// Created by 34021 on 2025/10/10.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000000  // 根据题目要求调整大小

void Sort(char s[], int k, int n) {
    char *output = (char*)malloc(n * k * sizeof(char));
    
    for (int i = 0; i < k; i++) {
        int c[16] = {0};

        for (int j = 0; j < n; j++) {
            int pos = j * k + (k - 1 - i);
            char digit = s[pos];
            
            if (digit >= '0' && digit <= '9') {
                c[digit - '0']++;
            } else if (digit >= 'A' && digit <= 'F') {
                c[digit - 'A' + 10]++;
            }
        }

        for (int j = 1; j < 16; j++) {
            c[j] += c[j - 1];
        }

        for (int j = n - 1; j >= 0; j--) {
            int pos = j * k + (k - 1 - i);
            char digit = s[pos];
            int digit_value;
            
            if (digit >= '0' && digit <= '9') {
                digit_value = digit - '0';
            } else {
                digit_value = digit - 'A' + 10;
            }

            int new_index = c[digit_value] - 1;

            for (int m = 0; m < k; m++) {
                output[new_index * k + m] = s[j * k + m];
            }
            c[digit_value]--;
        }
        memcpy(s, output, n * k);
    }
    
    free(output);
}

void Count(char s[], int k, int l, int r) {
    int count = 0;
    for (int i = l - 1; i < r; i++) {
        for (int j = 0; j < k; j++) {
            if (s[i * k + j] == 'F') {
                count++;
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    char *s = (char*)malloc(n * k + 1);  // 动态分配内存
    for (int i = 0; i < n * k; i++) {
        scanf(" %c", &s[i]);
    }
    s[n * k] = '\0';  // 添加字符串结束符
    
    Sort(s, k, n);
    
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        Count(s, k, l, r);
    }
    
    free(s);
    return 0;
}