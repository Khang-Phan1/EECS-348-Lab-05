/*
Name: Khang Phan
KUID:  3122346
Lab Session: Friday 4 p.m.
Lab Assignment: 05
Description: Given 12 monthly sales figures in an input file, generates monthly sales report, sales summary report, six-month moving average report, and sales report (highest to lowest)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void monthly_sales_report(float months[]) {
    printf("Monthly Sales Report for 2024");
    printf("Month\t\tSales");
    printf("January\t\t%0.2f\n", months[0]);
    printf("February\t%0.2f\n", months[1]);
    printf("March\t\t%0.2f\n", months[2]);
    printf("April\t\t%0.2f\n", months[3]);
    printf("May\t\t%0.2f\n", months[4]);
    printf("June\t\t%0.2f\n", months[5]);
    printf("July\t\t%0.2f\n", months[6]);
    printf("August\t\t%0.2f\n", months[7]);
    printf("September\t%0.2f\n", months[8]);
    printf("October\t\t%0.2f\n", months[9]);
    printf("November\t%0.2f\n", months[10]);
    printf("December\t%0.2f\n", months[11]);
}

int main() {
    char file[100];
    float months[12], sales;
    int x=0;
    printf("Enter file name: ");
    scanf("%s", &file);
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1; 
    }

    printf("Monthly Sales Report for 2024\nMonth\t\tSales\n");
    while (fscanf(fp, "%f", &sales) != EOF) {
        months[x] = sales;
        x++;
    }

    printf("Sales Summary Report:\n");

    fclose(fp);

    return 0;
}