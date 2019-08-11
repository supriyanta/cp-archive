#include<bits/stdc++.h>
#include<cstdio>

#define deb(x) cout << #x << " -> " << x << el 
#define db double
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define sclu(x) scanf("%llu", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define pass cout<<"pass\n"
#define vi vector<int>
#define pb push_back
#define vec vector
#define el "\n"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define f(i,x,y) for(int i=x;i<y;++i)
#define ff(i,x,y) for(int i=x;i<=y;++i)
#define mem(x) memset(x, 0, sizeof(x))
#define mems(x,y) memset(x, y, sizeof(x))
#define MOD 1000000007
#define MAX 100005

using namespace std;

int n, m;
int dp[3][3];
int g[3][3] = {{1, 2, 9}, 
			   {5, 3, 8}, 
			   {4, 6, 7}};

int find(int i, int j, int val) {
	// if(i < 0 || j < 0) return 0;
	if(i >= n || j >= m) return 0;
	if(val+1 != g[i][j]) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int ans = 0;

	if(i > 0) {
		ans = max(ans, find(i-1, j, g[i][j]));
	}

	if(i < n-1) {
		ans = max(ans, find(i+1, j, g[i][j]));
	}

	if(j > 0) {
		ans = max(ans, find(i, j-1, g[i][j]));
	}

	if(j < m- 1) {
		ans = max(ans, find(i, j + 1, g[i][j]));
	}

	dp[i][j] = ans + g[i][j];
	return dp[i][j];
}

void solve() {
	n = 3; m = 3;
	
	memset(dp, -1, sizeof(dp));

	int ans = INT_MIN;
	f(i,0,n) {
		f(j,0,m) {
			ans = max(ans, find(i, j, g[i][j]-1));
		}
	}
	
	cout << ans << el;
}

int main() {
	// freopen("inp.txt", "r", stdin);
	// freopen("op.txt", "w", stdout);
	
	int ccc = 1;
	// sc(ccc);
	while(ccc--) {
		solve();
	}
 
	return 0;
}
