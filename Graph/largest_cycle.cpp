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
int vis[MAX], par[MAX];
int maxWt = -1;

void dfs(int src, int parent) {
	// cout << "src -> " << src << el;
	par[src] = parent;
	vis[src] = 1;

	for(auto i: g[src]) {
		// cout << i << el;
		if(i == parent) continue;
		if(vis[i] == 2) {
			continue;
		}
		if(vis[i] == 1) {
			int st = i, en = src;
			int wt = en;
			while(1) {
				en = par[en];
				wt += en;
				if(en == st) {
					break;
				}
			}
			maxWt = max(maxWt, wt);
			continue;
		}

		dfs(i, src);
	}
	vis[src] = 2;
}

void solve() {
	maxWt = -1;
	int vertex; cin >> vertex;


	// Check self loops
	f(i,0,vertex) {
		int x; cin >> x;
		if(x == -1) continue;
		if(i == x) {
			maxWt = max(x, maxWt);
			continue;
		}
		g[i].pb(x);
	}

	for(int i=0; i<vertex; ++i) {
		if(vis[i] == 0) {
			dfs(i, -1);
		}
	}

	cout << maxWt << el;
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
