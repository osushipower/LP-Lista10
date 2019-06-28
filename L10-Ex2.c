#include <stdio.h>
 
int minMax(int vetor[100][100], int *m, int *n, int *l, int *c) {
    int i, j, menor, v_minmax;
    
    *l = 0;
    menor = vetor[0][0];
    
    //Encontrando posição do menor
    for (i = 0; i < *m; i++) {
        for (j = 0; j < *n; j++) {
            if (vetor[i][j] < menor) {
                menor = vetor[i][j];
                *l = i;
                *c = j;
            }
        }
    }
    //printf("%d %d\n", *l, *c);
    
    
    v_minmax = vetor[*l][0];
    //printf("\nMaior Valor Antes: %d\n", v_minmax);
    *c = 0;
    //Encontrando posição do maior valor
    for (i = 0; i < *n; i++) {
        if (vetor[*l][i] > v_minmax) {
            v_minmax = vetor[*l][i];
            *c = i;
        }
    }
    return v_minmax;
}
 
int main() {
    
    int i, j, m, n, vetor[100][100];
    int l, c;
 
    scanf("%d", &m);
    scanf("%d", &n);
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &vetor[i][j]);
        }
    }
    
    printf("%d %d %d", l, c, minMax(vetor, &m, &n, &l, &c));
    
    return 0;
}