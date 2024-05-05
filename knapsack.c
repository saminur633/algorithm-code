#include <stdio.h>

int W = 5;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int n, int wt[], int val[], int select[]) {
    int P[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                P[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                P[i][w] = max(val[i - 1] + P[i - 1][w - wt[i - 1]], P[i - 1][w]);
            } else {
                P[i][w] = P[i - 1][w];
            }
        }
    }

    int i = n;
    int w = W;
    while (i > 0 && w > 0) {
        if (P[i][w] != P[i - 1][w]) {
            select[i - 1] = val[i - 1];
            w = w - wt[i - 1];
        }
        i--;
    }

    return P[n][W];
}

int main() {
	int n;
	scanf("%d", &n);
    int val[n];
    int wt[n];
	for (int i = 0; i<n; i++){
   		scanf("%d %d", &wt[i], &val[i]);
	} 

    int select[n];
    for (int i = 0; i < n; i++) {
        select[i] = 0;
    }

    int maxProfit = knapSack(n, wt, val, select);

    printf("Maximum Profit = %d\n", maxProfit);
    printf("Item choice: ");
    for (int i = 0; i < n; i++) {
        if((select[i]) != 0){
			printf("%d ", select[i]);
		}
    }
    printf("\n");
    return 0;
}