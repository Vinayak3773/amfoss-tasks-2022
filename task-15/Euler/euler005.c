#include<stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int LCM = 1;
        for (int i = 2; i <= N; i++)
        {
            int temp = i;
            while (temp % LCM != 0)
            {
                temp += i;
            }

            LCM = temp;
        }

        printf("%d\n", LCM);
    }

    return 0;
