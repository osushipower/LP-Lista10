#include <stdio.h>

void LeABC ( int *a, int *b, int *c );
void Calcula_XY ( int b, int c, int *x, int *y );
void Calcula_QR ( int a, int b, int *q, int *r );
int Calcula_Z ( int q, int r );
int Calcula_P ( int x, int y, int z );
int Calcula_S ( int m, int p, int q, int r, int x, int y );

int main() {

    int m;
    int a, b, c, p, q, r, s;
    int x, y, z;

    scanf("%d", &m);
    
    LeABC(&a, &b, &c);
    Calcula_XY(b, c, &x, &y);
    Calcula_QR (a, b, &q, &r);
    z = Calcula_Z (q, r);
    p = Calcula_P (x, y, z);
    s = Calcula_S (m, p, q, r, x, y);
    printf("%d", s);
    //printf("%d %d %d", a, b, c);

    return 0;
}

void LeABC ( int *a, int *b, int *c ) {
    scanf("%d %d %d", a, b, c);
}

void Calcula_XY ( int b, int c, int *x, int *y ) {
    int v1, v2, i, j, div = 0;
    *x = b + 1;

    for (i = c + 1; ; i++){
        v1 = 0;
        v2 = 0;
        for (j = 1; j <= i; j++){
            if ((i % j) == 0 && (*x % j) == 0){
                v1++;
                if (j == 1){
                    v2++;
                    div = i;
                }       
            }
        }
        if (v1 == v2){            
            *y = div;
            break;
        }
    }
}

void Calcula_QR ( int a, int b, int *q, int *r ) {
    if (a > b) {
        *q = a/b;
        *r = 1 + (a % b);
    } else if (b > a) {
        *q = b/a;
        *r = 1 + (b % a);
    } else {
        *q = 20 * a;
        *r = 5;
    } 
}

int Calcula_Z ( int q, int r ) {
    int min, i, j, z, div = 0;

    if (q < r) {
        min = q;
    } else {
        min = r;
    }
    if (min == 1) {
        return 1;
    } else {
        for (i= min; i >= 0; i--){
            div = 0;
            for (j = 1; j <= i; j++){
                if ((i % j) ==0){
                    div++;
                }
            }
            if (div == 2){
                z = i;
                break;
            }
        }
        return z;
    }
}

int Calcula_P ( int x, int y, int z ) {
    int p;

    p = x + ((z-1) * y);
    return p;
}

int Calcula_S ( int m, int p, int q, int r, int x, int y ) {
    int s, max, min;

    if (x > y) {
        max = x;
    } else {
        max = y;
    }

    if (q < r) {
        min = q;
    } else {
        min = r;
    }

    s = ((m * p) / max) + min;
    return s;
}