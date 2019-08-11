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

struct Box {
	int h, d, w;
	Box(int hh, int x, int y) {
		h = hh;
		d = max(x, y);
		w = min(x, y);
	}
	Box() {}
};


void solve() {
	int n; cin >> n;

	int index = 0;
	Box box[3*n];

	f(i,0,n) {
		int h, d, w;
		cin >> h >> d >> w;
		box[index++] = Box(h, d, w);
		box[index++] = Box(d, w, h);
		box[index++] = Box(w, h, d);
	}

	sort(box, box+(3*n), [](Box a, Box b) -> bool {
		if(a.d == b.d) {
			return a.w <= b.w;
		}
		return a.d < b.d;
	});

	int dp[3*n];
	memset(dp, 0, sizeof(dp));

	int maxHeight = 1;

	f(i,0,3*n) {
		dp[i] = box[i].h;
		f(j,0,i) {
			if(box[i].d > box[j].d && box[i].w > box[j].w) {
				dp[i] = max(dp[i], box[i].h + dp[j]);
			}
		}
		maxHeight = max(maxHeight, dp[i]);
	}

	cout << maxHeight << endl;
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
