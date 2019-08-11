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

int find(int* ar, int l, int r) {
	if(l == r) return ar[l];
	if(r < l) return 0;

	if(dp[l][r] != -1) return dp[l][r];

	int a = find(ar, l+2, r);
	int b = find(ar, l+1, r-1);
	int c = find(ar, l, r-2);

	// deb(a); deb(b); deb(c);

	return (dp[l][r] = max(ar[l] + min(a, b), ar[r] + min(b, c)));
}

void solve() {
	int n; cin >> n;
	int ar[n+1];

	ff(i,1,n) {
		sc(ar[i]);
	}

	memset(dp, -1, sizeof(dp));

	cout << find(ar, 1, n) << el;

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
