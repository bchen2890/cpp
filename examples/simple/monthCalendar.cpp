#include<iostream>
#include<iomanip>
#include <string>

using namespace std;

const string MONTH_NAMES []= {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", 
        "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

int daysInMonth (int month, int year){
	if( month == 2)
	{
		if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))	
			return 29;
		else	
			return 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	|| month == 10 || month == 12)
		return 31;
	else 		
		return 30;
}

//Tomohiko Sakamoto’s Algorithm
int dayOfWeek (int day, int month, int year){
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

void printMonthCalendar(int month, int year){
    const int DAY_WIDTH = 4, WEEKDAYS = 7, YEAR_WIDTH = 4;
    cout << endl << endl;
    cout << setw(DAY_WIDTH * WEEKDAYS - YEAR_WIDTH - 1);
    cout << MONTH_NAMES [month - 1] << " " << year << endl;
    cout << setw(DAY_WIDTH) << 'D'
         << setw(DAY_WIDTH) << 'L'
         << setw(DAY_WIDTH) << 'M'
         << setw(DAY_WIDTH) << 'X'
         << setw(DAY_WIDTH) << 'J'
         << setw(DAY_WIDTH) << 'V'
         << setw(DAY_WIDTH) << 'S' << endl;
    cout << setfill('-') << setw(DAY_WIDTH * WEEKDAYS) << "" << endl;
    cout << setfill(' ');
    int weekdayOfFirstDay = dayOfWeek(1, month, year);
    int daysOfMonth = daysInMonth(month, year);
    for (int j = 0; j < weekdayOfFirstDay; j++){
        cout << setw(DAY_WIDTH) << ' ';
    }
    for (int i = 1; i <= daysOfMonth; i++){
	    cout << setw(DAY_WIDTH) << i;
        if ((weekdayOfFirstDay + i) % 7 == 0){
            cout << endl;
        }
    }
}

int main() {
    int month, year;
    cout << "Enter a month:";
    cin >> month;

    while ( !(1 <= month && month <= 12) ) {
        cout << "Enter a valid month:";
        cin >> month;
    }

    cout << "Enter a gregorian year:";
    cin >> year;

    while ( !(year >= 1582) ) {
        cout << "Enter a valid gregorian year:";
        cin >> year;
    }

    printMonthCalendar(month, year);
    return 0;
}