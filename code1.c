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

struct monthlySales {
    //structure of month names and sales numbers
    //used only for sales report (highest to lowest) and later sales summary report
    char month[9];
    float sales;
};

int compare(const void *a, const void *b) {
    //compares sales values of two months and swaps depending on relationship
    return ((struct monthlySales*)b)->sales - ((struct monthlySales*)a)->sales;
}

void monthly_sales_report(float months[]) {
    //prints each month out with monthly sales rounded to second decimal place
    printf("\nMonthly Sales Report for 2024\n\n");
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
    //creates array of monthly sales called yearly
    struct monthlySales yearly[12];
    float avg;
    for (int i=0; i<12; i++) {
        //sets each monthly sales' sales value to corresponding array months' value
        yearly[i].sales = months[i];
    }
    //month names are done separately
    strcpy(yearly[0].month, "January");
    strcpy(yearly[1].month, "February");
    strcpy(yearly[2].month, "March");
    strcpy(yearly[3].month, "April");
    strcpy(yearly[4].month, "May");
    strcpy(yearly[5].month, "June");
    strcpy(yearly[6].month, "July");
    strcpy(yearly[7].month, "August");
    strcpy(yearly[8].month, "September");
    strcpy(yearly[9].month, "October");
    strcpy(yearly[10].month, "November");
    strcpy(yearly[11].month, "December");

    struct monthlySales min = yearly[0], max = yearly[0];
    for (int i=0; i<12; i++) {
        //iterates through each monthly sale, changing max and min to the greatest/least values
        if (yearly[i].sales > max.sales) {
            max = yearly[i];
        }
        if (yearly[i].sales < min.sales) {
            min = yearly[i];
        }
        avg += months[i];   //adds each month's sales together
    }
    printf("\nSales Summary Report:\n\n");
    printf("Minimum Sales: %0.2f (%s)\n", min.sales, min.month);
    printf("Maximum Sales: %0.2f (%s)\n", max.sales, max.month);
    printf("Average Sales: %0.2f\n", avg/12);   //divides total of sales by 12 to get average
}

void six_month_moving_average_report(float months[]) {
    //sets j as the upper bound at 6
    int j=6;
    float avg, sixavg[7];
    while (j<=12) {
        //same process as before but now puts 6-month averages into an array
        avg = 0;
        for (int i=j-6; i<j; i++) {
            avg += months[i];
        }
        sixavg[j-6] = avg;
        j++;
    }
    //prints results from the array
    printf("\nSix Month moving average report:\n\n");
    printf("January June\t%0.2f\n", sixavg[0]/6);
    printf("February July\t%0.2f\n", sixavg[1]/6);
    printf("March August\t%0.2f\n", sixavg[2]/6);
    printf("April September\t%0.2f\n", sixavg[3]/6);
    printf("May October\t%0.2f\n", sixavg[4]/6);
    printf("June November\t%0.2f\n", sixavg[5]/6);
    printf("July December\t%0.2f\n", sixavg[6]/6);
}

void sales_report_high_low(float months[]) {
    //creates another array of structures
    struct monthlySales yearly[12];
    for (int i=0; i<12; i++) {
        yearly[i].sales = months[i];
    }
    strcpy(yearly[0].month, "January\t\t");
    strcpy(yearly[1].month, "February\t");
    strcpy(yearly[2].month, "March\t\t");
    strcpy(yearly[3].month, "April\t\t");
    strcpy(yearly[4].month, "May\t\t");
    strcpy(yearly[5].month, "June\t\t");
    strcpy(yearly[6].month, "July\t\t");
    strcpy(yearly[7].month, "August\t\t");
    strcpy(yearly[8].month, "September\t");
    strcpy(yearly[9].month, "October\t\t");
    strcpy(yearly[10].month, "November\t");
    strcpy(yearly[11].month, "December\t");
    
    //sorts the structures from greatest to least in terms of sales
    qsort(yearly, 12, sizeof(yearly[0]), compare);
    printf("\nSales report (highest to lowest) :\n\n");
    printf("Month\t\tSales\n");
    for (int i=0; i<12; i++) {
        //prints out each month's sales with the month name in descending order of sales
        printf("%s$%0.2f\n", yearly[i].month, yearly[i].sales);
    }
}

int main() {
    //allows file name up to 100 characters, create array of 12 months' sales values
    char file[100];
    float months[12], sales;
    int x=0;
    printf("Enter file name: ");
    scanf("%s", &file);
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        //checks for valid file opened
        printf("Error opening file.\n");
        return 1; //indicates error
    }

    while (fscanf(fp, "%f", &sales) != EOF) {
        //scans each line of floats and puts them into the array
        months[x] = sales;
        x++;
    }

    monthly_sales_report(months);
    sales_summary_report(months);
    six_month_moving_average_report(months);
    sales_report_high_low(months);

    fclose(fp);

    return 0;
}