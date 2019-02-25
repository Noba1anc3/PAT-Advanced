#include <stdio.h>
#include <stdlib.h>

typedef struct BinTNode{
	char data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

BinTree ReBuildTree(char *post, int i, int j, char *in, int m, int n);
void LevelOrderTraversal(BinTree BT, int n);

int main()
{
	int n, i;
	BinTree p;
	char post[300], in[300];
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%c ", &post[i]);
	scanf("%c", &post[i]);
	for(i = 0;i < n;i++)
		scanf("%c ", &in[i]);
	scanf("%c", &in[i]);
	p = ReBuildTree(post,1,n,in,1,n);
	LevelOrderTraversal(p, n);
    return 0;
}


BinTree ReBuildTree(char *post, int i, int j, char *in, int m, int n)
{
    //post[i.....j] in[m....n]
    int x;  //x是遍历器
    BinTree p;   //p是新的结点
    p = (BinTree)malloc(sizeof(BinTNode));
    p->data = *(post + j);      //从后序序列中读取结点信息
    x = m;

	//在中序中找到根节点位置
    for (; *(in + x) != *(post + j); x++)
		;

    //接下来递归完成左右子树的构建
    if (x == m) 
		p->lchild = NULL;
    else
    {
        p->lchild = ReBuildTree(post, i, i+x-m-1, in, m, x-1);
    }

    if (x == n) 
		p->rchild = NULL;

    else
    {
        p->rchild = ReBuildTree(post, i+x-m, j-1, in, x+1,n);
    } 
    return p;
}

void LevelOrderTraversal(BinTree BT, int n){

	BinTree queue[300], T;
	int head = 0, rear = 0, count;

	if(!BT)
		return;
	
	queue[head] = BT;
	rear++;
	
	while(head != rear){
		T = queue[head++];
	  if(count < n-1){
  		printf("%d ", T->data - 48);
  		count++;
	  }
  	else
  		printf("%d", T->data - 48);
		if(T->lchild){
			queue[rear] = T->lchild;
			rear++;
		}
		if(T->rchild){
			queue[rear] = T->rchild;
			rear++;
		}
	}
}
