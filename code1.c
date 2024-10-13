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
    printf("Monthly Sales Report for 2024\n\n");
    printf("Month\t\tSales\n");
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

void sales_summary_report(float months[]) {
    float min=months[0], max=months[0], avg;
    for (int i=0; i<12; i++) {
        if (months[i] > max) {
            max = months[i];
        }
        if (months[i] < min) {
            min = months[i];
        }
        avg += months[i];
    }
    printf("\nSales Summary Report:\n\n");
    printf("Minimum Sales: %0.2f\n", min);
    printf("Maximum Sales: %0.2f\n", max);
    printf("Average Sales: %0.2f\n", avg/12);
}

void six_month_moving_average_report(float months[]) {
    int j=6;
    float avg, sixavg[7];
    while (j<=12) {
        avg = 0;
        for (int i=j-6; i<j; i++) {
            printf("%f\n", months[i]);
            avg += months[i];
        }
        printf("separator!!!!!\n");
        sixavg[j-6] = avg;
        j++;
    }
    printf("Six Month moving average report:\n\n");
    printf("January June\t%0.2f\n", sixavg[0]/6);
    printf("February July\t%0.2f\n", sixavg[1]/6);
    printf("March August\t%0.2f\n", sixavg[2]/6);
    printf("April September\t%0.2f\n", sixavg[3]/6);
    printf("May October\t%0.2f\n", sixavg[4]/6);
    printf("June November\t%0.2f\n", sixavg[5]/6);
    printf("July December\t%0.2f\n", sixavg[6]/6);
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

    while (fscanf(fp, "%f", &sales) != EOF) {
        months[x] = sales;
        x++;
    }

    monthly_sales_report(months);
    sales_summary_report(months);
    six_month_moving_average_report(months);

    fclose(fp);

    return 0;
}