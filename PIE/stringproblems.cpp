#include <unordered_map>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
/**
 * Returns the first character in the string which is not repeated.
*/
char findNonRepeatedChar(string str)
{
    unordered_map<char, int> map;
    int i;
    int length = str.length();

    //O(N)
    for (int i = 0; i < length; i++)
    {
        char c = str.at(i);
        if (map.find(c) != map.end())
        {
            map[c] = map[c] + 1;
        }
        else
        {
            map.emplace(c, 1);
        }
    }
    //O(n)
    for (int i = 0; i < length; i++)
    {
        char c = str.at(i);
        if (map[c] == 1)
            return c;
    }
    return NULL;
}

/**
 * Array implementation.
 * Returns new string after removing chars from remove.
*/
string remove(string str, string remove)
{

    char *s = new char[str.length() + 1];
    strcpy(s, str.c_str());
    cout << s << endl;
    char *r = new char[remove.length() + 1];
    strcpy(r, remove.c_str());
    cout << r << endl;
    bool flags[128];
    for (int i = 0; i < str.length(); i++)
    {
        flags[s[i]] = false;
    }

    for (int i = 0; i < remove.length(); i++)
    {
        flags[r[i]] = true;
    }
    int dst = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!flags[s[i]])
            s[dst++] = s[i];
    }
    return string(s, 0, dst);
}
/**\
 * Converts a given string into a integer.
*/
int strToInt(string str)
{
    int i = 0;
    int num = 0;
    bool isNeg = false;
    int len = str.length();

    if (str[0] == '-')
    {
        isNeg = true;
        i = 1;
    }

    while (i < len)
    {
        num *= 10;
        num += str[i++] - '0';
    }

    if (isNeg)
        num = -num;
    return num;
}
const int MAX_DIGITS = 10;
string intToString(int num)
{
    int i = 0;
    bool isNeg = false;
    char *temp = new char[MAX_DIGITS + 1];
    if (num < 0)
    {
        isNeg = true;
        num = -num;
    }
    while (num != 0)
    {
        temp[i++] = (char)((num % 10) + '0');
        num /= 10;
    }

    string *s = new string();
    if (isNeg)
        s->append("-");
    while (i > 0)
        s->push_back(temp[--i]);

    return *s;
}
int main()
{
    string s = "total";
    string s2 = "teeter";
    cout << findNonRepeatedChar(s) << endl;

    cout << findNonRepeatedChar(s2) << endl;
    cout << remove("The Battle of Hawaii", "aeiou") << endl;
    cout << strToInt("123") << endl;
    cout << strToInt("-123") << endl;
    cout << strToInt("0") << endl;
    cout << intToString(123) << endl;
    cout << intToString(-123) << endl;
}