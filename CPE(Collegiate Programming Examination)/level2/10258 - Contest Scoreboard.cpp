10258 - Contest Scoreboard
http://knightzone.org/?p=1483



#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;

struct Team {int num,score,problem,error[10];};

bool compare(Team a, Team b) {
	if (a.problem > b.problem) return true;
	if (a.problem < b.problem) return false;
	//if a.problem=b.problem
	if (a.score < b.score) return true;
	if (a.score > b.score) return false;
	//if a.score=b.score
	if (a.num < b.num) return true;
	return false;
}
int main() {
	string entry;
	int n,contestant, problem, time;
	char L;

	while (~scanf("%d ", &n)) {
		for (int i = 0; i < n; i++) {
			Team teams[105] = {};
			if (i) printf("\n");
			while (getline(cin, entry) && entry != "") {
				stringstream ss;
				ss.str(entry);
				ss >> contestant >> problem >> time >> L;
				teams[contestant].num = contestant;
                
				//It's no score even if samecontestant correct same problem
				if (teams[contestant].error[problem] == -1) 
					continue;
				if (L == 'C') {
					teams[contestant].score += time + teams[contestant].error[problem] * 20;
					teams[contestant].problem++;
					teams[contestant].error[problem] = -1;
						}
				else if (L == 'I')
					teams[contestant].error[problem]++;
			}
			sort(teams, teams + 105, compare);
			for (int j = 0; j < 105; j++)
				if (teams[j].num)
					printf("%d %d %d\n", teams[j].num, teams[j].problem, teams[j].score);
		}
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<sstream>
#include<string.h>
using namespace std;
struct team { int num, problem, score, error[10]; };
int comp(team a, team b) {
	if (a.problem > b.problem)return true;
	if (a.problem < b.problem)return false;
	if (a.score < b.score)return true;
	if (a.score > b.score)return false;
	if (a.num < b.num)return true;
	return false;
}
int main() {
	int n, time, contestant, problem;
	char L;
	string entry;
	while (~scanf("%d ",&n)) {
		for (int i = 0; i < n; i++) {
			if (i)puts("");
			team teams[105] = {};
			while (getline(cin, entry), entry != "") {
				stringstream ss;
				ss << entry;
				ss >> contestant >> problem >> time >> L;
				teams[contestant].num = contestant;

				if (teams[contestant].error[problem] == -1)
					continue;
				if (L == 'C') {
					teams[contestant].score += time + teams[contestant].error[problem] * 20;
					teams[contestant].problem++;
					teams[contestant].error[problem] = -1;
				}
				if (L == 'I')
					teams[contestant].error[problem]++;
			}
			sort(teams, teams + 105, comp);
			for (int j = 0; j < 105; j++)
				if(teams[j].num)
					printf("%d %d %d\n", teams[j].num, teams[j].problem, teams[j].score);
		}
	}
	return 0;
}



Think the contest score boards are wrong? Here's your chance to 
come up with the right rankings. Contestants are ranked  rst by 
the number of problems solved (the more the better), then by
decreasing amounts of penalty time. If two or more contestants are 
tied in both problems solved and penalty time, they are displayed 
in order of increasing team numbers.
A problem is considered solved by a contestant 
if any of the submissions for that problem was judged
correct. Penalty time is computed as the number of minutes it took 
for the  rst correct submission for a problem to be received plus 
20 minutes for each incorrect submission received prior to the 
correct solution. Unsolved problems incur no time penalties.



Input
The input begins with a single positive integer on a line by itself 
indicating the number of the cases
following, each of them as described below. 
This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
Input consists of a snapshot of the judging queue, 
containing entries from some or all of contestants
1 through 100 solving problems 1 through 9. 
Each line of input will consist of three numbers and a
letter in the format contestant problem time L
where
L
can be `
C
', `
I
', `
R
', `
U
' or `
E
'. These stand for
C
orrect,
I
ncorrect, clari cation
R
equest,
U
njudged
and
E
rroneous submission. The last three cases do not affect scoring.
Lines of input are in the order in which submissions were received.
Output
For each test case, the output must follow the description below. 
The outputs of two consecutive cases
will be separated by a blank line.
Output will consist of a scoreboard sorted as previously described. 
Each line of output will contain a contestant number, 
the number of problems solved by the contestant and the time 
penalty accumu-lated by the contestant. 
Since not all of contestants 1-100 are actually participating, 
display only the contestants that have made a submission.



SampleInput
1
1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C

SampleOutput
1 2 66
3 1 11