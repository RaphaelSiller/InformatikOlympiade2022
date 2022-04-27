#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    // Look when a carnet is better than single tickets
    int carnetIsBetter = 1;
    int price = 0;
    while (A * carnetIsBetter <= B) {
        carnetIsBetter++;
    }

    //until all trips are paid
    while (N > 0) {
        //When a carnet is better than single tickets
        if (carnetIsBetter <= M && (N >= carnetIsBetter || A > B)) {
            price += B;
            N -= M;
        } else {
            price += A;
            N--;
        }
    }

    return price;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
