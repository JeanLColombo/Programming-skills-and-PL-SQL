# Question 9

Make a program in **C/C++** or **Java** language that calculates the length of a string informed by the user (**do not use any pre-existing function** or method for this, such as *len()*, *count()*, *strlen()* or *lenght()*).

## Solution

For this exercise, the following approach was implemented:

```c++
int stringSize(string userString)
{
    int i;

    for (auto c : userString)       // Foreach approach. Will loop until an empty char is found.
        i++;                        // Simple increment in each loop.

    return i;
}
```

An user interface function was also implemented, for sake of simplicity:

```c++
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
```

## Usage

Run the following line on command prompt.

```shell
.\Question9.exe
```

