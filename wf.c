#include <stdio.h>

void sort(int a[], int b[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
}

int main() {
	int n, np, i, j, k;
	printf("Enter no of memory blocks : ");
	scanf("%d", &n);
	int bs[n], bi[n];
	printf("Enter size of memory blocks : \n");
	for (i = 0; i < n; i++) {
		scanf("%d", &bs[i]);
	}
	printf("Enter no of processes : ");
	scanf("%d", &np);
	int ps[np], p[np];
	printf("Enter size of processes : \n");
	for (i = 0; i < np; i++) {
		scanf("%d", &ps[i]);
	}
	for (i = 0; i < n; i++) {
		bi[i] = i;
	}
	sort(bs, bi, n);
	for(j = 0; j < np; j++) {
		k = 0;
		for (i = 0; i < n; i++) {
			if (ps[j] <= bs[i]) {
				bs[i] -= ps[j];
				p[j] = bi[i]+1;
				k = 1;
				break;
			}
		}
		if (k == 0) {
			p[j] = -1;
		}
	}
	printf("PID\tBID\n");
	for(i = 0; i < np; i++) {
		if(p[i] == -1) {
			printf("P[%d]\tN/A\n", i+1);
		} else {
			printf("P[%d]\t%d\n", i+1, p[i]);
		}
	}
}