int quadri(int N, long long M, int V[]) {
    int B = N;
    bool isOverLimit = true;
    while (isOverLimit) {
        //Cycle through every starting point
        for (int i = 0; i <= N-B; i++) {
            //Count all prizes
            long long somma = 0;
            for (int j = 0; j < B; j++) {
                somma += V[i+j];
            }
            if(somma < M) {
                isOverLimit = false;
                i = N+1;
            }
        }
        
    }

    return B;
}
