#define MAX_RANGE 5000
#define MAX_NUM 100

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
	if (argc < 3) { printf("generate_matrix [destination filename] [# of test cases]\n"); exit(1); }

	FILE *fp; char buf[100];
	int n, m, o;

	srand(time(NULL));
	fp = fopen(argv[1], "w");
	unsigned int test_cases = atoi(argv[2]);
	fprintf(fp, "%d\n", test_cases);

	while (test_cases--) {
		fprintf(fp, "%d, %d, %d\n", n = (rand() % MAX_RANGE) + 1, o = (rand() % MAX_RANGE) + 1, m = (rand() % MAX_RANGE) + 1);
		for (int i = 0; i < n; i++) for (int j = 0; j < o; j++) fprintf(fp, "%d\n", rand() % MAX_NUM);
		for (int i = 0; i < o; i++) for (int j = 0; j < m; j++) fprintf(fp, "%d\n", rand() % MAX_NUM);
	}

	return 0;
}
