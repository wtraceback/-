#include <stdio.h>

int search(const char *arr, int len, char target) {
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            index = i;
        }
    }

    return index;
}

int main() {
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' };

    int index = search(arr, 11, 'K');
    if (index == -1) {
        printf("元素不再数组中\n");
    } else {
        printf("元素在数组中的索引为 %d\n", index);
    }

    return 0;
}