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

int main() {
    char fname[100], line[256];
    int month=1;
    printf("Enter file name: ");
    scanf("%s", &fname);
    FILE *fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1; 
    }

    printf("Monthly Sales Report for 2024\nMonth\t\tSales\n");
    while (fgets(line, 256, fp) != NULL) {
        switch (month) {
            case 1:
                printf("January\t\t%s", line);
                break;
            case 2:
                printf("February\t%s", line);
                break;
            case 3:
                printf("March\t\t%s", line);
                break;
            case 4:
                printf("April\t\t%s", line);
                break;
            case 5:
                printf("May\t\t%s", line);
                break;
            case 6:
                printf("June\t\t%s", line);
                break;
            case 7:
                printf("July\t\t%s", line);
                break;
            case 8:
                printf("August\t\t%s", line);
                break;
            case 9:
                printf("September\t%s", line);
                break;
            case 10:
                printf("October\t\t%s", line);
                break;
            case 11:
                printf("November\t%s", line);
                break;
            case 12:
                printf("December\t%s", line);
                break;
        }
        month++;
    }

    fclose(fp);

    return 0;
}