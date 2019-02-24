
#include <stdio.h>
#include <stdlib.h>

int n, count = 0;

typedef struct BTNode{
	int lchild, rchild;
}BTNode;

int GetTreeHead(int n, BTNode nodes[]);
void InOrderTraverse(int head, BTNode nodes[]);
void LevelOrderTraverse(int head, BTNode nodes[]);

int main()
{
	char tmpl, tmpr;
	BTNode nodes[10];
	
	scanf("%d\n", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%c %c\n", &tmpr, &tmpl);
		if(tmpr == '-')
			nodes[i].rchild = -1;
		else
			nodes[i].rchild = tmpr - 48;
		if(tmpl == '-')
			nodes[i].lchild = -1;
		else
			nodes[i].lchild = tmpl - 48;
	}
	scanf("%c %c", &tmpr, &tmpl);

	if(tmpr == '-')
		nodes[n-1].rchild = -1;
	else
		nodes[n-1].rchild = tmpr - 48;
	if(tmpl == '-')
		nodes[n-1].lchild = -1;
	else
		nodes[n-1].lchild = tmpl - 48;

	int head = GetTreeHead(n, nodes);

	LevelOrderTraverse(head, nodes);
	InOrderTraverse(head, nodes);

    return 0;

}

int GetTreeHead(int n, BTNode nodes[]){
	int i;
	int scan[10];
	for(i = 0; i < n; i++){
		if(nodes[i].lchild >= 0)
			scan[nodes[i].lchild] = 1;
		if(nodes[i].rchild >= 0)
			scan[nodes[i].rchild] = 1;
	}
	for(i = 0; i < n; i++)
		if(scan[i] != 1)
			return i;
}

void InOrderTraverse(int head, BTNode nodes[]){

	if(head < 0)
		return;

	InOrderTraverse(nodes[head].lchild, nodes);

	if(count < n-1){
		printf("%d ", head);
		count++;
	}
	else
		printf("%d\n", head);
	
	InOrderTraverse(nodes[head].rchild, nodes);
}


void LevelOrderTraverse(int head, BTNode nodes[]){

	int queue[10];
	int front = 0, rear = 0;

	if(head < 0)
		return;

	queue[rear++] = head;

	while(front != rear){
		int prt = queue[front];

		if( count < n-1 ){
			printf("%d ", prt);
			count++;
		}
		else
			printf("%d\n", prt);

		if(nodes[queue[front]].lchild >= 0)
			queue[rear++] = nodes[queue[front]].lchild;
		
		if(nodes[queue[front]].rchild >= 0)
			queue[rear++] = nodes[queue[front]].rchild;
		
		front++;
	}
	count = 0;

}

