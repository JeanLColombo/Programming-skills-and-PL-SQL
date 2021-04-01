#include <iostream>
#include <string>

using namespace std;

int stringSize(string userString)
{
    int i;

    for (auto c : userString)       // Foreach approach. Will loop until an empty char is found.
        i++;                        // Simple increment in each loop.

    return i;
}

void userInterface()                // User interface, for acquiring the string.
{
    string userString;

    cout << 
        "Please, insert a string here:\t";
    cin >> userString;

    cout << 
        "String size:\t" 
        << stringSize(userString)   // It also prints string size.
        << endl; 
}

int main() 
{  
    userInterface();
}