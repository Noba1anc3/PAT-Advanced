
#include <stdio.h>
#include <stdlib.h>

//2023 2150
int main()
{
	int i, j = 0, k, num, girl = -1, boy = 101, space_sign = 0, status = -1, score, lock = 0, tmp, mp, fp;
	char c, input[21], tscore[3];
	char m[21], f[21];
	
	scanf("%d", &num);
	getchar();

	for(i = 0;i < num;i++){
		if(!space_sign){
			while((c = getchar()) != ' ')
				input[j++] = c;
			input[j++] = ' ';
			space_sign = 1;
		}
		if(space_sign == 1){
			c = getchar();
			if(c == 'M')
				status = 1;
			else
				status = 0;
			getchar();
			space_sign = 2;
		}
		if(space_sign == 2){
			while((c = getchar()) != ' ')
				input[j++] = c;
			j--;
			space_sign = 3;
		}
		if(space_sign == 3){
			if((c = getchar()) != '\n')
				tmp = (int)c - 48;
			if((c = getchar()) != '\n'){
				tmp = 10*tmp + (int)c - 48;
				score = tmp;
			}
			else{
				score = tmp;
				lock = 1;
			}
			if(score == 10){
				if((c = getchar()) != '\n'){
					score = 100;
					lock = 1;
					getchar();
				}
				else{
					lock = 1;
					score = tmp;
				}
			}
			else if( score != 10 && !lock){
				c = getchar();
				lock = 1;
			}

			if(status == 1 && score < boy){
				boy = score;
				mp = j;
				for(k = 0;k <= j;k++){
					m[k] = input[k];
				}
			}
			else if(status == 0 && score > girl){
				girl = score;
				fp = j;
				for(k = 0;k <= j;k++){
					f[k] = input[k];
				}
			}

			lock = 0;
			j = 0;
			status = -1;
			space_sign = 0;			
			
		}
	}
	if(girl == -1)
		printf("Absent");
	else{
		for(i = 0;i<=fp;i++)
			printf("%c", f[i]);
	}
	printf("\n");
	if(boy == 101)
		printf("Absent");
	else{
		for(i = 0;i<=mp;i++)
			printf("%c", m[i]);
	}
	printf("\n");
	if(girl == -1 || boy == 101)
		printf("NA");
	else
		printf("%d", girl - boy);

	return 0;
}
