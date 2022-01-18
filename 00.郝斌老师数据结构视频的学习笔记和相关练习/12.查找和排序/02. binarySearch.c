#include <stdio.h>

int binarySearch(const char *arr, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (target == arr[mid]) {
            return mid;
        } else  if (target < arr[mid]) {
            high = mid - 1;
        } else {
            // target > arr[mid]
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    char arr[] = { 1, 3, 4, 6, 7, 8, 10, 13, 14 };

    int index = binarySearch(arr, 0, 8, 10);
    if (index == -1) {
        printf("元素不再数组中\n");
    } else {
        printf("元素在数组中的索引为 %d\n", index);
    }

    return 0;
}