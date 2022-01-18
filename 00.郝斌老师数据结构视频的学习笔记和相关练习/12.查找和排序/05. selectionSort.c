#include <stdio.h>

void selectionSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) { // 走访未排序的元素
            if (arr[j] < arr[min]) {        // 找到目前最小值
                min = j;                    // 记录目前最小值
            }
        }

        // 交换两个数
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 1070 };
    int len = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}