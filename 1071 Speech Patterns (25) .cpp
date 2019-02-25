#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

char ch;
vector<char> input;
map<string, int> mp;

bool yes(int i){
	if(input[i]>='A' && input[i]<='Z'){
		input[i] = input[i]-'A' + 'a';
		return true;
	}
	else if(input[i]>='a' && input[i]<='z')
		return true;
	else if(input[i]>='0' && input[i]<='9')
		return true;
	return false;
}

int main(){

	int i, len, st, end, maxn;
	maxn = INT_MIN;

	while(scanf("%c",&ch)){
		input.push_back(ch);
		if(ch=='\n')
			break;
	}

	len = input.size();
	st = 0, end = 0;
	vector<char>::iterator ite = input.begin();

	for(i = 0; i < len; i++){
		if( yes(i) ){
			end++;
			continue;
		}

		if(st < end){
			string s(ite+st, ite+end);
			mp[s]++;
			if(mp[s] > maxn)
				maxn = mp[s];
			end++;
			st = end;
			continue;
		}

		st = end = i+1;

	}

	map<string,int>::iterator itm = mp.begin();

	for(; itm!=mp.end(); itm++){
		if(itm->second==maxn){
			cout<<itm->first<<" "<<itm->second<<endl;
			break;
		}
	}
	return 0;
}
