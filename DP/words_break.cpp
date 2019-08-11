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

string words[13] = { "i", "and", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
map<string, int> mm;

void pre() {
	f(i,0,13) {
		mm[words[i]] = 1;
	}
}

void solve() {
	pre();
	string str; cin >> str;
	int sz = (int)str.size();

	int dp[sz] = {0};

	for(int i=0; i < sz; ++i) {
		if(mm[str.substr(0, i+1)]) {
			dp[i] = 1;
			continue;
		}

		for(int j=0; j < i; ++j) {
			string ps = str.substr(j+1, i-j);
			if(dp[j] && mm[ps]) {
				dp[i] = 1;
				break;
			}
		}
	}
	cout << dp[sz-1] << endl;
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
