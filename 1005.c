// 1.cpp : Defines the entry point for the console application.
//

/*
#include <stdio.h>


int summer = 0;

void sum(){
	char c;
	scanf("%c",&c);
	if(c != '\n'){
		summer += (int)c - 48;
		sum();
	}
}



int main()
{
	char summ[1000];
	sum();
	sprintf(summ, "%d", summer);
	for(int i = 0;summ[i] != '\0';i++){
		if(summ[i] == '0')
			printf("zero");
		else if(summ[i] == '1')
			printf("one");
		else if(summ[i] == '2')
			printf("two");
		else if(summ[i] == '3')
			printf("three");
		else if(summ[i] == '4')
			printf("four");
		else if(summ[i] == '5')
			printf("five");
		else if(summ[i] == '6')
			printf("six");
		else if(summ[i] == '7')
			printf("seven");
		else if(summ[i] == '8')
			printf("eight");
		else
			printf("nine");
		if(summ[i+1] != '\0')
			printf(" ");
	}
	return 0;
}

*/

#include <stdio.h>

int main()
{
    int sum = 0;
    char c, *digits[] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };

    while((c = getchar()) != '\n')
        sum += c - '0';

    if(sum >= 100)
        printf("%s ", digits[sum / 100]);
    if(sum >= 10)
        printf("%s ", digits[sum % 100 / 10]);
    printf("%s", digits[sum % 10]);

    return 0;
}
