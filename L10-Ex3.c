#include <stdio.h>
 
void uniao(int vA[200], int vB[200], int vC[200], int *m, int *n, int *p) {
    int i, j, k, aux = 0, soma = 0;
    
    *p = *m + *n;
    //printf("\n# Elementos: %d", *p);
    
    for (i = 0; i < (*m); i++) {
        vC[i] = vA[i]; 
    }
    for (i = (*m); i < (*p); i++) {
        vC[i] = vB[aux];
        aux++;
    }
    //Novo Vetor
    //printf("\nC: ");
    // for (i = 0; i < *p; i++) {
    //     printf("%d ", vC[i]);
    // }
    
    //Eliminando os numeros repetidos do novo vetor
    
    for (i = 0; i < (*p); i++) {
        for (j = i+1; j < (*p);) {
            if (vC[j] == vC[i]) {
                for (k = j; k < (*p); k++) {
                    vC[k] = vC[k+1];
                }
                (*p)--;
            } else {
                j++;
            }
            
        }
    }
    
    //União
    //printf("\n");
    for(i = 0; i < *p; i++) {
        soma = soma + vC[i];
    }
    printf("%d", soma);
    
}
 
int main() {
    
    int m, A[200], n, B[200], p, C[200];
    int i, j, k;
    
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    
    //Retirando os numeros repetidos de A
    for (i = 0; i < m; i++) {
        for (j = i+1; j < m;)
            if (A[j] == A[i]) {
                for (k = j; k < m; k++) {
                    A[k] = A[k+1];   
                }
                m--;
            } else {
                j++;
            }
    }
    
    //Retirando os numeros repetidos de B
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n;)
            if (B[j] == B[i]) {
                for (k = j; k < n; k++) {
                    B[k] = B[k+1];   
                }
                n--;
            } else {
                j++;
            }
    }
    
    // //Imprimindo vetor sem repetidos
    // printf("A: ");
    // for (i = 0; i < m; i++) {
    //     printf("%d ", A[i]);
    // }
    
    // printf("\nB: ");
    // //Imprimindo vetor sem repetidos
    // for (i = 0; i < n; i++) {
    //     printf("%d ", B[i]);
    // }
    
    //Gerando União dos Vetores
    uniao(A, B, C, &m, &n, &p);
    
    return 0;
}