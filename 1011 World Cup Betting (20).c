/*
#include <stdio.h>

int main()
{
	double tmpa, tmpb, tmpc, tmpd, tmpe, tmpf, tmpg, tmph, tmpi, top, tmp = 1;
	int tp = 0;

		scanf("%lf",&tmpa);
		scanf("%lf",&tmpb);
		scanf("%lf",&tmpc);

		scanf("%lf",&tmpd);
		scanf("%lf",&tmpe);
		scanf("%lf",&tmpf);

		scanf("%lf",&tmpg);
		scanf("%lf",&tmph);
		scanf("%lf",&tmpi);

		if(tmpa >= tmpb){
			top = tmpa;
			tp = 1;
		}
		else{
			top = tmpb;
			tp = 2;
		}
		if(tmpc >= top){
			top = tmpc;
			tp = 3;
		}
		tmp *= top;

		if(tp == 1)
			printf("W ");
		else if(tp == 2)
			printf("T ");
		else
			printf("L ");

		if(tmpd >= tmpe){
			top = tmpd;
			tp = 1;
		}
		else{
			top = tmpe;
			tp = 2;
		}
		if(tmpf >= top){
			top = tmpf;
			tp = 3;
		}

		if(tp == 1)
			printf("W ");
		else if(tp == 2)
			printf("T ");
		else
			printf("L ");
		tmp *= top;

		if(tmpg >= tmph){
			top = tmpg;
			tp = 1;
		}
		else{
			top = tmph;
			tp = 2;
		}
		if(tmpi >= top){
			top = tmpi;
			tp = 3;
		}

		if(tp == 1)
			printf("W ");
		else if(tp == 2)
			printf("T ");
		else
			printf("L ");
		tmp *= top;
	
	printf("%.2lf",(tmp*0.65-1)*2);

    return 0;
}
*/

int main()
{
    char c;
    float odd, maxodd, maxprofit = 1;

    for(int i = 0; i < 3; i++)
    {
        maxodd = 0;
        for(int j = 0; j < 3; j++)
        {
            scanf("%f", &odd);
            if(maxodd < odd)
            {
                maxodd = odd;
                c = "WTL"[j];
            }
        }
        printf("%c ", c);
        maxprofit *= maxodd;
    }
    printf("%.2f", (maxprofit * 0.65 - 1) * 2);

    return 0;
}
