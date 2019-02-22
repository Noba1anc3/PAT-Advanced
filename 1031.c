
#include <stdio.h>
#include <stdlib.h>
//1946 2011

int main()
{
	int i = 0, j, count, n0, n2;
	char c, input[100];
	while((c = getchar()) != '\n')
		input[i++] = c;
	count = i;
	n0 = (count + 2) / 3 ;  
  n2 = count +2 - 2*n0;  
	for(i = 0; i < n0 - 1 ; i++){
		printf("%c", input[i]);
		for(j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n", input[count - i - 1]);
	}
	for(i = n0 - 1; i < count - n0 + 1 ;i++)
		printf("%c", input[i]);
	return 0;
}
