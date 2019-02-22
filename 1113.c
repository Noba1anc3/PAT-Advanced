
/*
#include <stdio.h>

//2117-2138
int main()
{
	int num, nm[10000], i, j, t, sum1 = 0, sum2 = 0;
	scanf("%d",&num);

	for(i = 0;i<num;i++)
		scanf("%d",&nm[i]);

    for(i = 0;i<num-1;i++)
    {          
        for(j=0;j<num-i-1;++j)
        {
            if(nm[j]>nm[j+1])
            {
                t=nm[j];
                nm[j]=nm[j+1];
                nm[j+1]=t;
            }
        }
    }

	if(num%2 == 1)
		printf("1 ");
	else
		printf("0 ");

	for(j=0;j<num/2;j++)
        sum1 += nm[j];

	for(j=num-1;j>=num/2;j--)
        sum2 += nm[j];

	printf("%d", sum2 - sum1);

  return 0;
}

*/


#include<cstdio>
#include<algorithm>
using namespace std;

int nm[100000];

int main()
{
  
	int num;
	scanf("%d",&num);

	for (int i = 0; i < num; i++)
		scanf("%d", &nm[i]);

	sort(nm, nm + num);

	int sum1 = 0, sum2 = 0;
	
	for (int i = 0; i < num/2; i++)
			sum1 += nm[i];
	for (int i = num - 1; i >=num/2; i--)
			sum2 += nm[i];

	if(num%2 == 1)
		printf("1 ");
	else
		printf("0 ");
	printf("%d", sum2 - sum1);

	return 0;
}
