#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct score{
	int ID;
	int virtue;
	int talent;
	int total;
};

bool cmp(score s1, score s2){
	if(s1.total > s2.total)
		return true;
	else if(s1.total == s2.total){
		if(s1.virtue > s2.virtue)
			return true;
		else if (s1.virtue == s2.virtue){
			if(s1.ID < s2.ID)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void prt(score scr[], int num);

int main()
{
	int num, L, H, i, pass;
	int s = 0, n = 0, f = 0, x = 0;
	score scr[100000], sages[100000], noblemen[100000], foolmen[100000], smallmen[100000];	
	scanf("%d %d %d", &num, &L, &H);
	pass = num;

	for(i = 0; i < num; i++){
		scanf("%d %d %d", &scr[i].ID, &scr[i].virtue, &scr[i].talent);
		if(scr[i].talent < L || scr[i].virtue < L){
			scr[i].ID = -1;
			pass--;
		}
		scr[i].total = scr[i].talent + scr[i].virtue;
	}
	
	for(i = 0; i < num; i++){

		if( scr[i].talent >= H && scr[i].virtue >= H && scr[i].ID != -1 ){
			sages[s].ID = scr[i].ID;
			sages[s].talent = scr[i].talent;
			sages[s].virtue = scr[i].virtue;
			sages[s++].total = scr[i].talent + scr[i].virtue;

		}
		else if( scr[i].talent < H && scr[i].virtue >= H && scr[i].ID != -1 ){
			noblemen[n].ID = scr[i].ID;
			noblemen[n].talent = scr[i].talent;
			noblemen[n].virtue = scr[i].virtue;
			noblemen[n++].total = scr[i].talent + scr[i].virtue;
		}
		else if( scr[i].talent < H && scr[i].virtue < H && scr[i].talent <= scr[i].virtue && scr[i].ID != -1 ){
			foolmen[f].ID = scr[i].ID;
			foolmen[f].talent = scr[i].talent;
			foolmen[f].virtue = scr[i].virtue;
			foolmen[f++].total = scr[i].talent + scr[i].virtue;
		}
		else if( scr[i].talent > scr[i].virtue && scr[i].ID != -1 ){
			smallmen[x].ID = scr[i].ID;
			smallmen[x].talent = scr[i].talent;
			smallmen[x].virtue = scr[i].virtue;
			smallmen[x++].total = scr[i].talent + scr[i].virtue;
		}
	}

	sort(sages, sages+s, cmp);
	sort(noblemen, noblemen+n, cmp);
	sort(foolmen, foolmen+f, cmp);
	sort(smallmen, smallmen+x, cmp);

	printf("%d\n", pass);

	prt(sages, s);
	prt(noblemen, n);
	prt(foolmen, f);
	prt(smallmen, x);

    return 0;

}

void prt(score scr[], int num){
	for(int i = 0; i < num; i++)
		printf("%d %d %d\n", scr[i].ID, scr[i].virtue, scr[i].talent);
}
