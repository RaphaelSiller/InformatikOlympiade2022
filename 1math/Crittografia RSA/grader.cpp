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

// int fastModularExponentation(int N, int d) {
// 	if(d > 0) {
// 		if (d % 2) { //
// 			return N * fastModularExponentation(N, d-1);
// 		} else {
// 			int l = fastModularExponentation(N, d/2);
// 			return l*l;
// 		}
		
// 	} else { //Exit
// 		return 1;
// 	}
// }

#include <vector>
void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
	for (int i = 0; i < L; i++) {
		// plaintext[i] = fastModularExponentation(N, d);
		int modulo = N;
		std::vector<bool> isHalvedOrMinusOne;
		int indexOfHalved = 0;
		int dClone = d;
		while (dClone > 0) {
			if (dClone % 2)
			{
				isHalvedOrMinusOne.insert(isHalvedOrMinusOne.begin(), false);
				dClone--;
			} else {
				isHalvedOrMinusOne.insert(isHalvedOrMinusOne.begin(), true);
				dClone/=2;
			}
		}
		
		for (int j = 0; j < isHalvedOrMinusOne.size(); j++) {
			if (isHalvedOrMinusOne[j]) {
				modulo = (modulo * modulo) % d;
			} else {
				modulo = (N * modulo) % d;
			}
		}
		plaintext[i] = modulo;
	}
}
