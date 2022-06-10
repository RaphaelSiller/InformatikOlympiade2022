#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

// Needed for qsort
typedef int CmpFunType(const void *, const void *);
int CmpFun(const long long *v1, const long long *v2) {
	return (*v1 > *v2) - (*v2 > *v1);
}

long long P[MAXN], count[MAXN];
int main() {
	FILE *fr, *fw;
	int N, K, i, j;
	long long r;

	// Reading Input
	fr = fopen("input.txt", "r");
	fw = fopen("output.txt", "w");
	assert(2 == fscanf(fr, "%d %d", &N, &K));
	for (i = 0; i < N; i++)
		assert(1 == fscanf(fr, "%llu", &P[i]));

	// Sort the array from min to max
	qsort(P, N, sizeof(long long), (CmpFunType *)CmpFun);

	//Compare pairs and keep the ones closer to K
	for (i = 0; i < N; ++i) {
		count[i] = P[i];
		for (j = 0; j < i; ++j) {
			if (count[i] < K) {
				if (count[i] < count[j] + P[i])
					count[i] = count[j] + P[i];
			}
			else {
				if (count[j] + P[i] >= K && count[j] + P[i] < count[i])
					count[i] = count[j] + P[i];
			}
		}
	}

	//Look for the smallest number above K
	r = __LONG_LONG_MAX__;
	for (i = 0; i < N; ++i) {
		if (count[i] >= K && count[i] < r)
			r = count[i];
	}
	fprintf(fw, "%llu\n", r);
	fclose(fr);
	fclose(fw);
	return 0;
}