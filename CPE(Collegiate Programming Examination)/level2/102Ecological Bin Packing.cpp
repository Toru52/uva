102	Ecological Bin Packing



#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int brown[5], green[5], clear[5];
	int move[10];
	const string answer[10] = { "BCG", "BGC",
		"CBG", "CGB",
		"GBC", "GCB" };
	int min_index;
	while (scanf("%d", &brown[0]) != EOF) {
		scanf("%d%d%d%d%d%d%d%d", &green[0], &clear[0]
			, &brown[1], &green[1], &clear[1] 
			, &brown[2], &green[2], &clear[2]);
		move[0] = brown[1] + brown[2] + green[0] + green[1] + clear[0] + clear[2];
		move[1] = brown[1] + brown[2] + green[0] + green[2] + clear[0] + clear[1];
		move[2] = brown[0] + brown[2] + green[0] + green[1] + clear[1] + clear[2];
		move[3] = brown[0] + brown[1] + green[0] + green[2] + clear[1] + clear[2];
		move[4] = brown[0] + brown[2] + green[1] + green[2] + clear[0] + clear[1];
		move[5] = brown[0] + brown[1] + green[1] + green[2] + clear[0] + clear[2];

		min_index = 0;
		for (int i = 1; i < 6; i++)
			if (move[i] < move[min_index])
				min_index = i;
		printf("%s %d\n", answer[min_index].c_str(), move[min_index]);

	}
	return 0;
}



#include<iostream>

int main()
{
	std::string type[] = {"BGC","BCG","GBC","GCB","CGB","CBG"};
	int move[6], B[3], G[3], C[3];

	while (~scanf("%d", &B[0]))
	{
		scanf("%d %d %d %d %d %d %d %d", &G[0], &C[0], &B[1], &G[1], &C[1], &B[2], &G[2], &C[2]);
		move[0] = G[0] + C[0] + B[1] + C[1] + B[2] + G[2];//BGC
		move[1] = G[0] + C[0] + B[1] + G[1] + B[2] + C[2];//BCG
		move[2] = B[0] + C[0] + G[1] + C[1] + B[2] + G[2];//GBC
		move[3] = B[0] + C[0] + B[1] + G[1] + G[2] + C[2];//GCB
		move[4] = B[0] + G[0] + C[1] + B[1] + C[2] + G[2];//CGB
		move[5] = B[0] + G[0] + C[1] + G[1] + C[2] + B[2];//CBG

		int min = 0;
		for (int i = 1; i < 6; i++)
			if (move[i] < move[min])
				min = i;
		printf("%s %d\n", type[min].c_str(), move[min]);
	}
}




Background

Bin packing, or the placement of objects of certain 
weights into different bins subject to certain 
constraints, is an historically interesting problem. 
Some bin packing problems are NP-complete but are 
amenable to dynamic programming solutions or to 
approximately optimal heuristic solutions.
In this problem you will be solving a bin packing 
problem that deals with recycling glass.

The Problem
Recycling glass requires that the glass be separated by 
color into one of three categories: brown glass, green 
glass, and clear glass. In this problem you will be given 
three recycling bins, each containing a specified number 
of brown, green and clear bottles. In order to be recycled,
the bottles will need to be moved so that each bin 
contains bottles of only one color.
The problem is to minimize the number of bottles that are 
moved. You may assume that the only problem is to 
minimize the number of movements between boxes.
For the purposes of this problem, each bin has infinite 
capacity and the only constraint is moving the bottles so 
that each bin contains bottles of a single color. 
The total number of bottles will never exceed 2^31.



The Input
The input consists of a series of lines with each line 
containing 9 integers. The first three integers on a line 
represent the number of brown, green, and clear bottles 
(respectively) in bin number 1, the second three represent
the number of brown, green and clear bottles (respectively)
in bin number 2, and the last three integers represent 
the number of brown, green, and clear bottles 
(respectively) in bin number 3. For example, 
the line 10 15 20 30 12 8 15 8 31
indicates that there are 20 clear bottles in bin 1, 12 
green bottles in bin 2, and 15 brown bottles in bin 3.
Integers on a line will be separated by one or more 
spaces. Your program should process all lines in the 
input file.

The Output
For each line of input there will be one line of output 
indicating what color bottles go in what bin to minimize 
the number of bottle movements. You should also print the 
minimum number of bottle movements.
The output should consist of a string of the three upper 
case characters 'G', 'B', 'C' (representing the colors 
green, brown, and clear) representing the color 
associated with each bin.
The first character of the string represents the color 
associated with the first bin, the second character of 
the string represents the color associated with the 
second bin, and the third character represents the color 
associated with the third bin.
The integer indicating the minimum number of bottle 
movements should follow the string.
If more than one order of brown, green, and clear bins 
yields the minimum number of movements then the 
alphabetically first string representing a minimal 
configuration should be printed.



Sample Input
1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10

Sample Output
BCG 30
CBG 50
