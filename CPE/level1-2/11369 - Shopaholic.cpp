11369 - Shopaholic



#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, N, a[20000];

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		sort(a, a + N);
		int ans = 0;
		for (int i = N - 3; i >= 0; i -= 3)
			ans += a[i];
		printf("%d\n", ans);
	}
}



#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int c, n, a[20000] = {0};
	scanf("%d", &c);
	while (c--)
	{
		int ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = n - 3; i >= 0; i -= 3) 
			ans += a[i];
		printf("%d\n", ans);
	}
}



Lindsay is a shopaholic. Whenever there is a
discount of the kind where you can buy three
items and only pay for two, she goes completely
mad and feels a need to buy all items in the
store. You have given up on curing her for this
disease, but try to limit its effect on her wallet.
You have realized that the stores coming with these 
offers are quite selective when it comes to which
items you get for free; it is always the cheapest ones. 
As an example, when your friend comes to the
counter with seven items, 
costing 400, 350, 300, 250, 200, 150, and 100 dollars, 
she will have to pay
1500 dollars. In this case she got a discount of 250 
dollars. You realize that if she goes to the counter
three times, she might get a bigger discount. 
E.g. if she goes with the items that costs 400, 300 and
250, she will get a discount of 250 the first round. 
The next round she brings the item that costs 150
giving no extra discount, but the third round she takes 
the last items that costs 350, 200 and 100 giving
a discount of an additional 100 dollars, adding up to a 
total discount of 350. Your job is to find the maximum 
discount Lindsay can get.



Input
The first line of input gives the number of test 
scenarios, 1 ≤ t ≤ 20. Each scenario consists of two
lines of input. The first gives the number of items 
Lindsay is buying, 1 ≤ n ≤ 20000. The next line
gives the prices of these items, 1 ≤ pi ≤ 20000.

Output
For each scenario, output one line giving the maximum 
discount Lindsay can get by selectively choosing
which items she brings to the counter at the same time.



Sample Input
1
6
400 100 200 350 300 250

Sample Output
400