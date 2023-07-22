//check n is prime or not
int prime(int n) {
	for (int i = 2; i*i <= n; i++)
		if ((n%i) == 0)
			return 0;
	return 1;
}

//generate not prime
	for (int i = 2; i <= 1000000; i++)
		if (!prime[i])
			for (int j = i + i; j <= 1000000; j += i)
				prime[j] = 1;
			
			
			