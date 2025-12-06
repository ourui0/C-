# 排序
## 快速排序
基本实现
```c++
#include <iostream>
#include <vector>
using namespace std;

// 分区函数 - 选择最后一个元素作为基准
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为基准
    int i = low - 1;        // 较小元素的索引
    
    for (int j = low; j < high; j++) {
        // 如果当前元素小于等于基准
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序主函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 分区索引
        int pi = partition(arr, low, high);
        
        // 递归排序分区
        quickSort(arr, low, pi - 1);  // 左半部分
        quickSort(arr, pi + 1, high); // 右半部分
    }
}
```
更简单的实现
```c++
// 使用第一个元素作为基准的分区函数
int partitionFirst(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // 选择第一个元素作为基准
    int i = low + 1;
    int j = high;
    
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j > low && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
```

## 归并排序
```c++
class MergeSort {
private:
// 合并函数
static void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        
        while (j <= right) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        
        // 拷贝回原数组
        for (int idx = left; idx <= right; idx++) {
            arr[idx] = temp[idx];
        }
    }
    
    // 递归排序函数
    static void sortRecursive(vector<int>& arr, int left, int right, vector<int>& temp) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        sortRecursive(arr, left, mid, temp);
        sortRecursive(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }

public:
// 递归版本
static void sortRecursive(vector<int>& arr) {
if (arr.size() <= 1) return;
vector<int> temp(arr.size());
sortRecursive(arr, 0, arr.size() - 1, temp);
}

    // 迭代版本
    static void sortIterative(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;
        
        vector<int> temp(n);
        
        for (int size = 1; size < n; size *= 2) {
            for (int left = 0; left < n - 1; left += 2 * size) {
                int mid = min(left + size - 1, n - 1);
                int right = min(left + 2 * size - 1, n - 1);
                
                // 合并操作
                int i = left, j = mid + 1, k = left;
                
                while (i <= mid && j <= right) {
                    if (arr[i] <= arr[j]) {
                        temp[k] = arr[i];
                        i++;
                    } else {
                        temp[k] = arr[j];
                        j++;
                    }
                    k++;
                }
                
                while (i <= mid) {
                    temp[k] = arr[i];
                    i++;
                    k++;
                }
                
                while (j <= right) {
                    temp[k] = arr[j];
                    j++;
                    k++;
                }
                
                // 拷贝回原数组
                for (int idx = left; idx <= right; idx++) {
                    arr[idx] = temp[idx];
                }
            }
        }
    }
};
```

# 计数排序
```c++
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int max_val) {
    int n = arr.size();
    vector<int> count(max_val + 1, 0);
    
    // 1. 统计频率
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // 2. 计算前缀和
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    
    // 3. 构建排序数组
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // 将排序结果复制回原数组
    arr = sorted;
}
```

# 基数排序中计数排序步骤详解

你提到的这两个步骤是基数排序中**计数排序**部分的核心，用于对每一位数字进行稳定排序。让我详细解释这个过程：

## 完整基数排序流程

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 获取数字在特定位上的值
int getDigit(int num, int digit) {
    for (int i = 0; i < digit; i++) {
        num /= 10;
    }
    return num % 10;
}

// 基数排序
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    // 找到最大值，确定最大位数
    int max_num = *max_element(arr.begin(), arr.end());
    int max_digits = 0;
    while (max_num > 0) {
        max_digits++;
        max_num /= 10;
    }
    
    // 从最低位到最高位逐位排序
    for (int digit = 0; digit < max_digits; digit++) {
        // 步骤1：创建计数数组并统计频率
        vector<int> count(10, 0);  // 0-9的数字
        vector<int> output(arr.size());
        
        // 统计每个数字在当前位的出现次数
        for (int num : arr) {
            int d = getDigit(num, digit);
            count[d]++;
        }
        
        // 步骤2：计算前缀和 ← 你问的第一个步骤
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // 步骤3：构建输出数组 ← 你问的第二个步骤
        for (int i = arr.size() - 1; i >= 0; i--) {
            int d = getDigit(arr[i], digit);
            output[count[d] - 1] = arr[i];
            count[d]--;
        }
        
        // 将排序结果复制回原数组
        arr = output;
    }
}
```

## 步骤详解

### 步骤1：计算前缀和

```c++
for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
}
```

**目的**：将计数数组转换为位置索引数组

**转换前**：`count[i]` 表示数字 `i` 出现的次数
**转换后**：`count[i]` 表示小于等于 `i` 的数字的总个数

**示例**：
```
原始计数: count = [2, 1, 3, 0, 2, 1, 0, 1, 0, 1]
          对应数字:  0  1  2  3  4  5  6  7  8  9

