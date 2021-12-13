#include <stdio.h>
#include <stdlib.h>     // malloc

typedef struct TreeNode {
    char data;                       // 数据域
    struct TreeNode * lchild;       // 左孩子指针
    struct TreeNode * rchild;       // 右孩子指针
} TreeNode;

TreeNode * createBTree();
void preOrderTraversal(TreeNode *T);
void inOrderTraversal(TreeNode *T);
void postOrderTraversal(TreeNode *T);

int main() {
    TreeNode * BTree = createBTree();

    printf("前序遍历的结果：\n");
    preOrderTraversal(BTree);
    printf("\n\n");

    printf("中序遍历的结果：\n");
    inOrderTraversal(BTree);
    printf("\n\n");

    printf("后序遍历的结果：\n");
    postOrderTraversal(BTree);
    printf("\n\n");

    return 0;
}

// 创建一个链式二叉树
TreeNode * createBTree() {
    TreeNode *pa = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *pb = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *pc = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *pd = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *pe = (TreeNode *)malloc(sizeof(TreeNode));

    pa->data = 'A';
    pa->lchild = pb;
    pa->rchild = pc;

    pb->data = 'B';
    pb->lchild = pb->rchild = NULL;

    pc->data = 'C';
    pc->lchild = pd;
    pc->rchild = pe;

    pd->data = 'D';
    pd->lchild = pd->rchild = NULL;

    pe->data = 'E';
    pe->lchild = pe->rchild = NULL;

    return pa;
}

// 二叉树的前序遍历递归算法
void preOrderTraversal(TreeNode *T) {
    if (NULL == T) {
        return;
    } else {
        printf("%c ", T->data);             // 显示节点数据，可以更改为其他对节点的操作
        preOrderTraversal(T->lchild);       // 再先序遍历左子树
        preOrderTraversal(T->rchild);       // 最后先序遍历右子树
    }
}

// 二叉树的中序遍历递归算法
void inOrderTraversal(TreeNode *T) {
    if (NULL == T) {
        return;
    } else {
        inOrderTraversal(T->lchild);        // 中序遍历左子树
        printf("%c ", T->data);             // 显示节点数据，可以更改为其他对节点的操作
        inOrderTraversal(T->rchild);        // 最后中序遍历右子树
    }
}

// 二叉树的后序遍历递归算法
void postOrderTraversal(TreeNode *T) {
    if (NULL == T) {
        return;
    } else {
        postOrderTraversal(T->lchild);      // 先后序遍历左子树
        postOrderTraversal(T->rchild);      // 再后序遍历右子树
        printf("%c ", T->data);             // 显示节点数据，可以更改为其他对节点的操作
    }
}