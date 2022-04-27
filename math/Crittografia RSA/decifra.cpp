#include <math.h>
void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
	for (int i = 0; i < L; i++)
	{
		plaintext[i] = (int)pow(messaggio[i], d) % N; 
	}
	
}