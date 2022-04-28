#include <stdio.h>
#include <assert.h>

double scosse(int N) {
	fprintf(stderr, "Test\n");
    //calculation how many different ways
	int faculty[(N-1)];
	faculty[0] = 1;
	for (int i = 1; i < N-1; i++) {
		faculty[i] = faculty[i-1] * (i+1);
	}
    int nWays = faculty[N-1];
    
    //Calculation of all shocks from all paths combined
    int nAllShocks = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j <= i; j++) {
            nAllShocks += (nWays/(i+1)) * j;
        }
    }
    

	return nAllShocks / nWays;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%.6f\n", scosse(N));
    fclose(fr);
    fclose(fw);
    return 0;
}