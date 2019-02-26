#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> input, pre1, pre2, post1, post2;

typedef struct BiTNode{
    int data;
    BiTNode *left;
    BiTNode *right;
}BiTNode, *BiTree;

void insert(BiTree &T, int data){
    if(T == NULL){
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;
        T->left = NULL;
        T->right = NULL;
    }
    
    else{
        if(data < T->data)
            insert(T->left, data);
        else
            insert(T->right, data);
    }

}

void preorder1(BiTree T){
    if(T == NULL) 
	return;
    pre1.push_back(T->data);
    preorder1(T->left);
    preorder1(T->right);
}

void preorder2(BiTree T){
    if(T == NULL) 
	return;
    pre2.push_back(T->data);
    preorder2(T->right);
    preorder2(T->left);
}

void postorder1(BiTree T){
    if(T == NULL) 
	return;
    postorder1(T->left);
    postorder1(T->right);
    post1.push_back(T->data);
}

void postorder2(BiTree T){
    if(T == NULL) 
	return;
    postorder2(T->right);
    postorder2(T->left);
    post2.push_back(T->data);
}

int main(){
    int n;
    cin>>n;
    BiTree T = NULL;
    for(int i = 0; i < n; i++){
       int data;
       cin>>data;
       input.push_back(data);
       insert(T, data);
    }

    preorder1(T);
    preorder2(T);

    if(input == pre1)
    {
        cout<<"YES"<<endl;
        postorder1(T);
        cout<<post1[0];
        for(int i = 1; i < post1.size(); i++)
            cout<<" "<<post1[i];
    }

    else if(input == pre2)
    {
        cout<<"YES"<<endl;
        postorder2(T);
        cout<<post2[0];
        for(int i = 1; i < post2.size(); i++)
            cout<<" "<<post2[i];
    }

    else
    {
        cout<<"NO"<<endl;
    }

}
