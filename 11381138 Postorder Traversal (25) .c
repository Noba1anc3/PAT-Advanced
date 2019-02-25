#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int lock = 0;
typedef struct BinTNode{
	int data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

void PostOrderTraversal(BinTree BT);
BinTree ReBuildTree(int pre[], int i, int j, int in[], int m, int n);

int main()
{
	int n, i;
	int pre[50000], in[50000];
	BinTree p;

	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &pre[i]);
	for(i = 0;i < n;i++)
		scanf("%d", &in[i]);

	p = ReBuildTree(pre, 0, n-1, in, 0, n-1);
	
	PostOrderTraversal(p);

    return 0;
}

BinTree ReBuildTree(int pre[], int i, int j, int in[], int m, int n)
{
    int x = m;  //x是遍历器
    BinTree p;   //p是新的结点
    p = (BinTree)malloc(sizeof(BinTNode));
    p->data = pre[i];      //从后序序列中读取结点信息

	//在中序中找到根节点位置
    for (; in[x] != pre[i]; x++)
		;

    //接下来递归完成左右子树的构建
    if (x == m) 
		p->lchild = NULL;
    else
        p->lchild = ReBuildTree(pre, i+1, i+x-m, in, m, x-1); 
    if (x == n) 
		p->rchild = NULL;
    else
        p->rchild = ReBuildTree(pre, j+x+1-n, j, in, x+1,n);
  
    return p;
}

void PostOrderTraversal(BinTree BT){
  if(BT){
    PostOrderTraversal(BT->lchild);
    PostOrderTraversal(BT->rchild);
	if(!lock){
		printf("%d", BT->data);
		lock = 1;
	}
  }
}
