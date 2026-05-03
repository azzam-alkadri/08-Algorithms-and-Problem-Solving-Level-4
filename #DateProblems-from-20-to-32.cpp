#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000

stDate CheckDay(stDate Date)
{
	if (Date.Month == 2)
	{

		if (Date.Day >= 28)
		{
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	return Date;
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,
		Date.Year));
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
	Date = CheckDay(Date);
	return Date;
}


short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0; 

	do
	{
		cout << "Please enter a Month (1-12): ";
		cin >> Month;
	} while (Month < 1 || Month > 12); 

	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	Date = CheckDay(Date);
	return Date;
}



stDate IncreaseDateByXDays(short Days, stDate Date)
{
	for (int i = 0; i < Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;

}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (int i = 0; i < Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	short NumberOfDaysInCurrentMonth =
		NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

stDate IncreaseDateByXMonths(short Month, stDate Date)
{
	for (int i = 0; i < Month; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;

	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);
	return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
	for (int i = 0; i < Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);
	return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year += Years;

	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	short Decade = 10;

	Date.Year += Decade;
	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

stDate IncreaseDateByXDecades(short Decades, stDate Date)
{
	for (int i = 0; i < Decades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decades, stDate Date)
{
	short Decade = 10;

	Date.Year += Decade * Decades;

	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	short Century = 100;

	Date.Year += Century;

	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	short Millennium = 1000;

	Date.Year += Millennium;
	//last check day in date should not exceed max days in the current month
	// example if date is 28/2/1999 increasing one year should not be 28 / 2 / 2000, it should
		// be 29/2/2000
	Date = CheckDay(Date);

	return Date;
}

int main()
{
	stDate Date1 = ReadFullDate();
	cout << "\nDate After: \n";
	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(10, Date1);
	cout << "\n02-Adding 10 days is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding one week is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 weeks is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonths(5, Date1);
	cout << "\n06-Adding 5 months is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 Years is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Adding 10 Years (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecades(10, Date1);
	cout << "\n11-Adding 10 Decades is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Adding 10 Decade (faster) is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding One Millennium is: "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}