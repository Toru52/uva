int solve(int I) {
	int  b[20][20]{};

	for (int j = 0; j < n; ++j) 
		if (I & (1 << j))
			b[0][j] = 1;
		else if(1 == a[0][j])  
			return INF;//是1，本应该是0的，不能修改，结束
	printf("i %d\n", I);
	for (int i = 0; i < n; ++i) 
			printf("%d ",b[0][i]);
	puts("");
	
	for (int r = 0; r < n - 1; ++r)
		for (int c = 0; c < n; ++c) {
			int sum = 0;
			if (r > 0)
				sum += b[r - 1][c];//计算上下左右						   //            if(r < n-1)  sum += b[r+1][c];
			if (c > 0)
				sum += b[r][c - 1];
			if (c < n - 1) 
				sum += b[r][c + 1];
			b[r + 1][c] = sum % 2;//确定下一行元素
		//	printf("sum %d\n", sum);
			if (a[r + 1][c] && !b[r + 1][c]) 
				return INF;//同上，不能改
		}
	printf("I %d\n", I);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", b[i][j]);
		puts("");
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != b[i][j]) 
				++cnt;//计算个数
	return cnt;
}
		uva 11464