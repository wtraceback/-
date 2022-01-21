#include <stdio.h>

void quickSortRecursive(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = arr[start];
    int left = start;
    int right = end;
    while (left < right) {
        // 从右到左开始，搜索小于 pivot 的值
        while (pivot <= arr[right] && left < right) {
            right--;
        }
        arr[left] = arr[right];

        // 接着从左到右，搜索大于 pivot 的值
        while (arr[left] <= pivot && left < right) {
            left++;
        }
        arr[right] = arr[left];
    }

    // 当 while 循环结束之后，left 和 right 一定是相等的，以下的 left 和 right 可以互换
    arr[left] = pivot;
    quickSortRecursive(arr, start, left - 1);
    quickSortRecursive(arr, right + 1, end);
}

void quickSort(int *arr, int len) {
    quickSortRecursive(arr, 0, len - 1);
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 10 };
    int len = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}
