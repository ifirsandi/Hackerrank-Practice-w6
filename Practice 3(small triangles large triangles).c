https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
  
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
        float p = tr[i].a; float q = tr[i].b; float r=tr[i].c;
        float x = tr[j].a; float y = tr[j].b; float z=tr[j].c;
        float p1 = (p+q+r)/2;
        float p2 = (x+y+z)/2; 
        float s1 = sqrt(p1*(p1-p)*(p1-q)*(p1-r));
        float s2 = sqrt(p2*(p2-x)*(p2-y)*(p2-z));
        //printf ("(%f %f)=> %d(%d,%d,%d)\n", s1, p1,i,p,q,r);
        if (s1>s2){
            triangle temp; 
            temp = tr[i]; 
            tr[i] = tr[j]; 
            tr[j] = temp;
        } 
    }
    }
    return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
