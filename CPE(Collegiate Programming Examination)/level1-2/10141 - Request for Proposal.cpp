10141 - Request for Proposal



#include <iostream>    
#include <string>   
using namespace std;

string P[1001], temp, name, ans;

int main()
{
	int n, p, T = 0;
	while (~scanf("%d%d", &n, &p) && n) {
		getchar();

		for (int i = 0; i < n; ++i)
			getline(cin, P[i]);

		int  maxm = 0, count, number;
		double  cost = 0.0, price;
		for (int i = 0; i < p; ++i) {
			getline(cin, name);
			scanf("%lf%d", &price, &number);
			getchar();
			count = 0;
			for (int j = 0; j < number; ++j) {
				getline(cin, temp);
				count++;
			}
			if (maxm == count && cost > price) {
				cost = price;
				ans = name;
			}
			if (maxm < count) {
				maxm = count;
				cost = price;
				ans = name;
			}
		}

		if (T++)
			printf("\n");
		cout << "RFP #" << T << endl;
		cout << ans << endl;
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, p,cas=0;

	while (~scanf("%d %d", &n, &p) && n)
	{
		getchar();
		string req[1005] = {}, REQ, proposal, best;
		for (int i = 0; i < n; i++)
			getline(cin, req[i]);
		float price,cost=0.0;
		int r, max = 0;
		for (int i = 0; i < p; i++)
		{
			int cnt = 0;
			getline(cin, proposal);
			scanf("%f %d", &price, &r);
			getchar();
			for (int j = 0; j < r; j++)
				getline(cin, REQ), cnt++;
			if (cnt == max&&price < cost)
			{
				cost = price;
				best = proposal;
			}
			if (cnt > max)
			{
				max = cnt;
				best = proposal;
				cost = price;
			}
		}
			
		if (cas++)
			puts("");
		cout << "RFP #" << cas << endl;
		cout << best << endl;
	}
}



Algorithm
9 degrees per a memory(360/40)
 turn the dial clockwise 2 full turns       ->720 degrees
 turn the dial counter-clockwise 1 full turn->360 degrees
 So initialize degrees are 1080 degrees

 
 
When government, military, or commercial agencies wish to 
make a major purchase, they first issue a Request for 
Proposal (RFP) which lists a number of requirements that 
must be met by a successful proposal. Competing suppliers 
issue Proposals, indicating which of the requirements are 
met, and a price that will be charged should the proposal 
be accepted by the agency issuing the RFP. Because the 
agencies are staffed by bureaucrats and are accountable to 
other agencies staffed by bureaucrats, it is necessary to 
remove all human judgement from the selection process. 
To this end, those evaluating the proposals are given 
feature sheets, which have one column for each requirement
and and additional column for price, and one row for each 
Proposal. The evaluator reads each proposal
and identifies each requirement that is met; 
for each such requirement a check mark is placed in the
corresponding row (for the Proposal) and column (for the 
requirement). After all proposals have been evaluated, 
the number of check marks in each row is added. 
Any proposal that has the same number of check marks as the 
number of requirements is said to be compliant; otherwise 
the proposal is said to be partially compliant. 
Many agencies award the contract to the lowest compliant 
proposal; that is the compliant proposal with the lowest 
price. If there is no compliant proposal, many agencies 
evaluate partial compliance according to the 
following formula:
compliance =
number−of−requirements−met
number−of−requirements
Your job is to select the Proposal with the highest 
compliance; if several proposals have the same
compliance you are to select from these proposals the one 
with the lowest price. If several proposals
have the same compliance and price you are to select the 
first one in the input.



Input
Your input will consist of the information for a number of 
RFPs and associated proposals. The information
for each RFP will consist of:

• a line containing two integers: 0 < n ≤ 1000, the number 
of requirements, and p the number of proposals. 
The line 0 0 indicates there are no more RFPs.

• n lines naming the requirements. Each requirement is a 
string up to 80 characters long, terminated by the end 
of line. All strings are case sensitive.

• for each of the p proposals:
– a line naming the proposal (up to 80 characters 
terminated by end of line)
– a line containing a floating point number d and an 
integer 0 ≤ r ≤ n: d is the price; r is the
number of met requirement lines to follow.
– for each met requirement, the name of the requirement, 
each on a separate line. All requirements
are from the RFP requirement list, and no requirements are 
duplicated.

Output
For each RFP, give the number of the RFP (see sample) 
followed by the name of the best proposal,
optimizing the criteria given above. Leave a blank line 
between the output for each pair of RFPs.



Sample Input
6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer

Chevrolet
20000.00 3
engine
tires
brakes

Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine

Hyundai
10000.00 3
engine
tires
ashtray

Lada
6000.00 1
tires
1 1
coffee

Starbucks
1.50 1
coffee
0 0

Sample Output
RFP #1
Cadillac
RFP #2
Starbucks



Explain

Sample Input
6 4
engine      <-"naming the requirements" <-Just declaration,no mean what to do
brakes
tires
ashtray
vinyl roof
trip computer

Chevrolet   <-"the name of the proposal" is written on the price
20000.00 3
engine      <-"naming the requirements"
tires
brakes

Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine

Hyundai
10000.00 3
engine
tires
ashtray

Lada
6000.00 1
tires
1 1
coffee

Starbucks
1.50 1
coffee
0 0

Sample Output
RFP #1
Cadillac
RFP #2
Starbucks