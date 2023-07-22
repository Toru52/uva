10491 - Cows and Cars
concept
http://mathtrain.jp/monty
http://www.waka-macha.com/entry/2015/01/25/210025



https://github.com/morris821028/UVa/blob/master/volume104/10491%20-%20Cows%20and%20Cars.cpp



#include <stdio.h>

int main() {
	double cow, car, show;
	while (scanf("%lf %lf %lf", &cow, &car, &show) == 3) {
		double tot, left;
		tot = cow + car;
		left = tot - show - 1;
		printf("%.5lf\n", cow / tot * car / left +
			car / tot * (car - 1) / left);
	}
	return 0;
}


https://github.com/ajahuang/UVa/blob/master/UVa%2010491%20-%20Cows%20and%20Cars.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{    
    int NCOWS, NCARS, NSHOW;
    while (cin >> NCOWS >> NCARS >> NSHOW)
    {
        // Two cases.
        // 1.Pick a cow and switch to a car:
        //   NCOWS / (NCOWS + NCARS) 
        //   * NCARS / (NCOWS + NCARS - NSHOW - 1)
        // 2.Pick a car and switch to a car:
        //   NCARS / (NCOWS + NCARS)
        //   * (NCARS - 1) / (NCOWS + NCARS - NSHOW - 1)
        cout << setprecision(5)
             << fixed
             << ((double)NCARS * (NCOWS + NCARS - 1)) / ((NCOWS + NCARS) * (NCOWS + NCARS - NSHOW - 1))
             << endl;
    }
    return 0;
}



http://blog.csdn.net/xuziye0327/article/details/44549355
#include <cstdio>  
  
int main() {  
    double a, b, c;  
    while(~scanf("%lf%lf%lf", &a, &b, &c)) {  
        double res = (a * b + b * (b - 1)) / ((a + b) * (a + b - c - 1));  
        printf("%.5f\n", res);  
    }  
    return 0;  
} 



#include<stdio.h>
int main() {
	double a, b, c;
	while (~scanf("%lf%lf%lf", &a, &b, &c)) {
		double res =
			(b*(a + b - 1)) /
			((a + b)*(a + b - c - 1));
		printf("%.5f\n", res);
	}
	return 0;
}



In television contests, participants are often asked to choose one 
from a set of or doors for example, one or several of which lead to 
different prizes. In this problem we will deal with a speci c kind of 
such a contest. Suppose you are given the following challenge by the 
contest presenter:
In front of you there are three doors. Two of them hide a cow, 
the other one hides your prize - a car. After you choose a door, 
but before you open it, I will give you an hint, by opening one of 
the doors which hides a cow (I'll never open the door you have chosen,
 even if it hides a cow). You will then be able to choose 
 if you want to keep your choice, or 
 if you wish to change to the other unopened
door. You will win whatever is behind the door you open.
In this example, the probability you have of winning the car is 2/3 
(as hard as it is to believe), assuming you always switch your choice 
when the presenter gives you the opportunity to do so (after
he shows you a door with a cow). The reason of this number (2/3) is 
this - if you had chosen one of the two cows, you would surely 
switch to the car, since the presenter had shown you the other cow.
If you had chosen the car, you would switch to the remaining cow, 
therefore losing the prize. Thus, in two out of three cases 
you would switch to the car. The probability to win 
if you had chosen to stick with your initial choice would obviously 
be only 1/3, but that isn't important for this problem.
In this problem, you are to calculate the probability 
you have of winning the car, for a generalization
of the problem above:

The number of cows is variable

The number of cars is variable (number of cows + number of 
cars = total number of doors)

The number of doors hiding cows that the presenter opens for you 
is variable (several doors may still be open when you are given the 
opportunity to change your choice)
You should assume that you always decide to switch your choice to any 
other of the unopen doors
after the presenter shows you some doors with cows behind it.



Input
There are several test cases for your program to process. Each test 
case consists of three integers on a
line, separated by whitespace. Each line has the following format:
NCOWSNCARSNSHOW
Where
NCOWS
is the number of doors with cows,
NCARS
is the number of doors with cars and
NSHOW
is the number of doors the presenter opens for you before you choose 
to switch to another
unopen door.
The limits for your program are:
1

NCOWS

10000
1

NCARS

10000
0

NSHOW<NCOWS

Output
For each of the test cases, you are to output a line containing just 
one value - the probability of winning
the car assuming you switch to another unopen door, displayed to 5
decimal places.



SampleInput
2 1 1
5 3 2
2000 2700 900

SampleOutput
0.66667
0.52500
0.71056