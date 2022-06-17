#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int* messaggio;
static char* plaintext;

// Declaring functions
void decifra(int N, int d, int L, int* messaggio, char* plaintext);
long long fastModularExponentation( int C, int a, int n);

int main() {
	fr = stdin;
	fw = stdout;
	// Iterators used in for loops
	int i0;

	// Reading input
    fscanf(fr, "%d %d %d", &N, &d, &L);
	messaggio = (int*)malloc(100 * sizeof(int));
	plaintext = (char*)malloc(110 * sizeof(char));
	for (i0 = 0; i0 < L; i0++)
            fscanf(fr, "%d", &messaggio[i0]);

	// Calling functions
	decifra(N, d, L, messaggio, plaintext);

	// Writing output
        fprintf(fw, "%s\n", plaintext);
	
	fclose(fr);
	fclose(fw);
	return 0;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
	for (int i = 0; i < L; i++) {
	plaintext[i] = fastModularExponentation(N, messaggio[i], d);
	}
}

/**
 * @brief uses following formula:
 * 	
 * 	a^(2n+1) %C = a * (a^2n) %C		and
 *  a^2n %C = (a^n)^2 %C
 * 
 * @param C 
 * @param a 
 * @param n 
 * @return long long 
 */
long long fastModularExponentation( int C, int a, int n) {
	if (n==0) // n pow 0 = 1
		return 1; 
	
	if(n==1)
		return a%C; // n pow 1 = n

	long long half = fastModularExponentation(C, a, n/2);
	long long ret = (half * half) % C;
	if(n%2)
		ret = (ret*a)%C;
	return ret;
}