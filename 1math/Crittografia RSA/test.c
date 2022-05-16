void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
	for (int i = 0; i < L; i++) {
		long int inputIntoArray = 1;
		for (int j = 0; j < d; j++) {
			inputIntoArray = (inputIntoArray%N * messaggio[i]%N) % N;
		}
		plaintext[i] = inputIntoArray;
	}
}