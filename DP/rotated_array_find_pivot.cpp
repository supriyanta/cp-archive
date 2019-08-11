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

inline int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int findStart(int* ar, int l, int r) {
	int st = l, en = r;
	while(r - l > 1) {
		int mid = (l + r)/2;

		if(ar[l] <= ar[mid]) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	
	if(r == en && ar[en-1] <= ar[en]) {
		return st;
	}
	if(ar[l] > ar[r]) {
		return r;
	} else {
		return l;
	}
}

void solve() {
	int n; n = 6;
	//           0  1  2  3  4  5  6  7  8
	int ar[n] = {1, 2, 3, 4, 4, 7};

	cout << findStart(ar, 0, n-1) << el;
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
