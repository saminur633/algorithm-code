
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define len1 4
#define len2 5

int max(int a, int b){
	return (a > b)? a : b;
}

int lcs(char X[], char Y[]){

	int m = len1, n = len2;
	int P[m+1][n+1];
	for (int i = 0; i<=m; i++){
		for (int j = 0; j<=n; j++){
			if (i == 0 || j == 0){
				P[i][j] = 0;
			}
			else if (X[i] == Y[j]){
				P[i][j] = 1 + P[i-1][j-1];
			}
			else {
				P[i][j] = max(P[i-1][j], P[i][j-1]);
			}
		}
	}
		
	return P[m][n];
}

int main()
{

    char X[] = "BDCB";
    char Y[] = "BACDB";

    printf ("Length of LCS is: %d", lcs(X, Y)); 		
    return 0;
}
