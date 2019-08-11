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
int weight;

void solve() {
	int weight; cin >> weight;

	int n; cin >> n;
	int ar[n+1], val[n+1];

	ff(i,1,n) {
		sc(ar[i]);
	}

	ff(i,1,n) {
		sc(val[i]);
	}

	memset(dp, 0, sizeof(dp));

	ff(i,1,n) {
		ff(j,1, weight) {
			dp[i][j] = dp[i-1][j];
			if(j >= ar[i]) {
				dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j-ar[i]]);
			}
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}

	int ans = dp[n][weight];
	// ff(i,1,weight) {
	// 	// ans = max(ans, dp[n][i]);
	// }

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
