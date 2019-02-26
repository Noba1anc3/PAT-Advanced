#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, i;    
    deque<int> a, b;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        b.push_back(t);
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    int sum;

    while (!a.empty() && !b.empty()) {
        if (a.front() * b.front() > 0) {
            sum += a.front() * b.front();
            a.pop_front();
            b.pop_front();
        } 
		else 
			break;
    }

    while (!a.empty() && !b.empty()) {
        if (a.back() * b.back() > 0) {
            sum += a.back() * b.back();
            a.pop_back();
            b.pop_back();
        } 
		else 
			break;
    }

    printf("%d\n", sum);

    return 0;
}
