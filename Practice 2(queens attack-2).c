https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int n, p;
    scanf ("%d %d", &n, &p);
    int r_q, c_q;
    int ces[n+1][n+1];
    scanf("%d %d", &r_q, &c_q);
    for (int i=0; i<n+1; i++){
        for (int j=0; j<n+1; j++){
            if (i==0 || j== 0){
                ces[i][j]=5;
            } else {
                ces[i][j]=0;
            }
        }
    }
    ces[r_q][c_q]=9;
    for (int i=0; i<p; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        ces[a][b]=1;
    }
    /*for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            printf("%d ", ces[i][j]);
        }
        printf("\n");
    }*/
    int count=0;
    //north
    int north=0;
    for (int i=1; i+r_q<n+1; i++){
        if (ces[r_q+i][c_q]==0){
            north++;
        } else { break;}
    }
    //norh-east
    int ne=0;
    for (int i=1; i>0; i++){
        if (r_q+i>n || c_q+i>n){
            break;
        } else if (ces[r_q+i][c_q+i] == 0){
            ne++;
        } else {break;}
    }
    //east
    int east=0;
    for (int i=1; c_q+i<n+1; i++){
        if (ces[r_q][c_q+i]==0){
            east++;
        } else { break;}
    }
    //south-east
    int se=0;
    for (int i=1; i>0; i++){
        if (r_q-i>n || c_q+i>n){
            break;
        } else if (ces[r_q-i][c_q+i] == 0){
            se++;
        } else {break;}
    }
    //south
    int south=0;
    for (int i=1; r_q-i<n+1; i++){
        if (ces[r_q-i][c_q]==0){
            //printf("kolom (%d,%d)\n",r_q-i, c_q);
            south++;
        } else { break;}
    }
    //south-west
    int sw=0;
    for (int i=1; i>0; i++){
        if (r_q-i>n || c_q-i>n){
            break;
        } else if (ces[r_q-i][c_q-i] == 0){
            sw++;
            //printf("kolom (%d,%d)\n",r_q-i, c_q);
        } else {break;}
    }
    //west
    int west=0;
    for (int i=1; c_q-i<n+1; i++){
        if (ces[r_q][c_q-i]==0){
            west++;
        } else { break;}
    }
    //north-west
    int nw=0;
    for (int i=1; i>0; i++){
        if (r_q+i>n || c_q-i>n){
            break;
        } else if (ces[r_q+i][c_q-i] == 0){
            nw++;
        } else {break;}
    }
    /*
    printf("north = %d\n", north);
    printf("north-east = %d\n", ne);
    printf("east = %d\n", east);
    printf("south-east = %d\n", se);
    printf("south = %d\n", south);
    printf("south-west = %d\n", sw);
    printf("west = %d\n", west);
    printf("north-west = %d\n", nw);
    */
    printf("%d", north+ne+east+se+south+sw+west+nw);


    return 0;
}


