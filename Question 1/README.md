# Question 1

**Consider the following problem:**  Write a **C/C++** or **Java** program that prints each number from 1 to 100 on a new line.  For each multiple of 3, print "Foo" instead of the number. For each multiple of 5, print "Baa" instead of the number. For multiple numbers simultaneously of 3 and 5, print "FooBaa", instead of the number.  Your solution should be using as few lines of code as possible, but you should produce efficient code.

## Solution

For this question, we implemented a function called `printNum(int)`:

```c++
int printNum(int num)
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
```

## Usage

Run the following line on command prompt.

```shell
.\Question1.exe
```

