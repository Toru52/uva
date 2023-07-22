void rotate(int x[][50], int n) {
	int y[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			y[j][n - i - 1] = x[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			x[i][j] = y[i][j];
}