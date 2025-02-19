#include "date.h"
#include <iostream>
#include <ctime>

using namespace std;

void Date::init(void) {
    struct tm *tms;
    time_t sec;

    time(&sec);
    tms = localtime(&sec);

    month = (short) tms->tm_mon + 1;
    day = (short) tms->tm_mday;
    year = (short) tms->tm_year + 1900;

}

void Date::init(int m, int d, int y) {
    month = (short) m;
    day = (short) d;
    year = (short) y;
}

void Date::print(void) {
    cout << "------" << " The date is" << "------" << "\n";
    cout << month << "/" << day << "/" << year << "\n";
}