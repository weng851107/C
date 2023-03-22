#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int coef;
    int exp;
    struct polynomial* next;
} Polynomial;

Polynomial* create_polynomial(int coefficient[], int n)
{
    Polynomial* poly = NULL;
    Polynomial* ptr = NULL;

    for (int i = 0;i < n;i++) {
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        if (!newnode) {
            exit(1);
        }
        if (i == 0) {
            newnode->coef = coefficient[i];
            newnode->exp = i;
            newnode->next = NULL;
            poly = newnode;
            ptr = poly;
        }
        else {
            newnode->coef = coefficient[i];
            newnode->exp = i;
            newnode->next = NULL;
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    return poly;
}

static Polynomial* reverse_polynomial(Polynomial* poly)
{
    Polynomial* rev_poly = NULL;
    while (poly != NULL) {
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        newnode->coef = poly->coef;
        newnode->exp = poly->exp;
        newnode->next = rev_poly;
        rev_poly = newnode;
        poly = poly->next;
    }
    return rev_poly;
}

void print_polynomial(Polynomial* poly)
{
    Polynomial* rev_poly = reverse_polynomial(poly);

    while ((rev_poly != NULL) && (rev_poly->coef == 0)) {
        rev_poly = rev_poly->next;
    }
    if (rev_poly == NULL) {
        printf("0\n");
        return;
    }

    if (rev_poly->exp == 0) {
        printf("%d", rev_poly->coef);
    }
    else if (rev_poly->exp == 1) {
        printf("%dX", rev_poly->coef);
    }
    else {
        printf("%dX^%d", rev_poly->coef, rev_poly->exp);
    }
    rev_poly = rev_poly->next;
    while (rev_poly != NULL) {
        if (rev_poly->exp == 0) {
            if (rev_poly->coef >= 0) {
                printf("+%d", rev_poly->coef);
            }
            else {
                printf("%d", rev_poly->coef);
            }
        }
        else if (rev_poly->exp == 1) {
            if (rev_poly->coef >= 0) {
                printf("+%dX", rev_poly->coef);
            }
            else {
                printf("%dX", rev_poly->coef);
            }
        }
        else {
            if (rev_poly->coef >= 0) {
                printf("+%dX^%d", rev_poly->coef, rev_poly->exp);
            }
            else {
                printf("%dX^%d", rev_poly->coef, rev_poly->exp);
            }
        }
        rev_poly = rev_poly->next;
    }
    printf("\n");
}

static int PolyLength(Polynomial* poly)
{
    if (poly == NULL) {
        return 0;
    }
    while (poly->next != NULL) {
        poly = poly->next;
    }
    return (poly->exp)+1;
}

Polynomial* sum_polynomial(Polynomial* A, Polynomial* B)
{
    if ((A == NULL) && (B == NULL)) {
        return NULL;
    }
    else if (A == NULL) {
        return B;
    }
    else if (B == NULL) {
        return A;
    }

    int A_Length = PolyLength(A);
    int B_Length = PolyLength(B);
    int C_Length = (A_Length>B_Length)?(A_Length):(B_Length);

    int* C_coef = (int *)malloc(C_Length*sizeof(int));
    while ((A != NULL) || (B != NULL)) {
        if ((A != NULL) && (B != NULL)) {
            C_coef[A->exp] = A->coef + B->coef;
            A = A->next;
            B = B->next;
        }
        else if (A != NULL) {
            C_coef[A->exp] = A->coef;
            A = A->next;
        }
        else if (B != NULL) {
            C_coef[B->exp] = B->coef;
            B = B->next;
        }
    }
    return create_polynomial(C_coef, C_Length);
}

Polynomial* multiple_polynomial(Polynomial* A, Polynomial* B)
{
    if ((A == NULL) || (B == NULL)) {
        return NULL;
    }

    int A_Length = PolyLength(A);
    int B_Length = PolyLength(B);
    int C_Length = A_Length+B_Length-1;

    int* C_coef = (int *)malloc(C_Length*sizeof(int));

    Polynomial* current_A = A;
    while (current_A != NULL) {
        Polynomial* current_B = B;
        while (current_B != NULL) {
            C_coef[(current_A->exp)+(current_B->exp)] = C_coef[(current_A->exp)+(current_B->exp)] + (current_A->coef)*(current_B->coef);
            current_B = current_B->next;
        }
        current_A = current_A->next;
    }
    return create_polynomial(C_coef, C_Length);
}

int main()
{
    int A_coef[] = {1, 2, 3, 0, 6, 7, 8};
    int B_coef[] = {2, 0, 4, 5};
    Polynomial* A = create_polynomial(A_coef, 7);
    Polynomial* B = create_polynomial(B_coef, 4);
    Polynomial* C = sum_polynomial(A, B);
    Polynomial* D = multiple_polynomial(A, B);
    printf("A: ");
    print_polynomial(A);
    printf("B: ");
    print_polynomial(B);
    printf("C: ");
    print_polynomial(C);
    printf("D: ");
    print_polynomial(D);
    return 0;
}