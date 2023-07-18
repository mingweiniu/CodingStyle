#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>   

inline std::string GetMonth(tm timedata)
{
    switch (timedata.tm_mon)
    {
    case 0:
        return "Jan";
    case 1:
        return "Feb";
    case 2:
        return "Mar";
    case 3:
        return "Apr";
    case 4:
        return "May";
    case 5:
        return "Jun";
    case 6:
        return "Jul";
    case 7:
        return "Aug";
    case 8:
        return "Sep";
    case 9:
        return "Oct";
    case 10:
        return "Nov";
    case 11:
        return "Dec";
    }

    return {};
}

inline std::string GetDayOfWeek(tm timedata)
{
    switch (timedata.tm_wday)
    {
    case 0:
        return "Sun";
    case 1:
        return "Mon";
    case 2:
        return "Tue";
    case 3:
        return "Wed";
    case 4:
        return "Thu";
    case 5:
        return "Fri";
    case 6:
        return "Sat";
    }

    return {};
}

std::string PrintDateFormat(tm timedata)
{
    std::stringstream ss;
    ss << GetMonth(timedata) << "/" << timedata.tm_mday << "(" << GetDayOfWeek(timedata) << ")";
    return ss.str();
}

inline tm GetSunday(tm timedata)
{
    timedata.tm_mday -= timedata.tm_wday;
    mktime(&timedata);
    return timedata;
}

std::string Weekly(tm timedata) 
{
    auto sunday = GetSunday(timedata);

    std::stringstream ss;    
    ss << PrintDateFormat(timedata);

    for (size_t i = 0; i < 7; i++)
    {
        timedata.tm_mday++;
        mktime(&timedata);
        ss << '\t' << PrintDateFormat(timedata);
    }

    return ss.str();
}

void PrintWeekDate() 
{
    time_t tmNow;
    tmNow = time(NULL);
    auto timedata = *localtime(&tmNow);
    std::cout << Weekly(timedata) << "\n";
}

// // https://www.programiz.com/cpp-programming/online-compiler/
//int main()
//{
//    PrintWeekDate();
//}
