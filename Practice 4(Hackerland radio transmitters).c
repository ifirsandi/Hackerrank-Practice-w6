https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Transmit 1
#define NotTrans 0

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int ar[n];
    scanf("%d", &ar[0]);
    //ar[0][1]=NotTrans;
    for(int i=1; i<n; i++){
        scanf("%d", &ar[i]);
        //ar[i][1]=NotTrans;
        for (int j=i; j>-1;j--){
            if (ar[j]>ar[i]){
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    /*for (int i=0; i<n; i++){
        printf("%d", ar[i]);
    }*/
    int count=0;
    int p=0;
    int radio;
    for (int i=0; i<n; i++){
        int trans =ar[i]+k;
        for(int j=i; ar[j]<=trans; j++){
            radio=ar[j];
            p=j;
        }
        trans = radio + k;
        for(int j=p; ar[j]<=trans; j++){
            radio=ar[j];
            p=j;
        }
        count++;
        i=p;
    }
    printf("%d", count);

    return 0;
}


