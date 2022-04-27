#include <stdio.h>
#include <assert.h>

double scosse(int N) {
    double ret = 0;
	
	int faculty[N-1];
	faculty[0] = 1;
	for (int i = 1; i < N-1; i++) {
		faculty[i] = faculty[i-1] * (i+1);
	}
	
	for (int i = 0; i < N-1; i++) {
		ret += faculty[i];
	}
	

	return (ret / (N-1));
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