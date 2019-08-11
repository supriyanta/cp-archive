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

int dp[100][100];

void solve() {
	int n; cin >> n;
	int ar[n+1];

	ff(i,1,n) {
		sc(ar[i]);
	}

	memset(dp, -1, sizeof(dp));

	f(gap,0,n) {
		for(int i=1; i+gap <= n; ++i) {
			if(gap == 0) {
				dp[i][i+gap] = ar[i];
				continue;
			}
			// if(gap == 1) {
			// 	dp[i][i+gap] = max(ar[i], ar[i+gap]);
			// 	continue;
			// }
			int a = dp[i+2][i+gap];
			int b = dp[i+1][i+gap-1];
			int c = dp[i][i+gap-2];

			dp[i][i+gap] = max(ar[i] + min(a, b), ar[i+gap] + min(b, c));
		}
	}
	cout << dp[1][n] << el;
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
