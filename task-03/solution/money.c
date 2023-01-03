#include <stdio.h>

int main()
{
    int n, m, count = 0;
    scanf("%d%d", &n, &m);
    if (m > n)
        printf("-1");
    else
    {
        while(n > 0)
        {
            if(n >= 2)
            {
                count++;
                n -= 2;
            }
            else
            {
                count++;
                n -= 1;
            }
        }
        if(count % m == 0)
            printf("%d", count);
        else
            printf("-1");
    }
    return 0;
