
#include <stdio.h>
#include <stdlib.h>

//1430 
int main()
{
	int i, j, k, l, t[5], tmp, req_num, wnd_num, total_wait_time = 0, wnd_table[100], queue[10][5];
	double real_req_num = 0;
	
	scanf("%d %d\n",&req_num,&wnd_num);

	for(i = 0;i<req_num;i++){
		scanf("%d:%d:%d %d",&queue[i][0],&queue[i][1],&queue[i][2],&queue[i][3]);
		if(i < req_num - 1)
			getchar();
		queue[i][4] = queue[i][0]*3600 + queue[i][1]*60 + queue[i][2];
	}

    for(i=0;i<req_num;i++)
    {            
        for(j=0;j<req_num-i-1;++j)
        {
            if(queue[j][4]>queue[j+1][4])
            {
				for(k = 0;k<5;k++)
					t[k]=queue[j][k];

				for(k = 0;k<5;k++)
					queue[j][k]=queue[j+1][k];

				for(k = 0;k<5;k++)
					queue[j+1][k]=t[k];
            }
        }
    }

	for(i = 0;i < wnd_num;i++)
		wnd_table[i] = 28800;
	
	for( i = 0; i < req_num ; i++ ){

	    for(j = 0;j < wnd_num; j++)
		{            
			for(k = 0;k < wnd_num - j - 1; k++)
			{
				if(wnd_table[k] > wnd_table[k+1])
				{
					for(l = 0;l < 5; l++)
						tmp = wnd_table[k];

					for(l = 0;l < 5; l++)
						wnd_table[k] = wnd_table[k+1];

					for(l = 0;l < 5; l++)
						wnd_table[k+1]=tmp;
		        }
			}
		}	

		if(queue[i][3] > 60)
			queue[i][3] = 60;

		if(queue[i][4] < 28800){
			total_wait_time += 28800 - queue[i][4];
			queue[i][4] = 28800;		
		}

		else if(queue[i][4] > 61200)
			continue;

		if(queue[i][4] >= wnd_table[0])
			wnd_table[0] = queue[i][4] + queue[i][3]*60;
		else{
			total_wait_time += wnd_table[0] - queue[i][4];
			wnd_table[0] += queue[i][3]*60;
		}
		real_req_num++;
		
	}

	printf("%.1f", total_wait_time/real_req_num/60.0);

	return 0;
}
