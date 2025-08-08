#pragma once

#include <iostream>
#include <string>
#include <limits>
// #include "clsString.h"
//#include "Date.h"

class InputValidate
{
public:

    static bool isNumberBetween(short number, short from, short to)
    {
        return number >= from && number <= to;
    }

    static bool isNumberBetween(int number, int from, int to)
    {
        return number >= from && number <= to;
    }

    static bool isNumberBetween(double number, double from, double to)
    {
        return number >= from && number <= to;
    }

    /*static bool isDateBetween(Date date, Date from, Date to)
    {
        return (
            (Date::isDate1AfterDate2(date, from) || Date::isDate1EqualDate2(date, from)) &&
            (Date::isdate1Beforedate2(date, to) || Date::isDate1EqualDate2(date, to))
            ) ||
            (
                (Date::isDate1AfterDate2(date, to) || Date::isDate1EqualDate2(date, to)) &&
                (Date::isdate1Beforedate2(date, from) || Date::isDate1EqualDate2(date, from))
                );
    }*/
    // static bool isValidDate(Date date)
   // {
   //     return Date::IsValidDate(date);
   // }

    static std::string readString()
    {
        std::string s;
        std::getline(std::cin >> std::ws, s);
        return s;
    }

    static int readIntNumber(const std::string& errorMessage = "Invalid number, enter again:\n")
    {
        int number;
        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMessage;
        }
        return number;
    }

    static int readIntNumberBetween(int from, int to, const std::string& errorMessage = "Number is not within range, enter again:\n")
    {
        int number = readIntNumber();
        while (!isNumberBetween(number, from, to)) {
            std::cout << errorMessage;
            number = readIntNumber();
        }
        return number;
    }

    static float readFloatNumber(const std::string& errorMessage = "Invalid number, enter again:\n")
    {
        float number;
        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMessage;
        }
        return number;
    }

    static float readFloatNumberBetween(float from, float to, const std::string& errorMessage = "Number is not within range, enter again:\n")
    {
        float number = readFloatNumber();
        while (!isNumberBetween(number, from, to)) {
            std::cout << errorMessage;
            number = readFloatNumber();
        }
        return number;
    }

    static double readDblNumber(const std::string& errorMessage = "Invalid number, enter again:\n")
    {
        double number;
        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMessage;
        }
        return number;
    }

    static double readDblNumberBetween(double from, double to, const std::string& errorMessage = "Number is not within range, enter again:\n")
    {
        double number = readDblNumber();
        while (!isNumberBetween(number, from, to)) {
            std::cout << errorMessage;
            number = readDblNumber();
        }
        return number;
    }
    static short readShortNumber(const std::string& errorMessage = "Invalid number, enter again:\n")
    {
        short number;

        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMessage;
        }
        return number;
    }
    static double readShortNumberBetween(short from, short to, const std::string& errorMessage = "Number is not within range, enter again:\n")
    {
        short number = readDblNumber();
        while (!isNumberBetween(number, from, to)) {
            std::cout << errorMessage;
            number = readDblNumber();
        }
        return number;
    }
};