#include <stdio.h>

void insertionSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        // 以 key 前面的第 1 个元素为有序序列的起始点
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            // 对于前面已排序的元素，以 1 为步长间隔向后替换或向前搜索
            arr[j + 1] = arr[j];
            j = j - 1;
            // j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 1070 };
    int len = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}