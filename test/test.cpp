#include <stdio.h>

int main(void) {
	int N = 4;
	int faculty[N];
	faculty[0] = 1;
	for (int i = 1; i < N; i++){
		printf("%i\n", faculty[i] = faculty[i-1] * i);
	}	
}