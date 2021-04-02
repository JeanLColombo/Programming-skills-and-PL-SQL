# Question 3 and 4



## Question 3



Develop a **C/C++** or **Java** language program that implements and uses the **ConcatRemove (s, t, k)** function. It should return the results 'yes' or 'no'.
The function has the following parameters:
**s**: starting string
**t**: desired string
**k**: an integer that represents the number of operations

## Question 4

Write an Unit Test using C/C++ or Java for the function **ConcatRemove(s,t,k)**.

## Solutions

Due to the nature of the questions, both were implemented simultaneously.

### Question 3

Two functions were implemented to solve the problem: `RemoveUntilInside(s,t)` and `ConcatRemove(s,t,k)`.

`RemoveUntilInside(s,t)` is a function that removes characters from the end of `s` until it becomes equal to `t`, or it becomes empty. This way, it can verify if `s` starts equal to `t`.

```c++
string RemoveUntilInside(string s, string t)
{
    while (t.find(s) != 0 && !s.empty())
        s.pop_back();

    return s;
}
```

Then, `ConcatRemove(s,t,k)` checks if is possible to do the permutations in `k` operations, by comparing the lengths of `s`, `t` and the result of `RemoveUntilInside(s,t)`.

```c++
string ConcatRemove(string s,string t,int k)
{
    s = RemoveSpaces(s);
    t = RemoveSpaces(t);
    
    string popedString = RemoveUntilInside(s,t);

    int numberOfOperations = 
        s.length() 
        + t.length() 
        - (2*popedString.length());

    return numberOfOperations <= k ? "yes" : "no";
}
```

`numberOfOperations` is the sum of the lengths of `s` and `t`, subtracted by 2 times the length of `RemoveUntilInside(s,t)` `s return variable. This represents the total number of operations necessary to solve the permutations.

The ternary operator checks if is possible to return do the permutations in `k` or more steps.

The following helper function `RemoveSpaces(str)` was implemented to remove spaces.

```c++
static string RemoveSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
```

Since `s` and `t` were always lowercase chars, no method was implemented to deal with uppercase.

### Question 4

For simplicity, question 4 was implemented as an executable. The `cassert` library was used for testing.

9 unit tests were implemented, to fully test `ConcatRemove(s,t,k)` under various circumstances. These testes were then included into the `main()` function, as follows:

```c++
int main()
{
    TestRemoveSpaces();
    TestRemoveUntilInsideRemainsEqual();
    TestRemoveUntilInsideRemovesNothing();
    TestRemoveUntilInsideRemovesChars();
    TestRemoveUntilInsideRemovesAllChars();
    TestRemoveUntilInsideReturnsEmpty();
    TestConcatRemoveExample1();
    TestConcatRemoveExample2();
    TestConcatRemoveIsNo();
}
```



`TestRemoveSpaces()` checks if spaces are being correctly removed.

```c++
void TestRemoveSpaces()
{
    string s = "a b c   d";
    string t = RemoveSpaces(s);
    assert(t == "abcd");
}
```

`TestRemoveUntilInsideRemainsEqual()` checks if  `RemoveUntilInside(s,t)` does nothing if strings are equal.

```c++
void TestRemoveUntilInsideRemainsEqual()
{
    string s = "abc";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i == t);
}
```

`TestRemoveUntilInsideRemovesNothing()` checks the behavior if `s` is equal to the beginning of `t`, when `t!=s`.

```c++
void TestRemoveUntilInsideRemovesNothing()
{
    string s = "abc";
    string t = "abcd";

    string i = RemoveUntilInside(s,t);
    assert(i == s);
}
```

`TestRemoveUntilInsideRemovesChars()` checks if `s` ‘s lasts chars are removed, until `s==t`

```c++
void TestRemoveUntilInsideRemovesChars()
{
    string s = "abcd";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i == t);
}
```

`TestRemoveUntilInsideRemovesChars()` checks if `s` is completely emptied. 

```c++
void TestRemoveUntilInsideRemovesChars()
{
    string s = "abcd";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i == t);
}
```

`TestRemoveUntilInsideReturnsEmpty()` checks the behavior if `s` is already empty.

```c++
void TestRemoveUntilInsideReturnsEmpty()
{
    string s = "";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i.empty());
}
```

 Then, both examples giver were tested, separately:

```c++
void TestConcatRemoveExample1()
{
    string s = "bla bla bla bla";
    string t = "blablabcde";
    int k = 8;

    assert(ConcatRemove(s,t,k) == "yes");
}

void TestConcatRemoveExample2()
{
    string s = "tab";
    string t = "tab";
    int k = 7;

    assert(ConcatRemove(s,t,k) == "yes");
}
```

And finally, a negative test is implemented:

```c++
void TestConcatRemoveIsNo()
{
    string s = "bla bla bla bla";
    string t = "blablabcde";
    int k = 4;

    assert(ConcatRemove(s,t,k) == "no");
}
```

## Usage

Compile `Question4.cpp`, and then run the following line on command prompt.

```shell
.\Question4.exe
```

