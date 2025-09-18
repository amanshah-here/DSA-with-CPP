#include <iostream>
#include <cstring>
using namespace std;

void lowerCase(char* str)
{
    int len = strlen(str);

    cout << "Converted String from 1st Function : ";
    for (int i = 0; i < len; i++)
    {
        cout << char(tolower(str[i]));
    }
}

void lowerCase2(char* str)
{
    int len = strlen(str);

    cout << "Converted String from 2nd Function : ";
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            cout << str[i];
        }
        else if ('a' <= str[i] && str[i] <= 'z')
        {
            cout << str[i];
        }
        else
        {
            cout << char((str[i] - 'A') + 'a');
        }
    }
}

int main()
{
    char str[50];

    cout << "Input a String : ";
    cin.getline(str, 50);

    lowerCase(str);
    cout << endl;
    lowerCase2(str);

    return 0;
}