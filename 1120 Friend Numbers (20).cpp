#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int i, n, in = 0;
	char c, input[4] = {'0', '0', '0', '0'};

	vector<int> vec;
	vector<int>::iterator it;

	scanf("%d\n", &n);

	for(i = 0; i < n; i++){
		while((c = getchar()) != ' '){
			if(c == '\n')
				break;
			input[in++] = c;
		}

		int tmp = input[0] + input[1] + input[2] + input[3] - 48*4;
		in = 0;
		input[0] = '0'; 
		input[1] = '0';
		input[2] = '0';
		input[3] = '0'; 
		if(tmp != 0)
			vec.push_back(tmp);

	}
	
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(),vec.end()), vec.end()); 

	printf("%d\n", vec.size());
	printf("%d", *(vec.begin()));
	for(it = vec.begin() + 1; it != vec.end(); it++)
		printf(" %d", *(it));
	
    return 0;
}
