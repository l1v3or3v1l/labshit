#include <stdio.h>

int main() {
	int at[20], bt[20], n, y, i, temp[20], sum, quant, count = 0;
	float twt=0, tat=0;
	printf("Enter no of processes : \n");
	scanf("%d", &n);
	y = n;
	printf("Enter arrival time and burst times of processes : \n");
	for (i = 0; i < n; i++) {
		printf("p[%d]=", i+1);
		scanf("%d %d", &at[i], &bt[i]);
		temp[i] = bt[i];
	}
	printf("Enter time quantum : \n");
	scanf("%d", &quant);
	printf("Process\tBT\tWt\tTat\n");
	for (sum = 0, i = 0; y != 0;) {
		if (temp[i] <= quant && temp[i] > 0) {
			sum += temp[i];
			temp[i] = 0;
			count = 1;
		}
		else if (temp[i] > 0) {
			sum += quant;
			temp[i] -= quant;
		}
		if (temp[i] == 0 && count == 1 ){
			y--;
			printf("%d\t%d\t%d\t%d\n", i+1, bt[i], sum-at[i]-bt[i], sum-at[i]);
			twt += sum-at[i]-bt[i];
			tat += sum-at[i];
			count = 0;
		}
		if (i == n-1) {
			i = 0;
		} else if (at[i+1] <= sum) {
			i++;
		} else {
			i=0;
		}
	}
	printf("average waiting time: %f\n", twt/n);
	printf("average turnaround time: %f\n", tat/n);	
}