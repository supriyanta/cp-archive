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

string ss, st;

inline int min(int a, int b, int c) {
	return min(c, min(a, b));
}

void solve() {
	cin >> ss >> st;

	int zss = ss.length();
	int zst = st.length();

	int dp[100][100];
	memset(dp, 0, sizeof(dp));

	ff(i,0,zss) {
		ff(j,0,zst) {
			if(i == 0) {
				dp[i][j] = j;
				continue;
			}
			if(j == 0) {
				dp[i][j] = i;
				continue;
			}

			if(ss[i-1] == st[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
			}
		}
	}

	// ff(i,0,zss) {
	// 	ff(j,0,zst) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << el;
	// }

	cout << dp[zss][zst] << el;
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
