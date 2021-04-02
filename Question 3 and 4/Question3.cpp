#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static string RemoveSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string RemoveUntilInside(string s, string t)
{
    while (t.find(s) != 0 && !s.empty())
        s.pop_back();

    return s;
}

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
