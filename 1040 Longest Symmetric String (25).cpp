#include <bits/stdc++.h>
using namespace std;

int main(){
    int maxLen=0;
    string s;
    getline(cin,s);
    for(int i = 0; i < s.size(); i++){
        int j;
        for(j = 1; i - j >= 0 && i + j < s.size() && s[i+j] == s[i-j]; j++)//以当前字符为回文中心查找最长回文子串 
		;
	maxLen = max(maxLen, 2*j-1);//更新回文子串最大长度
        for(j = 0; i - j >= 0 && i + j + 1 < s.size() && s[i+j+1] == s[i-j]; j++)//以当前字符为回文中心左侧字符查找最长回文子串
		;
        maxLen=max(maxLen, 2*j);//更新回文子串最大长度
    }
    printf("%d",maxLen);
    return 0;
}
