12406 - Help Dexter



#include <iostream>
#include <string>
using namespace std;

int main () {
    int t, p, q, tc=1;
    int r[18] = {0,1,2,4,6,5,8,7,11,9,10,11,12,13,17,15,16,17};
    string s = "11211111212122112";             //可以被 2^17 整除的 17 位數
    cin >> t;
    while (t--) {
        cin >> p >> q;
        cout << "Case " << tc++ << ": ";
        if (r[p] < q)                           //r[p]--p位數可被 2^r[p] 整除
            cout << "impossible\n";
        else {
            if (p <= q)
                cout << s.substr(17-p) << endl;
            else
                cout << string (p-q, '1') << s.substr (17-q) << ' '
                     << string (p-q, '2') << s.substr (17-q) << endl;
        }
    }
}



You know Dexter, right? He is a very talented young scientist. He
has a huge lab hidden inside his building.  He made all possible
security arrangement to keep his naughty sister Dee Dee away from
his lab. But she always  nds a way into the lab. One day Dee Dee
came to the lab and started her usual work, messing up Dexter's
lab! Dexter was working on a very important project, so he begged
to her and said, \Please!!! Not today. I will do anything for you, but
please leave this lab today!!!" Dee Dee was waiting for this chance,
she said, \Ok, you do my homework I won't disturb you today."
What can Dexter do? He agreed. Dee Dee said, \My teacher told
me to write down 17 numbers. First one single digit number, second
one two digit number, ...,
n
-th one
n
digit number. They will consist
of only digit 1 and 2 and the
n
-th number should be divisible by 2
n
." Dexter thought, \I have very
little time to  nish the project. I can't waste my time for this silly 
problem, I have bigger problem to think!" So, 
he sent the modi ed version of this problem to you. Hurry up, 
Dee Dee is waiting.



Input
Input starts with an integer
T
(

300), denoting the number of test cases.
Each case starts with two integers:
pq
(1

p;q

17).
Output
For each case, print the case number  rst. Then you have to  nd two 
integers (smallest and largest) which have
p
digits and is divisible by 2
q
. The integers should contain only
1
's and
2
's. If no result is
found, print `
impossible
'. If there is only one integer, then print that integer. 
Otherwise print both
integers ( rst the smallest one then the largest one) 
separated by a single space.



SampleInput
3
2 2
2 1
2 3

SampleOutput
Case 1: 12
Case 2: 12 22
Case 3: impossible