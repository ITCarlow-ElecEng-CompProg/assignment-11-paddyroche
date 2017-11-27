/**
Patrick Roche
Exercise 11
Tomorrow's Date Calculator */

/**< Preprocessor Directives */
#include <iostream>


/**< A Structure to group the day,month and year all together */
struct date
{
    int day;
    int month;
    int year;
};

/**< Fucntion declerations */
date tomorrowsdate(date todaysDate);
int checkLeap(int year);
using namespace std;



/**< Main Function */
int main()
{
    /**< declaring 'struct' as 'date today' */
    struct date today, tomorrow;

    /**< Prompts the user */
    cout << "Enter a day: " << endl;
    cin >> today.day;

    /**< while the day is <0 or >32, it is not valid */
    while(today.day<=0 || today.day>=32)
    {
        cout << "Enter a real day" << endl;
        cin >> today.day;
    }

    /**< Pompt the user */
    cout << "Enter a month: " << endl;
    cin >> today.month;

    /**< while the month is <0 or >13, it is not valid */
    while(today.month<=0 || today.month>=13)
    {
        cout << "Enter a real month" << endl;
        cin >> today.month;
    }

    /**< Promt the user */
    cout << "Enter a year: " << endl;
    cin >> today.year;

    /**< Calling the function */
    tomorrow = tomorrowsdate(today);

    /**< Outputting the date - eg- 12/12/2017 */
    cout << "Tomorrow's date is: " << tomorrow.day << "/" << tomorrow.month << "/" << tomorrow.year << endl;

    return 0;
}

/**< A function that gives all the possibilities for the day/month/year  */
date tomorrowsdate(date todaysDate)
{
    /**< Passing a structure through the function */
    struct date tomorrowsDate;

    tomorrowsDate.day = 0;
    tomorrowsDate.month = 0;
    tomorrowsDate.year = 0;


    /**< if day = 28th, month = feb and year isnt divisable by 4, then its not a leap year */
    if(todaysDate.day == 28 && todaysDate.month == 2 && !checkLeap(todaysDate.year))
    {
        /**< next date is 1st of march */
        todaysDate.day = 1;
        todaysDate.month = 3;
    }
    /**< if day = 28th, month = feb and year is divisable by 4, then its a leap year */
    else if(todaysDate.day == 28 && todaysDate.month == 2 && checkLeap(todaysDate.year))
    {
        /**< next date is 1st of march */
        todaysDate.day = 29;
        todaysDate.month = 2;

    }
    /**< if day = 29th, month = feb and year isnt divisable by 4, then its not a leap year
    and therefore cant be the 29th */
    else if( (todaysDate.day == 29) && (todaysDate.month == 2) && checkLeap(todaysDate.year))
    {
        /**< 1st of march */
        todaysDate.day = 1;
        todaysDate.month = 3;
    }
    /**< if day = 29th, month = feb and year isnt divisable by 4, then its not a leap year
    and therefore cant be the 29th */
    else if(todaysDate.day == 29 && todaysDate.month == 2 && !checkLeap(todaysDate.year))
    {
        cout << "That's not a real date" << endl;
        return tomorrowsDate;
    }
    /**< if the month has 30days */
    else if(todaysDate.day == 30)
    {
        /**<its April, June, Sept and Nov */
        if(todaysDate.month == 4 || todaysDate.month == 6 || todaysDate.month == 9 || todaysDate.month == 11)
        {
            /**< next date is the 1st, and the next month */
            todaysDate.day = 1;
            todaysDate.month = todaysDate.month + 1;
        }
        /**< If feb is the 30th its not a real date */
        else if(todaysDate.month == 2)
        {
            cout << "That's not a real date" << endl;
            return tomorrowsDate;
        }
        else
        {
            /**< or the 31st, not real either */
            todaysDate.day = 31;
        }
    }
    /**< if feb, April, june, sept, nov have 31 days, its not a real date */
    else if(todaysDate.day == 31)
    {
        /**< if feb has 31 days, its not a real date */
        if(todaysDate.month == 2)
        {
            cout << "That's not a real date" << endl;
            return tomorrowsDate;
        }
        /**< if April, june, sept, nov have 31 days, its not a real date */
        else if(todaysDate.month == 4 || todaysDate.month == 6 || todaysDate.month == 9 || todaysDate.month == 11)
        {
            cout << "That's not a real date" << endl;
            return tomorrowsDate;
        }

        /**< if month isnt the 12th month, then its not the end of the year */
        else if(todaysDate.month != 12)
        {
            /**< 1st of next month */
            todaysDate.day = 1;
            todaysDate.month = todaysDate.month + 1;
        }
        else
        {
            /**< 1st of Jan and add a year */
            todaysDate.day = 1;
            todaysDate.month = 1;
            todaysDate.year = todaysDate.year + 1;
        }
    }
    else
    {
        /**< just add a day */
        todaysDate.day = todaysDate.day + 1;
    }

    tomorrowsDate.day = todaysDate.day;
    tomorrowsDate.month = todaysDate.month;
    tomorrowsDate.year = todaysDate.year;

    return tomorrowsDate;
}


int checkLeap(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
                return 0;
        }
        else
        {
            return 1;
        }
    }
    else
        return 0;
}
