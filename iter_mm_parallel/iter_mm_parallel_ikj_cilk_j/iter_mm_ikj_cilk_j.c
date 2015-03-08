#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define msize 4096
#include<time.h>
#include<cilk/cilk.h>
int main() {

        int i, j, k, sum = 0;
        int a[msize][msize], b[msize][msize], res[msize][msize] = {{0}};
	// make the two matrices.
	for (i = 0; i < msize; i++ ) {
                for (j = 0; j < msize; j++) {
                        a[i][j] = rand() % INT_MAX;
                        b[i][j] = rand() % INT_MAX;
                }
        }
	//multiple the matrices
	time_t start = time(NULL);
	for ( i = 0; i < msize; i++) {
		for ( k = 0; k < msize; k++) {
			cilk_for ( j = 0; j < msize; j++) {
				res[i][j] = res[i][j]+ (a[i][k] * b[k][j]);
			}
			//res[i][j] = sum;
			//sum = 0;
		}
	}
        printf("Time taken : %.2f\n", (double)(time(NULL) - start));
	return 0;
}
