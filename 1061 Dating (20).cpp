#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
   	int i;
	string stra,strb,strc,strd;
	cin>>stra>>strb>>strc>>strd;

	for(i = 0; stra[i] != '\0' && strb[i] != '\0'; i++){
       		if(stra[i] == strb[i] && ('A' <= stra[i] && stra[i] <= 'G')){
             		if(stra[i]=='A')  
				cout<<"MON"<<" ";
             		else if(stra[i]=='B') 
				cout<<"TUE"<<" "; 
            		else if(stra[i]=='C')  
				cout<<"WED"<<" ";
			else if(stra[i]=='D') 
				cout<<"THU"<<" ";
			else if(stra[i]=='E')  
				cout<<"FRI"<<" ";
			else if(stra[i]=='F')  
				cout<<"SAT"<<" ";
			else if(stra[i]=='G')  
				cout<<"SUN"<<" ";
			i++;
             		break;                                                  
       		}                                      
   	}

   	for(;stra[i] != '\0' && strb[i] != '\0'; i++){
		if(stra[i] == strb[i] && ( isdigit(stra[i]) || ('A' <= stra[i] && stra[i] <= 'N') )){
			if('0' <= stra[i] && stra[i] <= '9') 
				cout<<"0"<<stra[i]<<":"; 
			else  
				cout<<((stra[i]-'A') + 10)<<":"; 
			break;                                                  
		}                                      
	}

   	for(i = 0; strc[i] != '\0' && strd[i] != '\0'; i++)
		if(strc[i] == strd[i] && isalpha(strc[i]))  
			break;                                   

   	if(i < 10) 
		cout<<"0"<<i<<endl;
   	else 
		cout<<i<<endl;

	return 0;
}
