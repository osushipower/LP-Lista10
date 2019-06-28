#include <stdio.h>
 
void minMax(int *mn, int *mr, int vetor[100], int n) {
    int i;
    
    *mn = vetor[0];
    *mr = vetor[0];
    
    for (i = 0; i < n; i++) {
        if (vetor[i] >= *mr) {
            //printf("achei maior: %d\n", *mr);
            *mr = vetor[i];
        } else if (vetor[i] <= *mn) {
            //printf("achei menor: %d\n", *mn);
            *mn = vetor[i];
        }
    }
}
 
int main() {
    
    int vetor[100], n, i, min, max;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    minMax(&min, &max, vetor, n);
    
    printf("%d %d", min, max);
    
    return 0;
}