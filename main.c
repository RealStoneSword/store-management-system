#include <stdio.h>
#include <stdlib.h>

void alrProducts();
void alrSales();
int printfile();

int main() {
    int choice1;
    char choice2;
    char choice3;
    printf("Store Management System\n\nWhat would you like to do?\n1.Add/Remove/list Product(s)\n2.Add/List/Remove Sales\n");
    scanf("%d", &choice1);
    
    switch(choice1) {
    case 1 :
        alrProducts();
        break;
    case 2 :
        alrSales();
        break;
    default :
        printf("Invalid Choice. Please try again.\n");
        return 1;
    }
    return 0;
}

void alrSales() {
    char choice3;
     /* a means when they picked add,
     sid stands for sale id */
    char choice3asid[255];
    /* a means when they picked add,
    PID stands for Product id */
    char choice3apid[255];
    /* a means when they picked add,
    SA stands for sold amount */
    char choice3asa[255];
    /* l means they picked list,
    yorn stands for yes or no*/
    char choice3lyorn;
    char choice3lread[255];

        printf("Would you like too (A)dd or (L)ist sales?\n");
        scanf("%s", &choice3);
            switch (choice3) {
            case 'a' :
                printf("What would you like the ID of the sale you are adding going to be?\n(if you dont know, list the sales list and look for the greatest ID and add 1.)\n");
                scanf("%s", &choice3asid);
                printf("What is the product that you sold id?\n(if you dont know, list the produts and look for the right product's id)\n");
                scanf("%s", &choice3apid);
                printf("How many of the product did you sell?\n");
                scanf("%s", &choice3asa);
                FILE * fpointer = fopen("database-sales.csv", "a");
                fprintf(fpointer, "%s,%s,%s\n", &choice3asid, &choice3apid, &choice3asa);
                fclose(fpointer);
            break;

            case 'l' :
                printf("This will print the ENTIRE sales database. Are you sure you want to continue? [y/n]");
                scanf("%s", &choice3lyorn);
                switch (choice3lyorn) {
                    case 'y' :
                        printfile("database-sales.csv");
                        break;
                    case 'n' :
                        break;
                    default :;
                    printf("Invalid Command. Please Try again.");
                    }

            break;

            default :
                printf("Invalid Choice. Please try again.\n");
            break;
            }

}
                

void alrProducts(){
    char choice4;
     /* a means when they picked add,
     pid stands for prouduct id */
    char choice4apid[255];
    /* a means when they picked add,
    p stands for price */
    char choice4ap[255];
    /* a means when they picked add,
    n stands for name */
    char choice4an[255];
    /* l means they picked list,
    yorn stands for yes or no*/
    char choice4lyorn;
    char choice3lredad[255];

    printf("Would you like too (A)dd or (L)ist prouducts?\n");
        scanf("%s", &choice4);
            switch (choice4)
            {
            case 'a' :
                printf("What would you like the ID of the product you are adding going to be?\n(if you dont know, list the product list and look for the greatest ID and add 1.)\n");
                scanf("%s", &choice4apid);
                printf("What is the price of the product?\n(Exculuding $, £, ect)\n");
                scanf("%s", &choice4ap);
                printf("What is the name of the product?\n(no spaces, 255 character limit)\n");
                scanf("%s", &choice4an);
                FILE * fpointer = fopen("database-products.csv", "a");
                fprintf(fpointer, "%s,%s,%s\n", &choice4apid, &choice4ap, &choice4an);
                fclose(fpointer);
                break;

            case 'l' :
                printf("This will print the ENTIRE products database. Are you sure you want to continue? [y/n]");
                scanf("%s", &choice4lyorn);
                switch (choice4lyorn) {
                    case 'y' :
                        printfile("database-products.csv");
                        break;
                    case 'n' :
                        break;
                    
                    
                    default :;
                    printf("Invalid Command. Please Try again.");
                    break;
                    
                    }
                
                }

}

int printfile(char *filename) {
    int i;
    FILE *fp = fopen(filename, "r");
    char buf[1024];

    i = 1;
    while (fgets(buf, 1024, fp)) {
        printf("L%d: %s", i, buf);
        i++;
    }

    fclose(fp);

    return 0;
}




/* backup 

    if (!fp) {
        printf("Can't open file\n");
        return 1;
    }

    char buf[255];
    int i;

    FILE * fpointer = fopen(filename, "r");
    i = 1; 
    while (fgets(buf, sizeof(buf), fpointer) != NULL) {
        printf("Line %d: %s", i, buf);
        i++;
    }
    fclose(fpointer);

    return 0;

    */

    /* The old if statement (here for future use if needed) */

    /*
    if(choice1 == 1) {
        printf("Would you like to (A)dd, (R)emove, or (l)ist products?\n");
        scanf("%s", &choice2);
        printf("%s", choice2);
    }
    else if(choice1 == 2) {
        printf("Would you like too (A)dd, (L)ist, or (R)emove sales?\n");
        scanf("%s", &choice3);
        printf("%s", choice3);
    }
    else{
        printf("Invalid Choice. Please try again.\n");
    }
    */
