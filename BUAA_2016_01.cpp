#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n1,n2;
    int tmp;
    char str1[100];
    char str2[100];
    scanf("%d",&n1);
    itoa(n1,str1,10);
    reverse(str1,str1+strlen(str1));
    n2=atoi(str1);
    if(n2%n1==0)
        printf("%d*%d=%s",n1,n2/n1,str1);
    else
        printf("%d %s",n1,str1);

    return 0;
}
