#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to multiply two polynomials
Term* multiplyPolynomials(Term* poly1, Term* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    Term* result = NULL;
    Term* current1 = poly1;
    while (current1 != NULL) {
        Term* current2 = poly2;
        while (current2 != NULL) {
            int coeff = current1->coefficient * current2->coefficient;
            int exp = current1->exponent + current2->exponent;
            // Find if a term with the same exponent already exists in the result
            Term* existingTerm = result;
            while (existingTerm != NULL) {
                if (existingTerm->exponent == exp) {
                    // Add the coefficients
                    existingTerm->coefficient += coeff;
                    break;
                }
                existingTerm = existingTerm->next;
            }
            // If no term with the same exponent found, insert a new term
            if (existingTerm == NULL) {
                insertTerm(&result, coeff, exp);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for polynomial
void freePolynomial(Term* poly) {
    Term* current = poly;
    while (current != NULL) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Example polynomials: 4x^2 + 3x + 5 and 9x^2 + 5x + 6
    Term* poly1 = NULL;
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 3, 1);
    insertTerm(&poly1, 5, 0);

    Term* poly2 = NULL;
    insertTerm(&poly2, 9, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 6, 0);

    // Multiply the polynomials
    Term* result_multiply = multiplyPolynomials(poly1, poly2);
    printf("Result of multiplication: ");
    displayPolynomial(result_multiply);

    // Add the polynomials
    Term* result_add = addPolynomials(poly1, poly2);
    printf("Result of addition: ");
    displayPolynomial(result_add);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result_multiply);
    freePolynomial(result_add);

    return 0;
}
