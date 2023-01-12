#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void read_poly(polynomial p[]) {
    int n, i;
    float c;
    int e;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f%d", &c, &e);
        p[i].coef = c;
        p[i].expon = e;
    }
}

void print_poly(polynomial p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.1fx^%d", p[i].coef, p[i].expon);
        if (i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

void add_poly(polynomial a[], int n, polynomial b[], int m, polynomial sum[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i].expon > b[j].expon)
            sum[k++] = a[i++];
        else if (a[i].expon < b[j].expon)
            sum[k++] = b[j++];
        else {
            sum[k].expon = a[i].expon;
            sum[k++].coef = a[i++].coef + b[j++].coef;
        }
    }
    for (; i < n; i++)
        sum[k++] = a[i];
    for (; j < m; j++)
        sum[k++] = b[j];
}

void multiply_poly(polynomial a[], int n, polynomial b[], int m, polynomial prod[]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            k = avail++;
            prod[k].coef = a[i].coef * b[j].coef;
            prod[k].expon = a[i].expon + b[j].expon;
        }
    }
}

int main() {
    polynomial a[MAX_TERMS], b[MAX_TERMS], sum[MAX_TERMS], prod[MAX_TERMS];
    int n, m;
    
    //read first polynomial from file
    FILE *f1;
    f1 = fopen("poly1.txt", "r");
    fscanf(f1, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%f%d", &a[i].coef, &a[i].expon);
    }
    fclose(f1);
    
    //read second polynomial from file
    FILE *f2;
    f2 = fopen("poly2.txt", "r");
    fscanf(f2, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(f2, "%f%d", &b[i].coef, &b[i].expon);
    }
    fclose(f2);

    // add the polynomials
    add_poly(a, n, b, m, sum);
    printf("The sum of the polynomials is: ");
    print_poly(sum, n + m);

    // multiply the polynomials
    multiply_poly(a, n, b, m, prod);
    printf("The product of the polynomials is: ");
    print_poly(prod, avail);

    return 0;
}
