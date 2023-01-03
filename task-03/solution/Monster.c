#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }

        if (a[n-1] > 0)
        {
            printf("NO\n");
            continue;
        }

        int flag = 1;
        for (int j = n-2; j >= 0; j--)
        {
            if (a[j] > 0)
            {
                if (a[j+1] > 0)
                {
                    printf("NO\n");
                    flag = 0;
                    break;
                }
                else if (a[j] - a[j+1] >= 0)
                {
                    a[j] -= a[j+1];
                }
                else
                {
                    printf("NO\n");
                    flag = 0;
                    break;
                }
            }
        }
        
        if (flag)
        {
            printf("YES\n");
        }
    }
    return 0;
}
