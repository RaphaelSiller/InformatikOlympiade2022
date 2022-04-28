#include <stdio.h>
#include <assert.h>
#include <vector>

int gioca(int N, int M) {
    std::vector<std::vector<bool>> field;

	//create field
	field.assign(N, {});
	for (int i = 0; i < N; i++) {
		field[i].assign(M, false);
		field[i].shrink_to_fit();
	}
	field.shrink_to_fit();
	
	//for every field, see if an X is possible, if yes increase ret
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] = isXPossible(i, j, field)) {
				ret++;
			}
		}
	}
	

    return 42;
}

bool isXPossible(int x, int y, std::vector<std::vector<bool>> field) {
	//switch Case if over field
	
}

int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}