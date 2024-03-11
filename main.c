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

int getMinimumSaleIndex(char *months[], double sales[]){
    double minimumSale = sales[0];
    int minimumSaleIndex = 0;
    for(int i = 1; i < 12; i++){
        if(sales[i] < minimumSale){
            minimumSale = sales[i];
            minimumSaleIndex = i;
        }
    }
    return minimumSaleIndex;
}

int getMaximumSaleIndex(char *months[], double sales[]){
    double maximumSale = sales[0];
    int maximumSaleIndex = 0;
    for(int i = 1; i < 12; i++){
        if(sales[i] > maximumSale){
            maximumSale = sales[i];
            maximumSaleIndex = i;
        }
    }
    return maximumSaleIndex;
}

void generateMonthlySalesReport(FILE *fOutput, char *months[], double sales[]){
    fprintf(fOutput, "Monthly Sales Report:\n");
    fprintf(fOutput, "%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        fprintf(fOutput, "%-10s $%.2f\n", months[i], sales[i]);
    }
    fprintf(fOutput, "\n");
}

void generateSalesSummary(FILE *fOutput, char *months[], double sales[]){
    int minimumSaleIndex = getMinimumSaleIndex(months, sales);
    int maximumSaleIndex = getMaximumSaleIndex(months, sales);
    fprintf(fOutput, "Sales Summary:\n");
    fprintf(fOutput, "%s\t$%.2f\t(%s)\n", "Minimum sales:", sales[minimumSaleIndex], months[minimumSaleIndex]);
    fprintf(fOutput, "%s\t$%.2f\t(%s)\n", "Maximum sales:", sales[maximumSaleIndex], months[maximumSaleIndex]);
}

void generateSixMonthAverageReport(FILE *fOutput, char *months[], double sales[]){
   fprintf(fOutput, "Six-Month Moving Average Report:\n");
}

void generateSalesReport(FILE *fOutput, char *months[], double sales[]){
    fprintf(fOutput, "Sales Report (Highest to Lowest):\n");
}

int main(){
    FILE *fInput = fopen("input.txt", "r");
    FILE *fOutput = fopen("output.txt", "w");
    char buffer[255];

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[12];

    if(fInput == NULL){
        printf("Unable to open file!\n");
        exit(0);
    }

    int i = 0;
    while (fgets(buffer, 255, fInput) != NULL){
        sscanf(buffer, "%lf", &sales[i]);
        i++;
    }

    fclose(fInput);

    printf("Writing to file: output.txt\n");

    generateMonthlySalesReport(fOutput, months, sales);
    generateSalesSummary(fOutput, months, sales);
    generateSixMonthAverageReport(fOutput, months, sales);
    generateSalesReport(fOutput, months, sales);

    fclose(fOutput);
    printf("Finished writing to file: output.txt\n");
    return 0;
}