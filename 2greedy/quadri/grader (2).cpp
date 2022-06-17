#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define n 1000

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

int quadri(int N, long long M, int V[]);

int quadri(int N, long long M, int V[]) {
    int a = 0,biggestPossibleGroup = N;
    int massimo = 0;
    while (a<=biggestPossibleGroup) {
        int range = (a+biggestPossibleGroup)/2;
        bool controllo = true;
        long long int somma = 0;
        for(int i = 0; i < range; i++) {
            somma+=V[i];
        }

        if(somma > M) 
			controllo = false;
		
		for(int i = range; i < N; i++) {
			somma-=V[i-range];
			somma+=V[i];
			if(somma > M) 
				controllo = false;
		}

        if(controllo) {
           massimo = max(range,massimo);
           a = range+1;
        }

        else {
            biggestPossibleGroup = range-1;
        }
    }
    return massimo;
}

int main() {
	fr = stdin;
	fw = stdout;

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