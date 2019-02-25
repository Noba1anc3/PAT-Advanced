
#include <stdio.h>
#include <stdlib.h>

typedef struct BinTNode{
	int data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

BinTree ReBuildTree(int *post, int i, int j, int *in, int m, int n);
void LevelOrderTraversal(BinTree BT, int n);

int main()
{
	int n, i;
	BinTree p;
	int post[30], in[30];

	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &post[i]);
	for(i = 0;i < n;i++)
		scanf("%d", &in[i]);

	p = ReBuildTree(post, 0, n-1, in, 0, n-1);
	LevelOrderTraversal(p, n);

    return 0;
}


BinTree ReBuildTree(int *post, int i, int j, int *in, int m, int n)
{
    //post[i.....j] in[m....n]
    int x;  //x是遍历器
    BinTree p;   //p是新的结点
    p = (BinTree)malloc(sizeof(BinTNode));
    p->data = *(post + j);      //从后序序列中读取结点信息
    x = m;

	//在中序中找到根节点位置
    for (; *(in + x) != p->data; x++)
		;

    //接下来递归完成左右子树的构建
    if (x == m) 
		p->lchild = NULL;
    else
        p->lchild = ReBuildTree(post, i, i+x-m-1, in, m, x-1);

    if (x == n) 
		p->rchild = NULL;
    else
        p->rchild = ReBuildTree(post, i+x-m, j-1, in, x+1, n);
 
    return p;
}

void LevelOrderTraversal(BinTree BT, int n){

	BinTree queue[30], T;
	int head = 0, rear = 0, count = 0;

	if(!BT)
		return;
	
	queue[rear++] = BT;
	
	while(head != rear){
		T = queue[head++];
		if(count < n-1){
  			printf("%d ", T->data);
  			count++;
		}
		else
  			printf("%d\n", T->data);

		if(T->lchild)
			queue[rear++] = T->lchild;
		
		if(T->rchild)
			queue[rear++] = T->rchild;
		
	}
}
