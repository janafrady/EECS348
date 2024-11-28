/*
Name: Jana Frady
KUID: 3085051
Lab Session: Thursday 4 p.m.
Lab Assignment Number: 05
Program Description: This program generates a sales report from an input file.
Collaborators: None
*/

#include <stdio.h>
#include <string.h>

// prints monthly sales reports
void monthly_sales_report(double *reports, char months[12][10]){
    printf("\nMonthly Sales Report for 2024\n\nMonth\t\tSales\n");
    for (int i=0; i<12; i++){
        if (strlen(months[i]) > 7){ // longer months index for better spacing and formatting
            printf("%s\t%.2f\n", months[i], reports[i]);
        } else {
            printf("%s\t\t%.2f\n", months[i], reports[i]);
        }
    }
}

// finds index of minimum sale
int min_sale(double *reports){
    int min = 0;
    for (int i=0; i<12; i++){
        if (reports[min] > reports[i]){
            min = i;
        }
    }
    return min;
}

// finds index of maximum sale
int max_sale(double *reports){
    int max = 0;
    for (int i=0; i<12; i++){
        if (reports[max] < reports[i]){
            max = i;
        }
    }
    return max;
}

// calculates average sales
double average_sales(double *reports, int size){
    double sum;
    for (int i=0; i<size; i++){
        sum += reports[i];
    }
    return sum/size;
}

// prints minimum sales, maximum sales, and average sales
void summary_sales_report(double *reports, char months[12][10]){
    int minIndex = min_sale(reports);
    int maxIndex = max_sale(reports);
    printf("\nSales summary report:\n\n");
    printf("Minimum sales: %.2f (%s)\n", reports[minIndex], months[minIndex]);
    printf("Maximum sales: %.2f (%s)\n", reports[maxIndex], months[maxIndex]);
    printf("Average sales: %.2f\n", average_sales(reports, 12));
}

// six-month moving average
void sixMonthAvg(double *reports, char months[12][10]){
    double subReports[6];
    printf("\nSix-Month moving average report:\n\n");
    for (int i=0; i<7; i++){
        int increment = i;
        for (int j=0; j<6; j++){ // creates subsets of each six months
            subReports[j] = reports[increment];
            increment++;
        }
        printf("%s-%s\t%.2f\n", months[i],months[i+5], average_sales(subReports, 6));
    }
}

void ordered_sales_report(double *reports, char months[12][10]){
    // bubble sort for highest to lowest reports
    int n = 12;
    double temp;
    char mon[10];
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1;j++){
            // printf("i %d, j %d\n", i,j);
            if (reports[j] < reports[j+1]){
                // swaps reports
                temp = reports[j];
                reports[j] = reports[j+1];
                reports[j+1] = temp;
                // swaps month names
                strcpy(mon, months[j]);
                strcpy((months[j]), months[j+1]);
                strcpy(months[j+1], mon);
            }
        }
    }
    printf("\nSales report (highest to lowest):\n\nMonth\t\tSales\n");
    for (int i=0; i<12; i++){
        if (strlen(months[i]) > 7){
            printf("%s\t$%.2f\n", months[i], reports[i]);
        } else {
        printf("%s\t\t$%.2f\n", months[i], reports[i]);
        }
    }
}

int main(){
    double reports[12];
    char months[12][10] = {"January", "February", "March", "April","May","June","July","August","September","October","November","December"};
    FILE *fptr;
    fptr = fopen("test.txt", "r");

    for (int index = 0; index<12; index++){
        fscanf(fptr, "%le", &reports[index]);
    }

    monthly_sales_report(reports, months);
    summary_sales_report(reports, months);
    sixMonthAvg(reports, months);
    ordered_sales_report(reports, months);

    fclose(fptr);
}
