# Question 8

Upload into your **Github / Gitlab** or **Bitbucket** account a solution for the following problems:

**Problem #1**
I have a relation ABC. 

What are the sequence of commands to determine its structure?

**Problem #2**

What are the sequence of commands to read the first and last records of relation XYZ?

**Problem #3**

Continuing with relation XYZ

What are the sequence of commands to read key value 10 and the next 2 records?

## Solution

Just implement the following commands in a bash terminal.

**Problem #1**

```bash
bq
rel ABC 
di
x
```



**Problem #2**

```bash
bq
rel XYZ 
re f
re l
x
```



**Problem #3**

```bash
bq
rel XYZ 
key 10
re n
re n
x
```

