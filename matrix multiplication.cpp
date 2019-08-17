#define mat vector<vector<int> >


mat multiply(mat a, mat b) {
	int row = a.size(), col = b[0].size();
	mat c(row, vi(col, 0));

	for(int i=0; i < row; ++i) {
		for(int j=0; j < col; ++j) {
			for(int k=0; k < b.size(); ++k) {
				int xx = (a[i][k] * b[k][j])%mod;
				c[i][j] = (c[i][j] + xx) % mod;
			}
		}
	}
	return c;
}
