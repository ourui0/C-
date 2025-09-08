//
// Created by 34021 on 2025/9/8.
//
#include <cmath>
#include<iostream>
using namespace std;
double f(double x, double a, double b) {
    return exp(x) - a * x - b;
}
double search(double a,double b) {
    double low = 0.0000001, high = 9.9999999;
    double tolerance = 1e-9;

    double flow = f(low, a, b);
    double fhigh = f(high, a, b);

    while (high - low > tolerance) {
        double mid = (low + high) / 2;
        double fmid = f(mid, a, b);

        if (fabs(fmid) < tolerance) {
            return mid;
        }

        if (flow * fmid < 0) {
            high = mid;
            fhigh = fmid;
        } else {
            low = mid;
            flow = fmid;
        }
    }

    return (low + high) / 2;
}
int main() {
    double a,b;
    cin>>a>>b;
    double ans = search(a,b);
    printf("%.6f",ans);
}