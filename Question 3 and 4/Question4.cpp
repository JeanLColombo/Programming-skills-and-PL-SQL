#include "Question3.cpp"
#include <iostream>
#include <cassert>

using namespace std;

void TestRemoveSpaces()
{
    string s = "a b c   d";
    string t = RemoveSpaces(s);
    assert(t == "abcd");
}

void TestRemoveUntilInsideRemainsEqual()
{
    string s = "abc";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i == t);
}

void TestRemoveUntilInsideRemovesNothing()
{
    string s = "abc";
    string t = "abcd";

    string i = RemoveUntilInside(s,t);
    assert(i == s);
}

void TestRemoveUntilInsideRemovesChars()
{
    string s = "abcd";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i == t);
}

void TestRemoveUntilInsideRemovesAllChars()
{
    string s = "dabc";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i.empty());
}

void TestRemoveUntilInsideReturnsEmpty()
{
    string s = "";
    string t = "abc";

    string i = RemoveUntilInside(s,t);
    assert(i.empty());
}

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

void TestConcatRemoveIsNo()
{
    string s = "bla bla bla bla";
    string t = "blablabcde";
    int k = 4;

    assert(ConcatRemove(s,t,k) == "no");
}

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