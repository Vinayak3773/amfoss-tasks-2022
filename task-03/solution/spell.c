#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    char a[m][11], b[m][11], c[n][11];
    int i, j;

    for(i=0; i<m; i++){
        scanf("%s%s", a[i], b[i]);
    }

    for(i=0; i<n; i++){
        scanf("%s", c[i]);
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(strcmp(c[i], a[j]) == 0){
                if(strlen(a[j]) < strlen(b[j]))
                    printf("%s ", a[j]);
                else
                    printf("%s ", b[j]);
            }
        }
    }

    return 0;
}
