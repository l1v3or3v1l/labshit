#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
	int i, j;
	int allocation[n];
	for (i = 0; i < n; i++) {
		allocation[i] = -1;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (blockSize[j] >= processSize[i]) {
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}

	printf("\nProcess No.\t\tProcess Size\t\tBlock No.\n");
	for (i = 0; i < n; i++) {
		printf("%d\t\t\t", i+1);
		printf("%d\t\t\t\t", processSize[i]);
		if (allocation[i] != 1) {
			printf("%d", allocation[i] + 1);
		} else {
			printf("Not Allocated");
		}
		printf("\n");
	}
}

int main() {
	int m, n, i, processSize[20];
	printf("Enter the number of block : \n");
	scanf("%d", &m);
	int blockSize[m];
	printf("Enter the size of each block : \n");
	for (i = 0; i < m; i++) {
		scanf("%d", &blockSize[i]);
	}
	printf("Enter the no of processes : \n");
	scanf("%d", &n);
	int processSize[n];
	printf("Enter the size of processes: \n");
	for (i = 0; i < n; i++) {
		scanf("%d", &processSize[i]);
	}
	firstFit(blockSize, m, processSize, n);
}