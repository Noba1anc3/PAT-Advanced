
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int i = 0;
	char c, doub[21];
	double in = 0;
	vector<int> check, doubl;
	vector<int>:: iterator iti;
	vector<char> input;
	vector<char>::iterator itc;
  
 	for(;i<21;i++)
    		doub[i] = 'a';
  	i = 0;
  
	while((c = getchar()) != '\n')
		input.push_back(c);

	for(itc = input.begin(); itc != input.end(); itc++){
		in += (*(itc) - 48) * pow(10, input.size() - 1 - i);
		check.push_back(*(itc) - 48);
		i++;
	}

	in *= 2;
	sprintf(doub, "%lf", in);

	for(i = 0; doub[i] >=48 && doub[i] <= 57 ; i++)
		doubl.push_back(doub[i] - 48);

	sort(doubl.begin(), doubl.end());
	doubl.erase(unique(doubl.begin(), doubl.end()), doubl.end());

	sort(check.begin(), check.end());
	check.erase(unique(check.begin(), check.end()), check.end());

	if(doubl == check)
		cout<<"Yes"<<'\n';
	else
		cout<<"No"<<'\n';

	printf("%.0lf\n", in);

	return 0;

}
