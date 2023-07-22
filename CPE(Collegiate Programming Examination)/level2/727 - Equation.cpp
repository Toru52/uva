727 - Equation
http://knightzone.org/?p=1343



#include<iostream>
#include<stack>
using namespace std;

int main(){
  int n;
  char c;
  stack<char> stk;
  while( scanf( "%d", &n ) != EOF ){
    getchar();
    getchar();
    for( int i = 0 ; i < n ; i++ ){
      if( i ) printf( "\n" );
      while( scanf( "%c", &c ) != EOF && c != '\n'){
        getchar();
        if( isdigit(c) )//number output first
          printf( "%c", c );
        else if( c == '(' )
          stk.push(c);
        else if( c == '*' || c == '/' ){
          while( !stk.empty() && (stk.top() == '*' || stk.top() == '/') ){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.push(c);
        }
        else if( c == '+' || c == '-' ){
          while( !stk.empty() &&
                 (stk.top() == '*' ||
                  stk.top() == '/' ||
                  stk.top() == '+' ||
                  stk.top() == '-' )){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.push(c);
        }
        else if( c == ')' ){//do not need push the ')'
          while( stk.top() != '(' ){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.pop();
        }
      }
      while( !stk.empty() ){
        printf( "%c", stk.top() );
        stk.pop();
      }
      printf( "\n" );
    }
  }
  return 0;
}



#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	char c;
	stack<char>st;
	cin >> n;
	getchar();
	getchar();
	for (int i = 0; i < n; i++) {
		if (i)
			puts("");
		while (scanf("%c", &c), c != '\n') {
			getchar();
			if (isdigit(c))
				printf("%c", c);
			else if (c == '(')
				st.push(c);
			else if (c == '*' || c == '/') {
				while (!st.empty() &&
					(st.top() == '*' || st.top() == '/')) {
					printf("%c", st.top());
					st.pop();
				}
				st.push(c);
			}
			else if (c == '+' || c == '-') {
				while (!st.empty() &&
					(st.top() == '*' || st.top() == '/'
						|| st.top() == '+' || st.top() == '-')) {
					printf("%c", st.top());
					st.pop();
				}
				st.push(c);
			}
			else if (c == ')') {
				while (st.top() != '(') {
					printf("%c", st.top());
					st.pop();
				}
			st.pop();
			}
		}
		while (!st.empty()) {
			printf("%c", st.top());
			st.pop();
		}
		puts("");
	}
	return 0;
}



Write a program that changes an infix expression to a 
postfix expression according to the following
specifications.



Input
1. The infix expression to be converted is in the input 
file in the format of one character per line,
with a maximum of 50 lines in the file. 
For example, (3+2)*5 would be in the form:
(
3
+
2
)
*
5
2. The input starts with an integer on a line by itself 
   indicating the number of test cases. Several
   infix expressions follows, preceded by a blank line.
3. The program will only be designed to handle the binary 
   operators +, -, *, /.
4. The operands will be one digit numerals.
5. The operators * and / have the highest priority. 
   The operators + and - have the lowest priority.
   Operators at the same precedence level associate from 
   left to right. Parentheses act as grouping
   symbols that over-ride the operator priorities.
6. Each testcase will be an expression with valid syntax.

Output
The output file will have each postfix expression all on 
one line. Print a blank line between different expressions.



Sample Input
1
(
3
+
2
)
*
5

Sample Output
32+5*