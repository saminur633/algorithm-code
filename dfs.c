#include <stdio.h>

char c[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int e[8] = {2, 3, 1, 2, 1, 3, 1, 1};
int list[8][3] = {{4,5}, {0, 2, 3}, {0}, {6, 7}, {1}, {1, 4, 7}, {4}, {6}};
int checked[20];
int stk[20];
int start[8];
int finish[8];
int top = 0;
int timeStamp = 1;

void push(int n) {
    checked[n] = 1;
    start[n] = timeStamp++;
    printf("(start: %d) %c   \n", start[n], c[n]);
    stk[top++] = n;
}

int pop() {
    finish[stk[top - 1]] = timeStamp++;
    printf("(end: %d) %c   \n", finish[stk[top - 1]],c[stk[top - 1]]);
    top--;
    return stk[top];
}

int notChecked(int n) {
    return (checked[n] == 0);
}

int main() {
    int i, n, f = 0;
    printf("\nStart and End  time stamp: \n");

    push(0);

    while (top != 0) {
        n = stk[top - 1];
        for (i = 0; i < e[n]; i++) {
            f = 0;
            if (notChecked(list[n][i])) {
                push(list[n][i]);
                f = 1;
                break;
            }
        }
        if (f == 0) {
            pop();
        }
    }

    return 0;
}