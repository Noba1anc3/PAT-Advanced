#include <stdio.h>

int main()
{
	int g1, s1, k1, g2, s2, k2;
	int kin, krem, sin, srem;

	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);

	int tmpk = k1 + k2;
	kin = tmpk / 29;
	krem = tmpk % 29;
	int tmps = s1 + s2 + kin;
	sin = tmps / 17;
	srem = tmps % 17;
	printf("%d.%d.%d", g1 + g2 + sin, srem, krem);

    return 0;
}
