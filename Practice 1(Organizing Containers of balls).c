https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int q;
    scanf("%d", &q);
    for (int queries=0; queries<q; queries++){
        int n;
        scanf("%d", &n);
        int ar[n+1][n+1];
        for (int i=0; i<n+1; i++){
            ar[n][i]=0;
            ar[i][n]=0;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                scanf("%d", &ar[i][j]);
                ar[i][n]=ar[i][n]+ar[i][j];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                ar[n][i]=ar[n][i]+ar[j][i];
            }
        }
        /*for (int i=0; i<n+1; i++){
            for (int j=0; j<n+1; j++){
                printf("%d ", ar[i][j]);
            }
            printf("\n");
        }*/
        //int a=ispossible(ar, n);

    int right=0;
    for (int i=0; i<=n;i++){
        for (int j=0; j<=n; j++){
            if (ar[n][i]==ar[j][n]){
                ar[n][i]=0;
                break;
            }
        }
        right=right+ar[n][i];
    }
    if (right==0){
        printf ("Possible\n");
    } else {
        printf ("Impossible\n");
    }
        /*if (a==1){
            printf ("Possible\n");
        }    else {
            printf("Impossible\n");
        }*/
        //printf("/******/\n");


    }

    return 0;
}


