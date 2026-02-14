#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);
    int log1[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &m);
    int log2[m];

    for(int i = 0; i < m; i++) {
        scanf("%d", &log2[i]);
    }

    int merged[n + m];

    int i = 0, j = 0, k = 0;

    // Merge both logs
    while(i < n && j < m) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements
    while(i < n) {
        merged[k++] = log1[i++];
    }

    while(j < m) {
        merged[k++] = log2[j++];
    }

    // Print merged log
    for(int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
