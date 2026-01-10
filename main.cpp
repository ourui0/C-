#include <iostream>
using namespace std;
int* get_inputs() {
    int *numbers = new int[10];
    int i;
    for(i = 0; i < 10; i ++) {
        cin >> numbers[i];
    }
    return numbers;
}
int find_max(int* inputs, int size) {
    int i;
    int max = -1;
    for (i = 0; i < size; i ++ ) {
        if (max < inputs[i]) {
            max = inputs[i];
        }
    }
    return max;
}
int main() {
    cout << "inputs" << endl;
    int* inputs = get_inputs();
    cout << "find the max" << endl;
    int max = find_max(inputs, 10);
    cout << "max: " << max << endl;
    delete[] inputs;
}