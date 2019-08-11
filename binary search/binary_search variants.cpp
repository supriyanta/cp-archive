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

int bsearch(int* ar, int l, int r, int key) {
	
	while(r - l > 1) {
		int mid = (l + r) / 2;

		if(key >= ar[mid]) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if(ar[l] == key) {
		return l;
	}
	if(ar[r] == key) {
		return r;
	}
	return -1;
}

int floorb(int* ar, int l, int r, int key) {
	if(ar[l] > key) return -1;
	// if(ar[r] <= key) return r;

	while(r - l > 1) {
		int mid = (l + r) / 2;

		if(key >= ar[mid]) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}

int ceilb(int* ar, int l, int r, int key) {
	if(ar[r] < key) return -1;
	// if(ar[l] >= key) return l; 

	while(r - l > 1) {
		int mid = (l + r) / 2;

		if(key <= ar[mid]) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}

int left(int* ar, int l, int r, int key) {
	while(r - l > 1) {
		int mid = (l + r) / 2;

		if(key <= ar[mid]) {
			r = mid;
		} else {  // key > ar[mid]
			l = mid;
		}
	}
	return r;
}

int right(int* ar, int l, int r, int key) {
	while(r - l > 1) {
		int mid = (l + r) / 2;

		if(key >= ar[mid]) {
			l = mid;
		} else {  // ar[mid] < key
			r = mid;
		}
	}
	return l;
}

void solve() {
	int n; cin >> n;
	int ar[n];

	f(i,0,n) {
		cin >> ar[i];
	}
	int key; cin >> key;
	cout << right(ar, 0, n-1, key) << endl;
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
