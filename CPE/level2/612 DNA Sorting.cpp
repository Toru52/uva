612	DNA Sorting



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct DNA {
	string sequence;
	int inverse;
	int id;

	DNA(string s, int inputID) {
		sequence = s;
		inverse = 0;
		id = inputID;

		int count[26] = { 0 };
		for (int i = 0; i < s.length(); ++i) {
			for (int j = s[i] - 'A' + 1; j < 26; ++j) {
				inverse += count[j];
			}

			++count[s[i] - 'A'];
		}
	}
};

bool cmpDNA(const DNA &a, const DNA &b) {
	return (a.inverse < b.inverse) || (a.inverse == b.inverse && a.id < b.id);
}

int main() {
	int M;
	while (scanf("%d", &M) != EOF) {
		for (int caseNumber = 0; caseNumber < M; ++caseNumber) {
			if (caseNumber > 0) {
				printf("\n");
			}

			int n, m;
			scanf("%d%d", &n, &m);

			vector<DNA> DNAs;
			for (int i = 0; i < m; ++i) {
				string input;
				cin >> input;

				DNA dna(input, i);
				DNAs.push_back(dna);
			}

			sort(DNAs.begin(), DNAs.end(), cmpDNA);

			for (int i = 0; i < DNAs.size(); ++i) {
				printf("%s\n", DNAs[i].sequence.c_str());
			}

		}
	}
	return 0;
}



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct DNA {
	int sum, id;
	string seq;

	DNA(string s, int ID) {
		sum = 0;
		id = ID;
		seq = s;
		int cnt[26] = {};
		for (int i = 0; i < s.length(); i++) {
			for (int j = seq[i] - 'A' + 1; j < 26; j++)
				sum += cnt[j];
			++cnt[seq[i]-'A'];
		}
	}
};

bool cmpDNA(DNA &a, DNA &b) {
	return (a.sum < b.sum) || ((a.sum == b.sum)&&(a.id < b.id));
}

int main() {
	int M,m,n;
	scanf("%d", &M);
	
	for (int cas = 1; cas <= M; cas++) {
		if (cas > 1)
			puts("");
		scanf("%d %d", &n, &m);

		vector<DNA>DNAs;
		string str;
		for (int i = 0; i < m; i++) {
			cin >> str;
			DNA dna(str, i);
			DNAs.push_back(dna);
		}
		sort(DNAs.begin(), DNAs.end(), cmpDNA);
		for (int i = 0; i < DNAs.size(); i++)
			printf("%s\n", DNAs[i].seq.c_str());
	}
}




One measure of “unsortedness” in a sequence is the number of pairs 
of entries that are out of order with respect to each other. 
For instance, in the letter sequence “DAABEC”, this measure is 5, 
since D is greater than four letters to its right and E is greater 
than one letter to its right. This measure is called the number of 
inversions in the sequence. The sequence “AACEDGG” has only one 
inversion (E and D) — it is nearly sorted — while the sequence 
“ZWQM” has 6 inversions (it is as unsorted as can be — exactly the 
reverse of sorted).You are responsible for cataloguing a sequence 
of DNA strings (sequences containing only the four letters A, C, G, 
and T). However, you want to catalog them, not in alphabetical 
order, but rather in order of “sortedness”, from “most sorted” to 
“least sorted”. All the strings are of the same length.



Input
The first line of the input is an integer M, then a blank line 
followed by M datasets. There is a blank line between datasets.
The first line of each dataset contains two integers: a positive 
integer n (0 < n ≤ 50) giving the length of the strings; and a 
positive integer m (0 < m ≤ 100) giving the number of strings. 
These are followed by m lines, each containing a string of length n.

Output
For each dataset, output the list of input strings, arranged from 
“most sorted” to “least sorted”. If two or more strings are equally 
sorted, list them in the same order they are in the input file.
Print a blank line between consecutive test cases.



Sample Input
1
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA