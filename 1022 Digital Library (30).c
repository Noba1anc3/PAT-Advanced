
#include <stdio.h>
#include <stdlib.h>

//1450 1750
//尚未对结果排序  
// i hate C
typedef struct book{
	char number[10000][7];
	char title[10000][80];
	char author[10000][80];
	char keyword[10000][5][10];
	int keywords[10000];
	char publisher[10000][80];
	char year[10000][4];
}book, *queue;

typedef struct answer{
	char sheet[100000][100];
}answer, *st;

int main()
{
	int num, i, j, k, l, count_of_keyword = 0, num_of_quests, request_length, p, q, answer_counter = 0, found = 0;
	char c, request[100];
	queue booklist;
	st answer;

	booklist = (queue)malloc(sizeof(book));
	answer = (st)malloc(sizeof(answer));

	scanf("%d", &num);
	getchar();

	for(i = 0;i<num;i++){
		for(j = 0;j<7;j++)
			scanf("%c", &(*booklist).number[i][j]);
		j = 0;
		c = getchar();
		while((c = getchar()) != '\n')
			(*booklist).title[i][j++] = c;
		(*booklist).title[i][j] = '|';
		j = 0;
		while((c = getchar()) != '\n')
			(*booklist).author[i][j++] = c;
		(*booklist).author[i][j] = '|';
		j = 0;
		while((c = getchar()) != '\n'){
			if(c != ' ')
				(*booklist).keyword[i][count_of_keyword][j++] = c;
			else{
				(*booklist).keyword[i][count_of_keyword][j] = '|';
				j = 0;
				count_of_keyword++;
			}
		}
		(*booklist).keyword[i][count_of_keyword][j] = '|';
		j = 0;
		count_of_keyword++;
		(*booklist).keywords[i] = count_of_keyword;
		count_of_keyword = 0;
		while((c = getchar()) != '\n')
			(*booklist).publisher[i][j++] = c;
		(*booklist).publisher[i][j] = '|';
		j = 0;
		while((c = getchar()) != '\n')
			(*booklist).year[i][j++] = c;		
		j = 0;

	}

	scanf("%d", &num_of_quests);
	getchar();
	for(i = 0; i<num_of_quests;i++){

		j = 0;
		found = 0;

		while((c = getchar()) != '\n'){
			request[j++] = c;
		}
		request_length = j;

		for(p = 0;p<request_length;p++)
			(*answer).sheet[answer_counter][p] = request[p];
		(*answer).sheet[answer_counter++][p] = '|';

		if(request[0] == '1'){
			for(j = 0;j < num;j++){
				for(k = 3; k < request_length ;k++){
					if((*booklist).title[j][k-3] == request[k] && k != request_length - 1)
						continue;
					else{
						if(k == request_length -1 && (*booklist).title[j][k-3] == request[k] &&  (*booklist).title[j][k-2] == '|'){
							for(q = 0;q<7;q++)
								(*answer).sheet[answer_counter][q] = (*booklist).number[j][q];
							(*answer).sheet[answer_counter++][q] = '|';
							found = 1;
						}
						else
							break;
					}
				}
			}
			if(j == num && !found){
				(*answer).sheet[answer_counter][0] = 'N';
				(*answer).sheet[answer_counter][1] = 'o';
				(*answer).sheet[answer_counter][2] = 't';
				(*answer).sheet[answer_counter][3] = ' ';
				(*answer).sheet[answer_counter][4] = 'F';
				(*answer).sheet[answer_counter][5] = 'o';
				(*answer).sheet[answer_counter][6] = 'u';
				(*answer).sheet[answer_counter][7] = 'n';
				(*answer).sheet[answer_counter][8] = 'd';
				(*answer).sheet[answer_counter++][9] = '|';
			}
		}

		else if(request[0] == '2'){
			for(j = 0;j < num;j++){
				for(k = 3; k < request_length;k++){
					if((*booklist).author[j][k-3] == request[k] && k != request_length - 1)
						continue;
					else{
						if(k == request_length -1 && (*booklist).author[j][k-3] == request[k] &&  (*booklist).author[j][k-2] == '|'){
							for(q = 0;q<7;q++)
								(*answer).sheet[answer_counter][q] = (*booklist).number[j][q];
							(*answer).sheet[answer_counter++][q] = '|';
							found = 1;
						}
						else
							break;
					}
				}
			}
			if(j == num && !found){
				(*answer).sheet[answer_counter][0] = 'N';
				(*answer).sheet[answer_counter][1] = 'o';
				(*answer).sheet[answer_counter][2] = 't';
				(*answer).sheet[answer_counter][3] = ' ';
				(*answer).sheet[answer_counter][4] = 'F';
				(*answer).sheet[answer_counter][5] = 'o';
				(*answer).sheet[answer_counter][6] = 'u';
				(*answer).sheet[answer_counter][7] = 'n';
				(*answer).sheet[answer_counter][8] = 'd';
				(*answer).sheet[answer_counter++][9] = '|';
			}			
		}

		else if(request[0] == '3'){
			for(j = 0;j < num;j++){
				for(l = 0;l < (*booklist).keywords[j];l++){
					for(k = 3; k < request_length;k++){
						if((*booklist).keyword[j][l][k-3] == request[k] && k != request_length - 1)
							continue;
						else{
							if(k == request_length -1 && (*booklist).keyword[j][l][k-3] == request[k] &&  ( k == 12 || (*booklist).keyword[j][l][k-2] == '|') ){
								for(q = 0;q < 7;q++)
									(*answer).sheet[answer_counter][q] = (*booklist).number[j][q];
								(*answer).sheet[answer_counter++][q] = '|';
								found = 1;
							}
							else
								break;
						}
					}

				}
			}

			if(j == num && !found){
				(*answer).sheet[answer_counter][0] = 'N';
				(*answer).sheet[answer_counter][1] = 'o';
				(*answer).sheet[answer_counter][2] = 't';
				(*answer).sheet[answer_counter][3] = ' ';
				(*answer).sheet[answer_counter][4] = 'F';
				(*answer).sheet[answer_counter][5] = 'o';
				(*answer).sheet[answer_counter][6] = 'u';
				(*answer).sheet[answer_counter][7] = 'n';
				(*answer).sheet[answer_counter][8] = 'd';
				(*answer).sheet[answer_counter++][9] = '|';
			}
		}

		else if(request[0] == '4'){
			for(j = 0;j < num;j++){
				for(k = 3; k < request_length ;k++){
					if((*booklist).publisher[j][k-3] == request[k] && k != request_length - 1)
						continue;
					else{
						if(k == request_length -1 && (*booklist).publisher[j][k-3] == request[k] &&  (*booklist).publisher[j][k-2] == '|'){
							for(q = 0;q<7;q++)
								(*answer).sheet[answer_counter][q] = (*booklist).number[j][q];
							(*answer).sheet[answer_counter++][q] = '|';
							found = 1;
						}
						else
							break;
					}
				}
			}
			if(j == num && !found){
				(*answer).sheet[answer_counter][0] = 'N';
				(*answer).sheet[answer_counter][1] = 'o';
				(*answer).sheet[answer_counter][2] = 't';
				(*answer).sheet[answer_counter][3] = ' ';
				(*answer).sheet[answer_counter][4] = 'F';
				(*answer).sheet[answer_counter][5] = 'o';
				(*answer).sheet[answer_counter][6] = 'u';
				(*answer).sheet[answer_counter][7] = 'n';
				(*answer).sheet[answer_counter][8] = 'd';
				(*answer).sheet[answer_counter++][9] = '|';
			}
		}

		else
		{
			for(j = 0;j < num;j++){
				for(k = 3; k < request_length ;k++){
					if((*booklist).year[j][k-3] == request[k])
						continue;
					else
						break;
				}
				if(k == request_length){
					for(q = 0;q<7;q++)
						(*answer).sheet[answer_counter][q] = (*booklist).number[j][q];
					(*answer).sheet[answer_counter++][q] = '|';
					found = 1;
				}
			}
			if(j == num && !found){
				(*answer).sheet[answer_counter][0] = 'N';
				(*answer).sheet[answer_counter][1] = 'o';
				(*answer).sheet[answer_counter][2] = 't';
				(*answer).sheet[answer_counter][3] = ' ';
				(*answer).sheet[answer_counter][4] = 'F';
				(*answer).sheet[answer_counter][5] = 'o';
				(*answer).sheet[answer_counter][6] = 'u';
				(*answer).sheet[answer_counter][7] = 'n';
				(*answer).sheet[answer_counter][8] = 'd';
				(*answer).sheet[answer_counter++][9] = '|';
			}
		}

	}

	for(i = 0;i<answer_counter;i++){
		for(j = 0;(*answer).sheet[i][j] != '|';j++)
			printf("%c", (*answer).sheet[i][j]);
		printf("\n");
	}

	return 0;
}
