//  This file is part of my personal string library "Utility-Library"
// Originally developed to simplify coding tasks.
 //original repository: https://github.com/nalodagreat/Util-Library
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Util
{
    public:
    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int randomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char generateSmallLetter()
    {
        return char(randomNumber(97, 122));
    }
    static char generateCapitalLetter()
    {
        return char(randomNumber(65, 90));
    }
    static char generateDigit()
    {
        return char(randomNumber(84, 75));
    }
    static char generateSpecialChar()
    {
        return char(randomNumber(33, 64));
    }

    static char generateMixChar()
    {
        char small = generateSmallLetter();
        char capital = generateCapitalLetter();
        char digit = generateDigit();
        char special = generateSpecialChar();
        char arr[] = { small,capital,digit,special };
        return arr[randomNumber(0, 3)];
    }

        enum enCharType 
    {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static char GetRandomChar(enCharType charType)
    {
        if (charType == SamallLetter)
            return generateSmallLetter();
        else if (charType == CapitalLetter)
        {
            return generateCapitalLetter();
        }
        else if (charType == Digit)
        {
            return generateDigit();
        }
        else if (charType == SpecialCharacter)
            return generateSpecialChar();
        else
        {
            return generateMixChar();
        }
    }
    static string generateWord(enCharType charType,short length)
    {
        string word = "";
        for (int i = 0; i < length; i++)
        {
            word += GetRandomChar(charType);
        }
        return word;
    }
static string generateKey(enCharType charType)
    {
        string key = "",sperator="-"; short groups = 12;
        for (int i = 0; i < groups; i++)
        {
            key += generateWord(charType,4);
            if (i < groups - 1)
            {
                key += sperator;
            }
        }
        return key;
    }

    static vector <string>  generateKeys(enCharType charType,short quantity)
    {
        vector <string> vKeys;
        for (int i = 0; i < quantity; i++)
        {
            vKeys.push_back(generateKey(charType));
        }
        return vKeys;
    }
static  void swap(int &a, int &b)
    {
        int c = 0;
        c = a;
        a = b;
        b = c;
    }
    static void swap(double &a, double &b)
    {
        double c = 0;
        c = a;
        a = b;
        b = c;
    }
    static void swap(string& a, string& b)
    {
        string c = "";
        c = a;
        a = b;
        b = c;
    }
    static  void swap(char& a, char& b)
    {
        char c;
        c = a;
        a = b;
        b = c;
    }
    static void  fillArrayWithRandomNum(int arr[100], short arrLength, short from, short to)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = randomNumber(from, to);
        }

    }
    static void fillArrayWithRandomWords(string arr[100], short arrLength, enCharType charType,short wordLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = generateWord(charType,wordLength);
        }
    }
    static void fillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateKey(CharType);
    }

    static void  shuffleArray(int arr[100], short arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[randomNumber(1, arrLength)-1], arr[randomNumber(1, arrLength)-1]);
        }
    }
    static void shuffleArray(string arr[100], short arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[randomNumber(1, arrLength)-1], arr[randomNumber(1, arrLength)-1]);
        }
    }

     static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
        }
        return t;
    }
 
    static string  encryptText(string text, short encryptionKey)
    {
        for (int i = 0; i < text.size(); i++)
        {
            text[i] = char( (int) text[i] + encryptionKey );
        }
        return text;
    }
    static string  decryptText(string text, short encryptionKey)
    {
        for (int i = 0; i < text.size(); i++)
        {
            text[i] = char((int)text[i] -  encryptionKey);
        }
        return text;
    }
    
};