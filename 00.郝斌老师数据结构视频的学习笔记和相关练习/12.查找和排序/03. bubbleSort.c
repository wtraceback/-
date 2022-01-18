#include <stdio.h>

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 220, 34, 3, 32, 82, 55, 891, 50, 37, 5, 64, 35, 9, 1070 };
    int len = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}