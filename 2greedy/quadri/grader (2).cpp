#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
int quadri(int N, long long M, int* V);

int main() {
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);
	
	fclose(fr);
	fclose(fw);
	return 0;
}

int quadri(int N, long long M, int V[]) {
    int B = 0;
    bool isUnderLimit = true;
    while (isUnderLimit && B <= N) {
        //Cycle through every starting point
        for (int i = 0; i <= N-B; i++) {
            //Count all prices
            long long somma = 0;
            for (int j = 0; j < B; j++) {
                somma += V[i+j];
            }
            if(somma > M) {
                isUnderLimit = false;
                i = N+1;
				B--;
            }
        }
        B++;
    }
    return B;
}