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

const int white = 0, gray = 1, black = 2;
vi g[MAX];
int maxLev;
int vis[MAX];
vi level[MAX];
int lev[MAX];

int lca(int src, int key, vi &path) {
	vis[src] = 1;
	path.pb(src);

	if(src == key) {
		return 1;
	}

	for(auto i: g[src]) {
		if(vis[i]) continue;
		if(lca(i, key, path) == 1) {
			return 1;
		}
	}

	path.pop_back();
	return 0;
}

void solve() {
	maxLev = -1;
	int vertex; cin >> vertex;

	vi heads;

	// Check self loops
	f(i,0,vertex) {
		int x; cin >> x;
		if(x == -1) {
			heads.pb(i);
			continue;
		}
		g[i].pb(x);
		g[x].pb(i);
	}

	int lc, rc;
	cin >> lc >> rc;

	int ans = -1;
	for(auto i: heads) {
		vi path1; vi path2;

		// cout << "root = " << i << el;

		int tll = lca(i, lc,  path1);
		memset(vis, 0, sizeof vis);
	
		int trr = lca(i, rc,  path2);
		memset(vis, 0, sizeof vis);

		if (tll && trr) {
			for(int j=0; j < path1.size() && j < path2.size(); ++j) {
				if(path1[j] != path2[j]) break;
				ans = path1[j];
			}
		}
		path1.clear(); path2.clear();
	}
	cout << ans << el;
}

int main() {
	freopen("inp.txt", "r", stdin);
	// freopen("op.txt", "w", stdout);
	
	int ccc = 1;
	// sc(ccc);
	while(ccc--) {
		solve();
	}
 
	return 0;
}

// 23
// 4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
// 9 2
