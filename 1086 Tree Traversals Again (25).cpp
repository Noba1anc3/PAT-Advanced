
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild, *rchild, *father;
}BiTNode, *BiTree;

void PostTraversal(BiTree T, int root_data);

int main(){
	int i, tmp, num;
	char c;
	vector<int> nodes;
	BiTree T = NULL;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = -1;
	T->lchild = NULL;
	T->rchild = NULL;
	T->father = NULL;

	scanf("%d\n", &num);
	for(i = 0; i < 2*num; i++){
		getchar();
		c = getchar();
		if(c == 'u'){
			getchar();
			getchar();
			scanf("%d\n", &tmp);
		}
		else{
			getchar();
			getchar();
			tmp = -1;
		}
		nodes.push_back(tmp);
	}

	int last = 0;
	for(vector<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if( *(it) != -1 )
		{
			if(!last){
				if(T->data != -1)
					T = T->lchild;
				T->data = *(it);
				T->lchild = (BiTree)malloc(sizeof(BiTNode));
				T->lchild->data = -1;
				T->lchild->lchild = NULL;
				T->lchild->rchild = NULL;
				T->lchild->father = T;

				T->rchild = (BiTree)malloc(sizeof(BiTNode));
				T->rchild->data = -1;
				T->rchild->lchild = NULL;
				T->rchild->rchild = NULL;
				T->rchild->father = T;

				T = T->lchild;
			}
			else{
				T = T->rchild;
				T->data = *(it);

				T->lchild = (BiTree)malloc(sizeof(BiTNode));
				T->lchild->data = -1;
				T->lchild->lchild = NULL;
				T->lchild->rchild = NULL;
				T->lchild->father = T;

				T->rchild = (BiTree)malloc(sizeof(BiTNode));
				T->rchild->data = -1;
				T->rchild->lchild = NULL;
				T->rchild->rchild = NULL;
				T->rchild->father = T;
			}
			last = 0;
		}
		else{
			T = T->father;
			last = 1;
		}
	}

	while(T->father != NULL)
		T = T->father;
	
	PostTraversal(T, T->data);

	return 0;

}

void PostTraversal(BiTree T, int root_data){
	if(T->data == -1)
		return;
	PostTraversal(T->lchild, root_data);
	PostTraversal(T->rchild, root_data);
	if(T->data != root_data)
		cout<<T->data<<" ";
	else
		cout<<T->data<<"\n";
}
