#include <stdio.h>

void mergeSortRecursive(int *arr, int *target, int start, int end) {
    if (start >= end) {
        return;
    }

    int len = end - start;
    int mid = (len >> 1) + start;
    // int mid = len / 2;
    // 这边 end1 不能 mid - 1，因为当 mid 为 0 时，mid - 1 会有问题
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    mergeSortRecursive(arr, target, start1, end1);
    mergeSortRecursive(arr, target, start2, end2);

    // 归并两个已经排好的序列
    int index = start;
    while (start1 <= end1 && start2 <= end2) {
        target[index++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }
    // 如果左边的有序序列有剩余，则将剩下的所有元素归并到数组中
    while (start1 <= end1) {
        target[index++] = arr[start1++];
    }
    // 如果右边的有序序列有剩余，则将剩下的所有元素归并到数组中
    while (start2 <= end2) {
        target[index++] = arr[start2++];
    }
    // 将额外申请的数组中的内容放回原数组
    // end 不能改为 len，因为 start 的值会有大于 len 的情况
    for (int i = start; i <= end; i++) {
        arr[i] = target[i];
    }
}

void mergeSort(int *arr, int len) {
    // 申请空间，使其大小为原数组的大小
    int target[len];
    mergeSortRecursive(arr, target, 0, len - 1);
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 10 };
    int len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}