前缀和后: count = [2, 3, 6, 6, 8, 9, 9, 10, 10, 11]
含义:
- count[0]=2: 小于等于0的数字有2个
- count[1]=3: 小于等于1的数字有3个  
- count[2]=6: 小于等于2的数字有6个
- ...
```

### 步骤2：构建输出数组

```c++
for (int i = arr.size() - 1; i >= 0; i--) {
    int d = getDigit(arr[i], digit);
    output[count[d] - 1] = arr[i];
    count[d]--;
}
```

**为什么从后往前遍历？** 为了保证排序的**稳定性**

**处理过程**：
1. 从原数组最后一个元素开始处理
2. 获取当前元素的当前位数字 `d`
3. 在输出数组的 `count[d] - 1` 位置放置当前元素
4. 将 `count[d]` 减1，为下一个相同数字预留位置

## 完整示例演示

假设数组：`[170, 45, 75, 90, 2, 802, 24, 66]`

### 第一次迭代（个位排序）

**原始数组**：`[170, 45, 75, 90, 2, 802, 24, 66]`

**步骤1：统计个位数字频率**
```
数字: 0  1  2  3  4  5  6  7  8  9
计数: 2  0  2  0  0  2  1  0  1  0
```

**步骤2：计算前缀和**
```
数字: 0  1  2  3  4  5  6  7  8  9
前缀: 2  2  4  4  4  6  7  7  8  8
```

**步骤3：构建输出数组（从后往前）**
```
处理 66(个位6) → output[7-1]=output[6] = 66, count[6]=6
处理 24(个位4) → output[4-1]=output[3] = 24, count[4]=3  
处理 802(个位2) → output[4-1]=output[3] = 802, count[2]=3
处理 2(个位2) → output[3-1]=output[2] = 2, count[2]=2
处理 90(个位0) → output[2-1]=output[1] = 90, count[0]=1
处理 75(个位5) → output[6-1]=output[5] = 75, count[5]=5
处理 45(个位5) → output[5-1]=output[4] = 45, count[5]=4
处理 170(个位0) → output[1-1]=output[0] = 170, count[0]=0

结果: [170, 90, 2, 802, 24, 45, 75, 66]
```

### 第二次迭代（十位排序）

**当前数组**：`[170, 90, 2, 802, 24, 45, 75, 66]`

**步骤1：统计十位数字频率**
```
数字: 0  1  2  3  4  5  6  7  8  9
计数: 2  0  1  0  1  1  1  1  0  1
```

**步骤2：计算前缀和**
```
数字: 0  1  2  3  4  5  6  7  8  9
前缀: 2  2  3  3  4  5  6  7  7  8
```

**步骤3：构建输出数组**
```
处理 66(十位6) → output[6-1]=output[5] = 66, count[6]=5
处理 75(十位7) → output[7-1]=output[6] = 75, count[7]=6
处理 45(十位4) → output[4-1]=output[3] = 45, count[4]=3
处理 24(十位2) → output[3-1]=output[2] = 24, count[2]=2
处理 802(十位0) → output[2-1]=output[1] = 802, count[0]=1
处理 2(十位0) → output[1-1]=output[0] = 2, count[0]=0
处理 90(十位9) → output[8-1]=output[7] = 90, count[9]=7
处理 170(十位7) → output[6-1]=output[5] = 170, count[7]=5

结果: [2, 802, 24, 45, 66, 170, 75, 90]
```

## 可视化理解

### 前缀和的作用
```
原始计数: [2, 1, 3]  (0出现2次, 1出现1次, 2出现3次)
前缀和:   [2, 3, 6]  (位置信息: 0在0-1, 1在2, 2在3-5)
```

### 稳定性保证
从后往前处理确保相同数字的元素保持原有相对顺序：
```
原数组: [A(2), B(2), C(1)]  // A和B的当前位都是2
处理:
1. C(1) → 位置1
2. B(2) → 位置3 (count[2]=3 → 位置2)
3. A(2) → 位置2 (count[2]=2 → 位置1)
结果: [C(1), A(2), B(2)]  // A和B的相对顺序不变
```

## 关键要点

1. **前缀和转换**：将频率统计转换为位置索引
2. **逆向遍历**：保证排序的稳定性
3. **位置计算**：`count[d] - 1` 是因为数组索引从0开始
4. **递减计数**：为下一个相同数字预留正确位置

这两个步骤是基数排序能够正确工作的核心，确保每次按位排序都是稳定的，从而最终得到完全有序的结果。