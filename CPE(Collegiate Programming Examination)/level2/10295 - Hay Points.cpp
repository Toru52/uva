10295 - Hay Points



#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int m, n, doller;
	map <string, int> msi;
	string word;
	scanf("%d%d ", &m, &n);
	while (m--){
		cin >> word >> doller;
		msi[word] = doller;
	}
	while (n--){
		long long int points = 0;
		while (cin >> word,word!=".")
			if (msi.find(word) != msi.end()) 
				points += msi[word];
		printf("%lld\n", points);
	}
	return 0;
}



#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	int m, n, p;
	map<string, int>rec;
	string word;
	scanf("%d %d ", &m, &n);
	for (int i = 0; i < m; i++) {
		cin >> word >> p;
		rec[word] = p;
	}
	for (int i = 0; i < n; i++) {
	    long long int scores=0;
		while (cin >> word, word != ".")
			if (rec.find(word) != rec.end())
				scores += rec[word];
		printf("%lld\n", scores);
	}
	return 0;
}



Each employee of a bureaucracy has a
job  de-
scription
| a few paragraphs that describe the
responsibilities of the job. The employee's job
description, combined with other factors, such as
seniority, is used to determine his or her salary.
The
Hay Point
system frees the Human Re-
sources department from having to make an in-
telligent judgement as to the value of the em-
ployee; the job description is merely scanned for
words and phrases that indicate responsibility.
In particular, job descriptions that indicate con-
trol over a large budget or management over a large number of people 
yield high Hay Point scores.
You are to implement a simpli ed Hay Point system. 
You will be given a Hay Point dictionary and a number of job 
descriptions. For each job description you are to compute the salary 
associated with the job, according to the system.



Input
The  rst line of input contains 2 positive integers:
m

1000, the number of words in the Hay Point
dictionary, and
n

100, the number of job descriptions.
m
lines follow; each contains a word (a string
of up to 16 lower-case letters) and a dollar value (a real number 
between 0 and 1,000,000). Following
the dictionary are the n
job descriptions. Each job description consists of one or more lines 
of text; for your convenience the text has been converted to lower 
case and has no characters other than letters,
numbers, and spaces. Each job description is terminated by a line 
containing a period.

Output
For each job description, output the corresponding salary computed 
as the sum of the Hay Point values for all words that appear in the 
description. Words that do not appear in the dictionary have a value
of `0'.



SampleInput
7 2
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
the incumbent will administer the spending of kindergarden milk 
money and exercise responsibility for making change he or she will 
share responsibility for the task of managing the money with the 
assistant whose skill and expertise shall ensure the successful
spending exercise. this individual must have the skill to perform a 
heart transplant and expertise in rocket science.

SampleOutput
700150
150