#include<stdio.h>

char c[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'S'};
int e[8] = {2, 2, 2, 2, 2, 2, 3, 3};
int list[8][3] = {{3,7}, {4,7}, {5,7}, {0,6}, {1,6}, {2,6}, {3,4,5}, {0,1,2}};
int checked[20];
int que[20];
int first = 0;
int last = 0;

void enq(int n){
  checked[n] = 1;
  que[last++] = n; 
}

int dq(){
  printf("%c ", c[que[first]]);
  first++;
  return que[first - 1];
}

int notChecked(int n){
	if (checked[n] == 1){
		return 0;
	}
	return 1;
}

int main()
{
	int i, j, n;
	enq(7);
	
	while (first < last){
		n = dq();
		for (i = 0; i < e[n]; i++){
			if (notChecked(list[n][i]) == 1){
				enq(list[n][i]);
			}
		}
	}
}