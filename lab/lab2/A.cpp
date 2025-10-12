//
// Created by 34021 on 2025/9/29.
//
#include "A.h"

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(ref_cnt != nullptr)*ref_cnt+=1;
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if(ref_cnt != nullptr){
        *ref_cnt-=1;
    }

    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(ref_cnt != nullptr){
        *ref_cnt+=1;
    }
}

SmartPointer::~SmartPointer()
{
    if(ref_cnt!=nullptr){
        *ref_cnt-=1;
        if(*ref_cnt == 0){
            delete pointer;
        }
    }
}
int main() {
    SmartPointer sp1(new Node(123));
    sp1.~SmartPointer();
    sp1.assign(SmartPointer());//测试空指针赋值
    sp1.assign(*(new SmartPointer(new Node(456))));//Node 456仍然被堆空间中的某个指针持有，所以不会被释放
}