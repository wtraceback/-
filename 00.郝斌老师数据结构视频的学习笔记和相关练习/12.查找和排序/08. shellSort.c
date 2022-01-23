#include <stdio.h>

void shellSort(int *arr, int len) {
    // 最开始的步长，求中位数：len / 2 或 len >> 1
    for (int gap = len / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < len; i++) {
            int key = arr[i];
            // 逻辑上，以 key 前面的第 gap 个元素为有序序列的起始点
            int j = i - gap;
            while (j >= 0 && arr[j] > key) {
                // 对于前面已排序的元素，以 gap 为步长间隔向后替换或向前搜索
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = key;
        }
    }
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 10 };
    int len = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}
