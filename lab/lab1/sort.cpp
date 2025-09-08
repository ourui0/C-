//
// Created by 34021 on 2025/9/8.
//

// 数据结构格式，详见StudentSorter.h文件
#include<iostream>
#include<cstring>
using namespace std;
struct Student {
	long long no;
	char name[101];
};

// TODO: 补充具体的排序策略
// 按学号升序排序
bool sortByNoAsc(const Student& s1, const Student& s2) {
    // TODO
    return s1.no > s2.no;
}

// 按学号降序排序
bool sortByNoDesc(const Student& s1, const Student& s2) {
    // TODO
    return s1.no < s2.no;
}

// 按姓名字典序升序排序，如果姓名相同，再按学号升序排序
bool sortByNameAsc(const Student& s1, const Student& s2) {
    // TODO
    if (strcmp(s1.name, s2.name) == 0) {
        return s1.no > s2.no;
    }
    return strcmp(s1.name, s2.name)>0;
}

// 通用排序函数
void sortStudents(Student st[], long long num, bool (*comp)(const Student&, const Student&)) {
    // TODO
    for (long long i= 0;i<num;i++) {
        for (long long j = 0; j < num-1; j++) {
            if (comp(st[j], st[j+1])) {
                Student temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
    }
}

// main函数无需修改
long long main() {
    long long N;
    cin >> N; // 同scanf("%d", &N);
    Student students[100];

    for (long long i = 0; i < N; i++) {
        cin >> students[i].no >> students[i].name; // 类似于scanf("%d %s", &(students[i].no), students[i].name);
    }

    long long M;
    cin >> M;

    // 根据输入选择不同的比较函数
    bool (*comp)(const Student&, const Student&);
    switch (M) {
        case 1:
            comp = sortByNoAsc;
            break;
        case 2:
            comp = sortByNoDesc;
            break;
        case 3:
            comp = sortByNameAsc;
            break;
        default:
            comp = sortByNoAsc;
            break;
    }

    sortStudents(students, N, comp);

    for (long long i = 0; i < N; i++) {
        cout << students[i].no << " " << students[i].name << endl; // cout语句类似于C中的prlong longf输出
    }

    return 0;
}