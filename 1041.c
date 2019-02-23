
#include<stdio.h>

int distribution[10008];
int num[100008];

int main(){

	int i,j,n;

	for(i=0;i<=10000;i++)
		distribution[i]=0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		distribution[num[i]]++;
	}

	for(i=0;i<n;i++){
		if(distribution[num[i]]==1){
			printf("%d\n",num[i]);
			break;
		}
	}

	if(i==n) 
		printf("None\n");

	return 0;	

}
