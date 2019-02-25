#include<iostream>
#include <vector>
using namespace std;

vector<int> in, pre, post;
bool uniquer = true;

void getin(int prel, int prer, int postl, int postr){

	if(prel == prer) {              //若遍历左右相等，则说明此子树为叶节点
		in.push_back(pre[prer]);    //叶节点直接插入中序遍历中
        return;
	}

    if (pre[prel] == post[postr]) {   //前序的开始的第一个应该是后序的最后一个是相等的，这个结点就是根结点

        int i = prel + 1;

        while (pre[i] != post[postr - 1]) 
			i++;

        if (i - prel > 1)             // i-prel = 1时代表只有一个子树
            getin(prel + 1, i - 1, postl, postl + i - prel - 2);
        else
            uniquer = false;

        in.push_back(post[postr]);

        getin(i, prer, postl + i - prel - 1, postr - 1);

    }
}

int main() {

	int i, n;

    cin>>n;
    pre.resize(n), post.resize(n);

    for(i = 0; i < n; i++)
    	cin>>pre[i];

	for(i = 0; i < n; i++)
    	cin>>post[i];

	getin(0, n-1, 0, n-1);

	printf("%s\n%d", uniquer == true ? "Yes" : "No", in[0]);
	for (i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
    return 0;

}
