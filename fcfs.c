#include <stdio.h>
int n,b[20],w[20],t[20],i;
float avgt=0,avgtat=0;
int main() {
	printf("Enter no of processes:\n");
	scanf("%d",&n);
	printf("Enter the burst time of each processes : \n");
	for (i=0;i<n;i++) {
		printf("p[%d]=", i+1);
		scanf("%d", &b[i]);
	}
	w[0] = 0;
	t[0] = b[0];
	avgtat = t[0];
	for (int i = 1; i < n; i++) {
		w[i] = t[i-1];
		t[i] = w[i] + b[i];
		avgt += w[i];
		avgtat += t[i];
	}
	printf("process\tbtime\twtime\tttime\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", i+1, b[i], w[i], t[i]);
	}
	printf("average waiting time = %f\n", avgt/n);
	printf("average turnaround time = %f", avgtat/n);	
}