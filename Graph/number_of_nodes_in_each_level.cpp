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

void bfs(int src) {
	queue<int> q;
	lev[src] = 0;
	level[0].pb(src);
	q.push(src);
	vis[src] = 1;

	while(!q.empty()) {
		// cout << "inf\n";
		int s = q.front();
		q.pop();

		for(auto i: g[s]) {
			if(vis[i]) continue;
			vis[i] = 1;

			q.push(i);
			lev[i] = lev[s] + 1;
			level[lev[i]].pb(i);

			maxLev = max(maxLev, lev[i]);
		}
	}
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

	for(auto i: heads) {
		bfs(i);
	}

	int depth = 0, ind = -1;

	ff(i,0,maxLev) {
		int sz = (int) level[i].size();
		if(depth <= sz) {
			depth = sz;
			ind = i;
		}
		cout << i << "th level -> " << sz << el;
		sort(level[i].begin(), level[i].end());
		for(auto p: level[i]) {
			cout << p << " ";
		}
		cout << el;
	}
	cout << "index -> " << ind << el;
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
