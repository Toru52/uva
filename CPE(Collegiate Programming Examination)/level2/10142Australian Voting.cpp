10142	Australian Voting
http://mypaper.pchome.com.tw/zerojudge/post/1323220878



#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	getchar();
	while (t--) {
		scanf("%d", &n);
		getchar();
		string name[25], line;
		int vote[1005][25];
		for (int i = 1; i <= n; i++)
			getline(cin, name[i]);
		int m = 0;
		while (getline(cin, line),line!="") {
			stringstream sin;
			sin << line;
			int j = 0;
			while (sin >> vote[m][j])
				j++;
			m++;
		}
		
		int rank[1005] = {}, fire[25] = {};
		while (1) {
			int p[25] = {}, tot = 0;
			for (int i = 0; i < m; i++) {
				printf("i %d\n", i);
				while (rank[i] < n && fire[vote[i][rank[i]]])
					rank[i]++;
				if (rank[i] < n) {
					p[vote[i][rank[i]]]++;
					tot++;
					printf("p[%d]=%d Idx[i] =%d\n", vote[i][rank[i]], p[vote[i][rank[i]]],rank[i]);
				}
			}
			printf("tot %d\n\n", tot);
			int half = tot / 2 + tot % 2;

			int mx = 0, mi = 0xffff;
			for (int i = 1; i <= n; i++) {
				if (!fire[i]) {
					if (p[i] > mx)
						mx = p[i];
					if (p[i] < mi)
						mi = p[i];
				}
			}
			if (mx == mi || mx >= half) {
				for (int i = 1; i <= n; i++)
					if (p[i] == mx)
						cout << name[i] << endl;
				break;
			}
			for (int i = 1; i <= n; i++)
				if (p[i] == mi)
					fire[i] = 1;
		}
		if (t)
			puts("");
	}
	return 0;
}



#include<iostream>
#include<sstream>
using namespace std;
int main() {
	int n, cas;
	scanf("%d", &cas);
	getchar();
	while (cas--) {
		int vote[1005][25],voter = 0;
		string name[25], line;
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; i++)
			getline(cin, name[i]);
		while (getline(cin, line), line != "") {
			stringstream ss;
			ss << line;
			int j = 0;
			while (ss >> vote[voter][j])
				j++;
			voter++;
		}
		int fire[25] = {}, rank[1005] = {};
		while (1) {
			int tot = 0, p[25] = {};
			for (int i = 0; i < voter; i++) {
				while (rank[i] < n&&fire[vote[i][rank[i]]])
					rank[i]++;
				if (rank[i] < n) {
					p[vote[i][rank[i]]]++;
					tot++;
				}
			}
			int half = tot / 2 + tot % 2;
			int mi = 0xffff, mx = 0;
			for (int i = 1; i <= n; i++) 
				if (!fire[i]) {
					if (mx < p[i])
						mx = p[i];
					if (mi > p[i])
						mi = p[i];
				}
			if (mi == mx || half <= mx) {
				for (int i = 1; i <= n; i++)
					if (p[i] == mx)
						cout << name[i] << endl;
				break;
			}
			for (int i = 1; i <= n; i++)
				if (p[i] == mi)
					fire[i] = 1;
		}
		if (cas)
			puts("");
	}
	return 0;
}



Australian ballots require that the voter rank the candidates 
in order of choice. Initially only the  rst choices are 
counted and if one candidate receives more than 50% of the 
vote, that candidate is elected. If no candidate receives more 
than 50%, all candidates tied for the lowest number of votes 
are eliminated. Ballots ranking these candidates  rst are 
recounted in favour of their highest ranked candidate who
has not been eliminated. This process continues [that is, the 
lowest candidate is eliminated and each ballot is counted in 
favour of its ranked non-eliminated candidate] until one 
candidate receives more than 50% of the vote or until all 
candidates are tied.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases following, 
each of them as described below. This line is followed by a 
blank line, and there is also a blank line between two 
consecutive inputs. The  rst line of input is an integer
n

20 indicating the number of candidates. The next n lines
consist of the names of the candidates in order. 
Names may be up to 80 characters in length and may
contain any printable characters. Up to 1000 lines follow; 
each contains the contents of a ballot.
That is, each contains the numbers from 1 to n in some order. 
The  rst number indicates the candidate of rst choice; 
the second number indicates candidate of second choice, 
and so on.

Output
For each test case, the output must follow the description 
below. The outputs of two consecutive cases
will be separated by a blank line.
The Output consists of either a single line containing the 
name of the winner or several lines
containing the names of the candidates who tied.



SampleInput
1
3
John Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2

SampleOutput
John Doe