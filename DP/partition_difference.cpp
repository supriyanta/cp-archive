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
#define mat vector<vector<long long int> >

using namespace std;

string ss, st;

void solve() {
	vi ar(100);

	int n; sc(n);

	int total = 0;
	ff(i,1,n) {
		sc(ar[i]);
		total += ar[i];
	}
	
	vec<vi> dp(100, vi(100, 0));
	dp[0][0] = 1;

	ff(i, 1, n) {
		ff(j, 0, total/2) {
			if(j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j];
			if(ar[i] <= j) {
				dp[i][j] = dp[i][j] || dp[i-1][j-ar[i]];
			}
		}
	}

	int ans;
	for(int i=total/2; i>=0; --i) {
		if(dp[n][i]) {
			ans = total - 2*i;
			break;
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
