#include <stdio.h>
int n,p[20],b[20],w[20],t[20],temp,pr[20],i;
float avgt=0,avgtat=0;
int main() {
	printf("Enter no of processes:\n");
	scanf("%d",&n);
	printf("Enter the burst time and priority of each processes : \n");
	for (i=0;i<n;i++) {
		printf("p[%d]=", i+1);
		scanf("%d %d", &b[i], &pr[i]);
		p[i] = i+1;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i -1; j++){
			if (pr[j] > pr[j+1]) {
				temp = pr[j];
				pr[j] = pr[j+1];
				pr[j+1] = temp;
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
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
		printf("%d\t%d\t%d\t%d\n", p[i], b[i], w[i], t[i]);
	}
	printf("average waiting time = %f\n", avgt/n);
	printf("average turnaround time = %f", avgtat/n);	
}