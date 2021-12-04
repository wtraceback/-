#include <stdio.h>

// 假定 n 的值大于或等于 0
long fn(long n) {
    if (1 >= n) {
        return 1;
    } else {
        return n * fn(n - 1);
    }
}

int main() {
    long n = 6;
    printf("%ld! = %ld\n", n, fn(n));

    return 0;
}
