12439 - February 29



#include<iostream>
#include<string>
using namespace std;

int main() {
	string month;
	int day, year,t1,t2,T;

	while (scanf("%d", &T) != EOF) {
		for (int i = 1; i <= T; i++) {
			cin >> month;
			scanf("%d, %d", &day, &year);
			if ((month[0] == 'J' && month[1] == 'a') || month[0] == 'F') 
				year--;
			t1 = year / 4 - year / 100 + year / 400;
			cin >> month;
			scanf("%d, %d", &day, &year);
			if ((month[0] == 'J' && month[1] == 'a') || month[0] == 'F') 
				year--;
			if (month[0] == 'F' && day == 29) 
				year++;
			t2 = year / 4 - year / 100 + year / 400;
			printf("Case %d: %d\n", i, t2 - t1);
		}
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,d,y,t1,t2;
	string m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		scanf("%d, %d", &d, &y);
		if (m[0] == 'J'&&m[1] == 'a' || m[0] == 'F')
			y--;
		t1 = y / 4 - y / 100 + y / 400;

		cin >> m;
		scanf("%d, %d", &d, &y);
		if (m[0] == 'J'&&m[1] == 'a' || m[0] == 'F')
			y--;
		if (m[0] == 'F'&&d == 29)
			y++;
		t2 = y / 4 - y / 100 + y / 400;
		printf("Case %d: %d\n", i, t2 - t1);
	}
}



hints
(month[0] == 'J' && month[1] == 'a') || month[0] == 'F') 
->since  January and February<February 29th



It is 2012, and it’s a leap year. So there is a 
“February 29” in this year, which is called leap day.
Interesting thing is the infant who will born in this 
February 29, will get his/her birthday again in
2016, which is another leap year. So February 29 only 
exists in leap years. Does leap year comes in
every 4 years? Years that are divisible by 4 are leap 
years, but years that are divisible by 100 are not
leap years, unless they are divisible by 400 in which 
case they are leap years. In this problem, 
you will be given two different date. 
You have to find the number of leap days in between them.



Input
The first line of input will contain T (≤ 500) denoting 
the number of cases.Each of the test cases will have two 
lines. First line represents the first date and second 
line represents the second date. Note that, the second 
date will not represent a date which arrives earlier
than the first date. The dates will be in this 
format — ‘month day, year’. See sample input for exact
format. You are guaranteed that dates will be valid and 
the year will be in between 2 ∗ 103 to 2 ∗ 109.
For your convenience, the month list and the number of 
days per months are given below. You can
assume that all the given dates will be a valid date.

Output
For each case, print the case number and the number of 
leap days in between two given dates (inclusive).
Note:
The names of the months are 
{“January”, “February”, “March”, “April”, “May”, “June”, 
“July”,“August”, “September”, “October”, “November” 
and “December”}. And the numbers of days for the months are
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 and 31} 
respectively in a non-leap year. In a leap year, 
number of days for February is 29 days; others are same 
as shown in previous line.
 
 
 
Sample Input
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012

Sample Output
Case 1: 1
Case 2: 0
Case 3: 1
Case 4: 3