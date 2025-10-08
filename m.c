//
// Created by 34021 on 2025/10/8.
//
#include <stdio.h>

int main() {
    // (1) short类型转换
    short s_val = -12345;
    printf("int: %d, 0x%08x\n", (int)s_val, (int)s_val);
    printf("unsigned short: %u, 0x%04x\n", (unsigned short)s_val, (unsigned short)s_val);
    printf("unsigned int: %u, 0x%08x\n", (unsigned int)s_val, (unsigned int)s_val);
    printf("float: %f\n", (float)s_val);

    // (2) int类型转换
    int i_val = 2147483647;
    printf("short: %d, 0x%04x\n", (short)i_val, (unsigned short)(short)i_val);
    printf("unsigned short: %u, 0x%04x\n", (unsigned short)i_val, (unsigned short)i_val);
    printf("unsigned int: %u, 0x%08x\n", (unsigned int)i_val, (unsigned int)i_val);
    printf("float: %f\n", (float)i_val);

    // (3) float转double
    float f_val = 123456.789e5;
    printf("double: %lf\n", (double)f_val);

    // (4) double转float
    double d_val = 123456.789e5;
    printf("\n(4) double转float:\n");
    printf("float: %f\n", (float)d_val);

    // (5) 移位操作
    short shift_val = -12345;
    printf("short左移2位: %d, 0x%04x\n", shift_val << 2, (unsigned short)(shift_val << 2));
    printf("short右移2位: %d, 0x%04x\n", shift_val >> 2, (unsigned short)(shift_val >> 2));
    printf("unsigned short左移2位: %u, 0x%04x\n", (unsigned short)shift_val << 2, (unsigned short)shift_val << 2);
    printf("unsigned short右移2位: %u, 0x%04x\n", (unsigned short)shift_val >> 2, (unsigned short)shift_val >> 2);

    return 0;
}