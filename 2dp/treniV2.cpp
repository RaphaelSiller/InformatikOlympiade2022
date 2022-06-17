    int tempo_massimo(int N, int A[], int B[]){
	if (N == 1) return A[0] >= B[0] ? A[0] : B[0];
	
	A[0] = A[0] >= B[0] ? A[0] : B[0];
	
	if(B[1] > A[0] + A[1])
		A[1] = B[1];
	else
		A[1] = A[0] + A[1];
	
	for (int i = 2; i < N; i++) {
		//Better choice train from array B
		if ((A[i-2] + B[i]) > (A[i-1] + A[i])) {
			A[i] = A[i-2] + B[i];
		} else {
			A[i] = A[i-1] + A[i];
		}
		
	}
	return A[N-1];
}