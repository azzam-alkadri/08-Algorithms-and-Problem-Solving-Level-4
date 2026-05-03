#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool isLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[13] = {  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month-1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();

    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\nDate after adding one day is:"
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    
    return 0;
}