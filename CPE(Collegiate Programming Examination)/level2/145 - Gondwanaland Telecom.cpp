145 - Gondwanaland Telecom
http://blog.csdn.net/mobius_strip/article/details/43541171



#include <cstring>  
#include <cstdio>  
#include <cmath>  

double cost[5][4] = {
	0.02, 0.10, 0.06, 0.02,
	0.05, 0.25, 0.15, 0.05,
	0.13, 0.53, 0.33, 0.13,
	0.17, 0.87, 0.47, 0.17,
	0.30, 1.44, 0.80, 0.30 };

int used[1440];
int sums[5];
int cut[5] = { 0,480,1080,1320,1440 };
//0 10(600) 14(840) 24(1440) 12:00~08:00->Night rate
//->shift to 8hours lately->0 8(480) 18(1080) 22(1320) 24(1440)
	char ch, str[10];
	int  a, b, c, d;
	
	while (~scanf("%c", &ch) && ch != '#') {
		scanf("%s%d%d%d%d", str, &a, &b, &c, &d);
		getchar();
		memset(used, 0, sizeof(used));
		if (c * 60 + d <= a * 60 + b) {//0小时代表24小时   
			for (int i = 0; i < c * 60 + d; ++i)
				used[i] = 1;
			for (int i = a * 60 + b; i < 1440; ++i)
				used[i] = 1;
		}    //->   ---|   |---  for x<0,max<x
		else
			for (int i = a * 60 + b; i < c * 60 + d; ++i)
				used[i] = 1;   //   |---|  for 0<x<max

		for (int i = 0; i < 4; ++i) {
			sums[i] = 0;
			for (int j = cut[i]; j < cut[i + 1]; ++j)
				sums[i] += used[j];
		}
		sums[3] += sums[0];
		double sum = sums[1] * cost[ch - 'A'][1] + sums[2] * cost[ch - 'A'][2] + sums[3] * cost[ch - 'A'][3];

		printf("%10s%6d%6d%6d%3c%8.2lf\n", str, sums[1], sums[2], sums[3], ch, sum);
	}
	return 0;
}



#include<cstdio>

double rate[5][4] = {
	0.02,0.10,0.06,0.02,
	0.05,0.25,0.15,0.05,
	0.13,0.53,0.33,0.13,
	0.17,0.87,0.47,0.17,
	0.30,1.44,0.80,0.30 };
int minute[5] = { 0,480,1080,1320,1440 };

int main()
{
	char phone[10], CS;
	while (scanf("%c",&CS) && '#' != CS)
	{
		int a, b, c, d, sums[5] = {}, used[1440] = {};
		scanf("%s %d %d %d %d", &phone, &a, &b, &c, &d);
		getchar();

		if (a * 60 + b >= c * 60 + d) {
			for (int i = 0; i < c * 60 + d; i++)
				used[i] = 1;
			for (int i = a * 60 + b; i < 1440; i++)
				used[i] = 1;
		}
		else
			for (int i = a * 60 + b; i < c * 60 + d; i++)
				used[i] = 1;
		for (int i = 0; i < 4; i++) 
			for (int j = minute[i]; j < minute[i + 1]; j++)
				sums[i] += used[j];	
		sums[3] += sums[0];
		double total = sums[1] * rate[CS - 'A'][1] + sums[2] * rate[CS - 'A'][2] + sums[3] * rate[CS - 'A'][3];
		printf("%10s%6d%6d%6d%3c%8.2lf\n", phone, sums[1], sums[2], sums[3],CS, total);
	}
}



Gondwanaland Telecom makes charges for calls according to 
distance and time of day. The basis of the charging is 
contained in the following schedule, where the charging step 
is related to the distance:
tabular21
All charges are in dollars per minute of the call. 
Calls which straddle a rate boundary are charged according to 
the time spent in each section. Thus a call starting at 
5:58 pm and terminating at 6:04 pm will be charged for 
2 minutes at the day rate and for 4 minutes at the evening rate. 
Calls less than a minute are not recorded and no call may last 
more than 24 hours.
Write a program that reads call details and calculates the 
corresponding charges.



Input and Output
Input lines will consist of the charging step (upper case 
letter 'A'..'E'), the number called (a string of 7 digits 
and a hyphen in the approved format) and the start and 
end times of the call, all separated by exactly one blank. 
Times are recorded as hours and minutes in the 24 hour clock, 
separated by one blank and with two digits for each number. 
Input will be terminated by a line consisting of a single #.

Output will consist of the called number, the time in minutes 
the call spent in each of the charge categories, the charging 
step and the total cost in the format shown below.



Sample input
A 183-5724 17 58 18 04
#
Sample output
183-5724 2 4 0 A 0.44



Sample input
place  phone number  start time  end time 
A      183-5724      17 58       18 04
#
Sample output
phone number  time(DayRate)  time(Evening)  time(Night)  place   total
183-5724      2              4              0            A       0.44

2*0.1+4*0.06=0.44


MEGA PUNCH