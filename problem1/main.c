#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MONTHS 12
#define BUFFER_SIZE 255

int getMinimumSaleIndex(char *months[], double sales[]) {
    double minimumSale = sales[0];
    int minimumSaleIndex = 0;

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < minimumSale) {
            minimumSale = sales[i];
            minimumSaleIndex = i;
        }
    }

    return minimumSaleIndex;
}

int getMaximumSaleIndex(char *months[], double sales[]) {
    double maximumSale = sales[0];
    int maximumSaleIndex = 0;

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] > maximumSale) {
            maximumSale = sales[i];
            maximumSaleIndex = i;
        }
    }

    return maximumSaleIndex;
}

double calculateSixMonthAverage(double sales[], int startIndex) {
    double sum = 0.0;

    for (int i = startIndex; i < startIndex + 6; i++) {
        sum += sales[i];
    }

    return sum / 6.0;
}

void generateMonthlySalesReport(FILE *fOutput, char *months[], double sales[]) {
    fprintf(fOutput, "Monthly Sales Report:\n");
    fprintf(fOutput, "%-10s %-10s\n", "Month", "Sales");

    for (int i = 0; i < NUM_MONTHS; i++) {
        fprintf(fOutput, "%-10s $%.2f\n", months[i], sales[i]);
    }

    fprintf(fOutput, "\n");
}

void generateSalesSummary(FILE *fOutput, char *months[], double sales[]) {
    int minimumSaleIndex = getMinimumSaleIndex(months, sales);
    int maximumSaleIndex = getMaximumSaleIndex(months, sales);

    fprintf(fOutput, "Sales Summary:\n");
    fprintf(fOutput, "%s\t$%.2f\t(%s)\n", "Minimum sales:", sales[minimumSaleIndex], months[minimumSaleIndex]);
    fprintf(fOutput, "%s\t$%.2f\t(%s)\n", "Maximum sales:", sales[maximumSaleIndex], months[maximumSaleIndex]);
    fprintf(fOutput, "\n");
}

void generateSixMonthAverageReport(FILE *fOutput, char *months[], double sales[]) {
    fprintf(fOutput, "Six-Month Moving Average Report:\n");

    char initialMonth[10];
    char finalMonth[10];
    double sixMonthAverage;

    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        strcpy(initialMonth, months[i]);
        strcpy(finalMonth, months[i + 5]);
        sixMonthAverage = calculateSixMonthAverage(sales, i);
        fprintf(fOutput, "%-10s - %-10s $%.2f\n", initialMonth, finalMonth, sixMonthAverage);
    }

    fprintf(fOutput, "\n");
}

void generateSalesReport(FILE *fOutput, char *months[], double sales[]) {
    fprintf(fOutput, "Sales Report (Highest to Lowest):\n");
    fprintf(fOutput, "%-10s %-10s\n", "Month", "Sales");

    int salesHighToLowIndex[NUM_MONTHS];

    for (int i = 0; i < NUM_MONTHS; i++) {
        salesHighToLowIndex[i] = i;
    }

    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = 0; j < NUM_MONTHS - i - 1; j++) {
            if (sales[salesHighToLowIndex[j]] < sales[salesHighToLowIndex[j + 1]]) {
                int temp = salesHighToLowIndex[j];
                salesHighToLowIndex[j] = salesHighToLowIndex[j + 1];
                salesHighToLowIndex[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < NUM_MONTHS; i++) {
        fprintf(fOutput, "%-10s $%.2f\n", months[salesHighToLowIndex[i]], sales[salesHighToLowIndex[i]]);
    }

    fprintf(fOutput, "\n");
}

int main() {
    FILE *fInput = fopen("input.txt", "r");
    FILE *fOutput = fopen("output.txt", "w");
    char buffer[BUFFER_SIZE];

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[NUM_MONTHS];

    if (fInput == NULL || fOutput == NULL) {
        printf("Unable to open files!\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, fInput) != NULL) {
        if (sscanf(buffer, "%lf", &sales[i]) != 1) {
            printf("Error reading sales data from file!\n");
            exit(EXIT_FAILURE);
        }
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
