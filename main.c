/*
Given 12 monthly sales numbers in an input file. Using functions, generate a tabular sales report
and also the sales summary report (as shown in the sample output). Your output should include
the below:
• Sales report (month and sales in two columns)
• minimum, maximum, and average of the monthly sales.
• six-month moving averages.
• monthly sales report from highest to lowest.
*/

#include <stdio.h>
#include <stdlib.h>

void generateMonthlySalesReport(char *months[], double sales[]){
    printf("%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

int main(){

    FILE *fptr = fopen("input.txt", "r");
    char buffer[255];

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[12];
    double minimumSale;
    double maximumSale;
    
    if(fptr == NULL){
        printf("Unable to open file!\n");
        exit(0);
    }

    int i = 0;
    while (fgets(buffer, 255, fptr) != NULL){
        sscanf(buffer, "%lf", &sales[i]);
        i++;
    }
    
    fclose(fptr);

    generateMonthlySalesReport(months, sales);

    return 0;
}