
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct stu
{
    char ID[14];
    int score, loc_ID, loc_rank, global_rank;
};

bool cmp(stu s1, stu s2)
{   /* 按照分数降序排序，如果分数相同，按照学号升序排序 */
    return s1.score == s2.score ? strcmp(s1.ID, s2.ID) < 0 : s1.score > s2.score;
}

int main()
{
    int N, K, idx = 0, sum = 0, temp;
	stu S[30005];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        sum += K;
        temp = idx;     /* 记录开始时的下标 */

        for (int j = 0; j < K; j++)
        {   
            scanf("%s %d", S[idx].ID, &S[idx].score);
            S[idx].loc_ID = i + 1;
            idx++;
        }

        sort(S+temp, S+temp+K, cmp);

        S[temp].loc_rank = 1;   /* 先给每个考场第一位同学排序 */
        for (int m = temp + 1; m < temp + K; m++)   /* 给每个考场的学生排序 */
            if (S[m].score == S[m-1].score)
                S[m].loc_rank = S[m-1].loc_rank;
            else
                S[m].loc_rank = m - temp + 1;   
    }

    sort(S, S+idx, cmp);
    printf("%d\n", sum);
    printf("%s %d %d %d\n", S[0].ID, 1, S[0].loc_ID, 1); 
	S[0].global_rank = 1;

    for (int i = 1; i < sum; i++)
        if (S[i].score == S[i-1].score)
        {   /* 如果与前面同学的总分相同 */
            S[i].global_rank = S[i-1].global_rank;
            printf("%s %d %d %d\n", S[i].ID, S[i].global_rank, S[i].loc_ID, S[i].loc_rank);
        }
        else
        {   /* 如果与前面同学总分不同，那么肯定就低于前面同学的分数 */
            S[i].global_rank = i+1;
            printf("%s %d %d %d\n", S[i].ID, S[i].global_rank, S[i].loc_ID, S[i].loc_rank);
        }

    return 0;
}
