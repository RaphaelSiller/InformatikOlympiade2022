#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string>
#include <math.h>

std::vector<int> possibleNumbers;

bool isPossibleNumber(int maybePossibleNumber);
int cabala(int M);

int occulta(int N, int M) {
    for (int maybePossibleNumber = pow(10, N)-1; maybePossibleNumber > 0; maybePossibleNumber-=3) {
        if(isPossibleNumber(maybePossibleNumber)) {
            possibleNumbers.push_back(maybePossibleNumber);
        }
    }
    
    return cabala(M);
}

bool isPossibleNumber(int maybePossibleNumber) {
    bool ret = true;
    std::string number = std::to_string(maybePossibleNumber);
    for (int i = 0; i < number.length(); i++) {
        if(number[i] != '3' && number[i] != '6' && number[i] != '9')
            ret = false;
    }
    if (ret) {
        for (int i = 0; i < number.length()-1; i++) {
            if (number[i] == number[i+1]) {
                ret = false;
                i = number.length();
            }
        }
    }
    return ret;
}

int cabala(int M) {
    int ret = possibleNumbers[0] % M;
    for (int i = 1; i < possibleNumbers.size(); i++) {
        if (possibleNumbers[i] % M > ret)
            ret = possibleNumbers[i] % M;
    }
    return ret;
}

int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%d ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}