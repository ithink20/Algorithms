#include <stdio.h>
#include <stdbool.h>

int N, M;

void calculateNeed(int Need[N][M], int max[N][M], int alloc[N][M]) {
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            Need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Need : \n");
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int avail[], int max[N][M], int alloc[N][M]) {
    int Need[N][M];
    calculateNeed(Need, max, alloc);
    int finish[N];
    for (int i = 0 ; i < N; ++i) {
        finish[i] = 0;
    }
    int safeseq[N];
    int work[M];
    for (int i = 0; i < M; ++i) {
        work[i] = avail[i];
    }
    int count = 0;
    bool found;
    while (count < N) {
        found = false;
        for (int i = 0; i < N; ++i) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < M; ++j) {
                    if (Need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == M) {
                    for (int k = 0; k < M; ++k) {
                        work[k] += alloc[i][k];
                    }
                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
    }
    if (found == false) {
        printf("Not in safe mode!\n");
        return false;
    }
    printf("system is in safe mode!\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", safeseq[i]);
    }
    printf("\n");
    return true;
}

int main() {
    printf("Enter no. of process and resource_type: ");
    scanf("%d%d", &N, &M);
    int P[N];
    for (int i = 0; i < N; ++i) {
        P[i] = i;
    }
    int avail[M];
    printf("Enter available : \n");
    for (int i = 0; i < M; ++i) {
        scanf("%d", &avail[i]);
    }
    int max[N][M];
    printf("Enter MAX : \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &max[i][j]);
        }
    }
    int alloc[N][M];
    printf("Enter Allocation : \n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &alloc[i][j]);
        }
    }
    isSafe(avail, max, alloc);
    return 0;
}