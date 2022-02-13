#include <stdio.h>

#define NUM 3 //CREATE a predefinition called NUM with value 3


/**
 * 1. Define the struct
 *    which is the main data structure in this program
 * 2. Declare methods
 * 3. Define control flow in main (use as a test too)
 * 4. Define methods (define is when we actually write the logic)
 *
 */

struct Date {
    int day;
    int month;
    int year;
};

struct Date globalDate;


/**
 * Method declarations
 */
void getDate();
int is_leap(int year);
int chkday(struct Date date);
int chkmonth(int month);
int chkyear(int year);
void day_of_year(struct Date date);
int getNumOfDays(struct Date date);
/**
 *

 */
void main(){

    getDate();

}

void getDate() {
    while(1) {
        printf("Enter day: ");
        while (scanf("%d", &globalDate.day) != 1) {
            printf("\nEnter number\n");
            while (getchar() != '\n');
        }

        printf("Enter month: ");
        while (scanf("%d", &globalDate.month) != 1) {
            printf("\nEnter number\n");
            while (getchar() != '\n');
        }

        printf("Enter year: ");
        while (scanf("%d", &globalDate.year) != 1) {
            printf("\nEnter number\n");
            while (getchar() != '\n');
        }

        if (chkday(globalDate) != 1 ||
            chkmonth(globalDate.month) != 1 ||
            chkyear(globalDate.year) != 1) {
            printf("Invalid date\n");
        } else {
            printf("Date is valid");
            day_of_year(globalDate);
            break;
        }
    }
}

int chkday(struct Date date) {
    int day = date.day;
    int maxDay = getNumOfDays(date);
    //Out of bounds
    if (day <= 0 || day > maxDay) {
        printf("Day must be between 1 and %d\n", maxDay);
        return -1;
    }
    return 1; //Day within bounds
}

int chkmonth(int month) {
    if (month <= 0 || month > 12) {
        printf("Invalid month\n");
        return -1;
    }
    return 1;
}

int chkyear(int year) {
    if (year <= 0) {
        printf("Invalid year\n");
        return -1;
    }
    return 1;
}

int is_leap(int year) {
    if((year % 400 == 0)||((year % 4 == 0) && (year % 100 != 0)))
        //Leap year if perfectly divisible by 400
        //Leap year if perfectly divisible by 4
        //but if not divisible by 100
        return 1;
    else//all other years are not leap year
        return 0;
}


void day_of_year(struct Date date) {
    int mo[12] = {31,28+is_leap(date.year),31,
                    30,31,30,31,31,30,31,30,31};
    int i;
    int dofy = 0;   // EDIT


    for (i=0; i<(date.month-1); i++) {
        dofy += mo[i];
    }
    dofy += date.day;
    printf("\nDay of the year: %d, %d days left for the end of the year\n", dofy, 365 - dofy - is_leap(date.year));
}

int getNumOfDays(struct Date date) {
    int month = date.month;
    if (month != 2) { //It is not Feb
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            return 31;
        }
        return 30;
    }
    if (is_leap(date.year)) {
        return 29; //Is Feb and leap
        //RETURN 1 if its leap and 0 if it isnt
    }
        return 28; // is Feb but not leap
}