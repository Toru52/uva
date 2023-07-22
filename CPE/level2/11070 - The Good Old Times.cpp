11070 - The Good Old Times
https://github.com/milon/UVa/blob/master/Volume-110/UVa_11070.cpp



#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<char> suru;
	char c;
	double a, b, sum;
	while (cin >> a) {
		sum = 0;
		while (true) {
			c = getchar();
			//when to enter the key did.
			if (c == '\n') {
				if (suru.empty())
					sum += a;
				else {
					char t = suru.top();
					suru.pop();
					if (t == '+')
						sum += a;
					else
						sum -= a;
				}
				break;
			}
			cin >> b;
			//a (+,-,*,/) b
			//a+b -> sum+=a
			//a*b -> a*=b 
			printf("a %.3lf c %c b %.3lf sum %.3lf\n", a,c,b,sum);
			if ((c == '+') || (c == '-')) {
				// top operator (since first operator, sum+=a whether it plus or minus)
				if (suru.empty()) {
					suru.push(c);
					sum += a;
					a = b;
				}
				//second or more operator
				else {
					char t = suru.top();
					suru.pop();
					suru.push(c);
					if (t == '+')
						sum += a;
					else
						sum -= a;
					a = b;
				}
			}
			else if (c == '*')
				a *= b;
			else if (c == '/')
				a /= b;
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}



#include<iostream>
#include<stack>
using namespace std;
int main() {
	double a, b,sum;
	stack<char>st;
	while (cin >> a) {
		sum = 0;
		while (1) {
			char c = getchar();
			
			if (c == '\n') {
				if (st.empty())
					sum += a;
				else {
					if (st.top() == '+')
						sum += a;
					else if (st.top() == '-')
						sum -= a;
					st.pop();
				}
				break;
			}
			cin >> b;
			if (c == '+' || c == '-') {
				if (st.empty()) {
					st.push(c);
					sum += a;
					a = b;
				}
				else {
					if (st.top() == '+')
						sum += a;
					else
						sum -= a;
					st.pop();
					st.push(c);
					a = b;
				}
			}		
			else if (c == '*')
				a *= b;
			else if (c == '/')
				a /= b;
			
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}



/*
concept
ex
a+b*c 
a->sum 
b*c->sum

ex 2+3*4
a=2
b=3
sum+=a; (sum=2)

next
a=3
b=4
a*=b (a=12)

next
sum+=a (sum=14)
*/
In the stoneage things weren't as easy for programmers as they are 
today. For example programmers had only very slow computers with a very 
limited main memory and very small hard disks at their disposal.
Furthermore a lot of standard applications hadn't been developed. 
Now one of your customers, FredFlintstone, wants a command line 
calculator for his computer, the new Granite500 with 1000 hertz.
Your task is to write a command line calculator for him



Input
Each line of input will consist of a string of length l, l < 255, 
containing a valid arithmetic expression.
Because main memory was very small in those days, 
the string will contain no blanks or tabs, nor
parathensis. It will contain the four standard arithmetic operators 
`+', `-', `*',/ as well as a unary `-' or `+' and 
oating point numbers. The input will be terminated by EOF.

Output
For each line of input, output the value of the arithmetic 
expression on a single line. The result should
contain three digits after the decimal point.
Hint: use double



Sample Input
1/2/2
-3.0
3
4.0+3.0/5.0
1*2*3+1+1*2+1*2*3*4

Sample Output
0.250
-3.000
3.000
4.600
33.000