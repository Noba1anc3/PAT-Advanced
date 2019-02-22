// 1.cpp : Defines the entry point for the console application.
//

/*#include <stdio.h>
#include <math.h>

int main()
{
	int num, first = 235959, last = 000000;
	int tf = 0, tl = 0, nf = 0, nl = 0;
	char record[100][14], tmp;
	scanf("%d\n",&num);
	for(int i = 0;i < num;i++){

		for(int j = 0;j < 15;j++){
			scanf("%c",&record[i][j]);
			if(record[i][j] == ' ')
				break;
		}

		for(int cd = 8;cd;cd--){
			scanf("%c",&tmp);
			if(cd > 6){
				tf += (tmp-48)*(int)pow(10,cd - 3);
			}
			else if(cd > 3 && cd < 6){
				tf += (tmp-48)*(int)pow(10,cd - 2);
			}
			else if(cd > 0 && cd < 3){
				tf += (tmp-48)*(int)pow(10,cd - 1);
			}			
		}
		if(tf < first){
			first = tf;
			nf = i;
		}
		
		scanf("%c",&tmp);
		for(int cd = 8;cd;cd--){
			scanf("%c",&tmp);
			if(cd > 6){
				tl += (tmp-48)*(int)pow(10,cd - 3);
			}
			else if(cd > 3 && cd < 6){
				tl += (tmp-48)*(int)pow(10,cd - 2);
			}
			else if(cd > 0 && cd < 3){
				tl += (tmp-48)*(int)pow(10,cd - 1);
			}			
		}
		if(tl > last){
			last = tl;
			nl = i;
		}
		
		tf = tl = 0;

		scanf("%c",&tmp);
		continue;
		
	}
	for(int i=0;record[nf][i] != ' ';i++)
		printf("%c",record[nf][i]);
	printf(" ");
	for(int i=0;record[nl][i] != ' ';i++)
		printf("%c",record[nl][i]);
	return 0;
}

*/

#include <stdio.h>
#include <string.h>

int main()
{
    int N, HH, MM, SS;
    int firsttime = 86400, lasttime = -1, time;
    char firstname[16], lastname[16], name[16];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %d:%d:%d", name, &HH, &MM, &SS);
        time = (HH * 60 + MM) * 60 + SS;
        if(time < firsttime)
        {
            firsttime = time;
            strcpy(firstname, name);
        }

        scanf("%d:%d:%d", &HH, &MM, &SS);
        time = (HH * 60 + MM) * 60 + SS;
        if(time > lasttime)
        {
            lasttime = time;
            strcpy(lastname, name);
        }
    }

    printf("%s %s", firstname, lastname);

    return 0;
}

