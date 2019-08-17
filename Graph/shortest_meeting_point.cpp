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
int vis[MAX];

void dfs(int src, int par, vi &st) {
	// cout << "src -> " << src << el;

	if(vis[src]) {
		return;
	}

	vis[src] = true;

	st.pb(src);

	for(auto i: g[src]) {
		// cout << i << el;
		if(i == par) continue;
		dfs(i, src, st);
	}
}

void solve() {
	int vertex; cin >> vertex;

	f(i,0,vertex) {
		int x; cin >> x;
		if(x == -1) continue;
		g[i].pb(x);
	}

	// ff(i,0,5) {
	// 	cout << "vert " << i << el;
	// 	for(auto k: g[i]) {
	// 		cout << k << " ";
	// 	} cout << el;
	// }

	int p, q;
	cin >> p >> q;

	memset(vis, 0, sizeof vis);
	vi st1;
	dfs(p, -1, st1);

	// cout << "stack 1 -> " << el;
	// for(auto i: st1) {
	// 	cout << i << " ";
	// } cout << el;

	memset(vis, 0, sizeof vis);
	vi st2;
	dfs(q, -1, st2);

	// cout << "stack 2 -> " << el;
	// for(auto i: st2) {
	// 	cout << i << " ";
	// } cout << el;

	unordered_map<int, int> track;
	for(auto i: st1) {
		track[i] = 1;
	}
	for(auto i: st2) {
		if(track[i] == 1) {
			cout << i << el;
			return;
		}
	}
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
