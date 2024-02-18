#include<stdio.h>
#include<stdlib.h>

struct term{
    struct term *link;
    int coeff;
    int exp;
};

struct term *root;

struct term* createTerm(int coeff, int exp) {
    struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->link = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(struct term *poly, int coeff, int exp) {
    struct term *newTerm = createTerm(coeff, exp);
    if (poly == NULL) {
    //struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    poly->coeff = coeff;
    poly->exp = exp;
    poly->link = NULL;
    //return newTerm;
        //poly = newTerm;
    } else {
        struct term *current = poly;
        while (current->link != NULL) {
            current = current->link;
        }
    struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->link = NULL;
    //return newTerm;
        current->link = newTerm;
    }
}


struct term* addPolynomial(struct term *poly1,struct term *poly2) {
    struct Term *result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            //insertTerm(&result, poly2->coeff, poly2->exp);
            struct term *newTerm = (struct term *)malloc(sizeof(struct term));
            newTerm->coeff = poly2->coeff;
            newTerm->exp = poly2->exp;
            newTerm->link = NULL;
            if(result==NULL){
                result=newTerm;
            }
            else{
                struct term *current = result;
            while (current->link != NULL) {
                    current = current->link;
                }
                current->link=newTerm;
            }
            poly2 = poly2->link;

        } else if (poly2 == NULL) {
            struct term *newTerm = (struct term *)malloc(sizeof(struct term));
            newTerm->coeff = poly1->coeff;
            newTerm->exp = poly1->exp;
            newTerm->link = NULL;
            if(result==NULL){
                result=newTerm;
            }
            else{
                struct term *current = result;
            while (current->link != NULL) {
                    current = current->link;
                }
            current->link=newTerm;
            }
            poly1 = poly1->link;
        } else if (poly1->exp > poly2->exp) {
            struct term *newTerm = (struct term *)malloc(sizeof(struct term));
            newTerm->coeff = poly1->coeff;
            newTerm->exp = poly1->exp;
            newTerm->link = NULL;
            if(result==NULL){
                result=newTerm;
            }
            else{
                struct term *current = result;
            while (current->link != NULL) {
                    current = current->link;
                }
            current->link=newTerm;
            }
            poly1 = poly1->link;

        } else if (poly1->exp < poly2->exp) {
            struct term *newTerm = (struct term *)malloc(sizeof(struct term));
            newTerm->coeff = poly2->coeff;
            newTerm->exp = poly2->exp;
            newTerm->link = NULL;
            if(result==NULL){
                result=newTerm;
            }
            else{
                struct term *current = result;
            while (current->link != NULL) {
                    current = current->link;
                }
            current->link=newTerm;
            }
            poly2 = poly2->link;
        } else {
            struct term *newTerm = (struct term *)malloc(sizeof(struct term));
            newTerm->coeff = poly1->coeff+poly2->coeff;
            newTerm->exp = poly2->exp;
            newTerm->link = NULL;
            if(result==NULL){
                result=newTerm;
            }
            else{
                struct term *current = result;
            while (current->link != NULL) {
                    current = current->link;
                }
            current->link=newTerm;
            }
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    return result;
}


void display(struct term *poly){
    struct term *curr;
    curr = poly;
    while(curr != '\0'){
        printf("%dx^%d", curr->coeff, curr->exp);
        if(curr!='\0'){
            printf("+");
        }
        curr = curr->link;
    }
    printf("\n");
}

int main() {
    // Example polynomials: 4x^2 + 3x + 5 and 9x^2 + 5x + 6
    struct term  *poly1 = NULL;
    insertTerm(poly1, 4, 2);
    insertTerm(poly1, 3, 1);
    insertTerm(poly1, 5, 0);

    struct term *poly2 = NULL;
    insertTerm(poly2, 9, 2);
    insertTerm(poly2, 5, 1);
    insertTerm(poly2, 6, 0);



    // Add the polynomials
    struct term *result_add = addPolynomial(poly1, poly2);
    printf("Result of addition: ");
    display(result_add);


}
