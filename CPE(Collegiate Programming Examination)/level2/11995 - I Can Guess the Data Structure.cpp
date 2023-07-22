11995 - I Can Guess the Data Structure!  
http://knightzone.org/?p=1779



#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
	int n, cmd, x;
	while (scanf("%d", &n)==1) {
		stack<int> st;
	    queue<int> qu;
	    priority_queue<int> pq;
		bool stack = true,queue = true,pqueue = true;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &cmd, &x);
			if (cmd == 1) 
				st.push(x),qu.push(x),pq.push(x);
			else if (cmd == 2) {
				if (stack) {
					if (!st.empty() && st.top() == x) st.pop();
					else stack = false;
				}
				if (queue) {
					if (!qu.empty() && qu.front() == x) qu.pop();
					else queue = false;
				}
				if (pqueue) {
					if (!pq.empty() && pq.top() == x) pq.pop();
					else pqueue = false;
				}
			}
		}
		if ((stack && queue) || (queue && pqueue) 
			|| (stack && pqueue))
			puts("not sure");
		else if (stack) puts("stack");
		else if (queue) puts("queue");
		else if (pqueue) puts("priority queue");
		else puts("impossible");
	}
	return 0;
}



#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
int main() {
	int n,x,type;
	while (scanf("%d", &n) == 1) {
		stack<int>st;
		queue<int>qu;
		priority_queue<int>pq;
		bool stack = true, queue = true, priqueue = true;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &type, &x);
			if (type == 1)
				st.push(x), qu.push(x), pq.push(x);
			else if (type == 2) {
				if (!st.empty() && st.top()==x)st.pop();
				else stack = false;
				if (!qu.empty() && qu.front()==x)qu.pop();
				else queue = false;
				if (!pq.empty() && pq.top()==x)pq.pop();
				else priqueue = false;
			}
		}
		if ((stack&&queue) || (stack&&priqueue) || (queue&&priqueue))
			puts("not sure");
		else if (stack)puts("stack");
		else if (queue)puts("queue");
		else if (priqueue)puts("priority queue");
		else puts("impossible");
	}
	return 0;
}



/*
memo
stack(Last-In,First-Out)
queue(First-In,First-Out)
priority-queue(Always take out larger elements first)

rule
1 x Throw an element x into the bag.
2 Take out an element from the bag.
*/

There is a bag-like data structure, supporting two operations:
1 x Throw an element x into the bag.
2 Take out an element from the bag.
Given a sequence of operations with return values, you're 
going to guess the data structure. It is a stack 
(Last-In, First-Out), a queue (First-In, First-Out),
a priority-queue (Always take out larger elements rst) 
or something else that you can hardly imagine!



Input
There are several test cases. Each test case begins with a 
line containing a single integer n (1  n 
1000). Each of the next n lines is either a type-1 command, 
or an integer 2 followed by an integer x.
That means after executing a type-2 command, we get an 
element x without error. The value of x is always a positive 
integer not larger than 100. The input is terminated by 
end-of-le (EOF).

Output
For each test case, output one of the following:
stack It's denitely a stack.
queue It's denitely a queue.
priority queue It's denitely a priority queue.
impossible It can't be a stack, a queue or a priority queue.
not sure It can be more than one of the three data structures 
men-tioned above.



Sample Input
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

Sample Output
queue
not sure
impossible
stack
priority queue


