#include <stdio.h>

void Hanoi(int n, char A, char B, char C) {
    if (1 == n) {
        printf("编号为 %d 的盘子的移动方向： %c --> %c\n", n, A, C);
    } else {
        Hanoi(n - 1, A, C, B);
        printf("编号为 %d 的盘子的移动方向： %c --> %c\n", n, A, C);
        Hanoi(n - 1, B, A, C);
    }
}

int main() {
    long n = 3;
    Hanoi(n, 'A', 'B', 'C');

    return 0;
}

/*
    伪算法：
        if 只有一个圆盘
            直接将圆盘从 A 柱子移动到 C 柱子上
        else
            先将 A 柱子上的 n-1 个盘子借助 C 移动到 B 上
            直接将圆盘从 A 柱子移动到 C 上
            最后将 B 柱子上的 n-1 个盘子借助 A 移动到 C 上

    算法复杂度：
        n=1         移动 1 次
        n=2         移动 3 次
        n=3         移动 7 次
        ...

        汉诺塔的复杂度是 2^n - 1 （问题很复杂，但真正解决问题的编码就只有三句）
*/