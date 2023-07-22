int N_origin = N;
		int N_reverse = 0;
		while (N)
		{
			N_reverse *= 10;
			N_reverse += N % 10;
			N /= 10;
		}