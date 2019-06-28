#include <stdio.h>
 
void interseccao(int vA[200], int vB[200], int vC[200], int *m, int *n, int *p) {
    int i, j, aux = 0, soma = 0;
    
    // for (i = 0; i < (*m); i++) {
    //     printf("%d ", vA[i]);
    // }
    // printf("\n");
    // for (i = 0; i < (*n); i++) {
    //     printf("%d ", vB[i]);
    // }
    // printf("\n");
    
    for (i = 0; i < (*m); i++) {
        for (j = 0; j < (*n); j++) {
            if (vA[i] == vB[j]) {
                vC[aux] = vA[i];
                aux++;
                break;
            }
        }
    }
    
    if (aux != 0) {
        //printf("\n");
        for (i = 0; i < aux; i++) {
            //printf("%d ", vC[i]);
            soma = soma + vC[i];
        }
        printf("%d", soma);
    } else {
        printf("0");
    }
    
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
    interseccao(A, B, C, &m, &n, &p);
    
    return 0;
}