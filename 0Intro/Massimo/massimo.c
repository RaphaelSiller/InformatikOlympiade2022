int trova_massimo(int N, int V[]) {
int massimo = V[0];

    for (int i = 1; i < N; i++){
        if(V[i] > massimo) {
            massimo = V[i];
        }
    }
    

    return massimo;
}
