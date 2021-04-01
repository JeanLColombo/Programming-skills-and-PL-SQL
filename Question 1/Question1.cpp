#include <iostream>
#include <string>

int printNum(int num = 1, int maxNum = 100)
{
    using namespace std;
    string str;                 // local variable, destroyed after usage

    if (num % 3 == 0)           // Checks it num is multiple of 3;
        str.append("Foo");      // Appends "Foo" to str;

    if (num % 5 == 0)           // Checks it num is multiple of 5;
        str.append("Baa");      // Appends "Baa" to str;
    
    if (str.empty())
        cout << num << endl;    // If str is empty, print num;
    else    
        cout << str << endl;    // Print str otherwise.

    if (num >= 100)
        return 0;
    else
        return printNum(++num);
}

int main()
{
    printNum();                // num is passed by value.
}