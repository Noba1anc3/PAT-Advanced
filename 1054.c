/*
#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
using namespace std;

struct pixel{
	int color;
	int times;
};

bool cmp(pixel a, pixel b){
	if(a.times > b.times)
		return true;
	else
		return false;
}

int main(){
	int row, column, tmp, i, j, lock = 0;
	pixel image[480000];

	scanf("%d %d", &row, &column);

	for( i = 0; i < row*column; i++){
		scanf("%d", &tmp);
		for( j = 0; j < i; j++){
			if( tmp == image[j].color){
				image[j].times++;
				lock = 1;
			}
		}		
		if(!lock){
			image[i].color = tmp;
			image[i].times = 1;
		}
		lock = 0;
	}
	
	sort(image, image+480000, cmp);
	printf("%d", image[0].color);
	
	return 0;	

}*/


#include <stdio.h>

int main()
{
	int M, N, i, found, count = 1, tmp;

	scanf("%d%d%d", &M, &N, &tmp);
	found = tmp;

	for(i = 1; i < M*N; i++){
	    scanf("%d", &tmp);
	    if( !count ){
	    	found = tmp;
	    	count = 1;
		  }
		  else{
			  if(found == tmp)
			    count++;
			  else
			    count--;
	  	}
	}
	
	printf("%d\n", found);
	
	return 0;   
}
