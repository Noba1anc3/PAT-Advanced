#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

struct number{
    int value;
    int index;
};

bool cmp(number n1, number n2){
	if(n1.value < n2.value)
		return true;
	else
		return false;
}

int main()
{
    int n;
    number num[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i].value;
        num[i].index=i;
    }
    sort(num,num+n, cmp);

    if(n&1==1) 
		cout<<num[n/2].value<<" "<<num[n/2].index+1;
    else 
		cout<<num[n/2-1].value<<" "<<num[n/2-1].index+1<<endl<<num[n/2].value<<" "<<num[n/2].index+1;

    return 0;
}
