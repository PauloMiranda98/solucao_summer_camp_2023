//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

//order_of_key(value)
//find_by_order(idx)

*/

#define DEBUG false
#define dbf if (DEBUG) printf

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double EPS = 1e-9;
const double PI = acos(-1);

const int MOD = 1000000007;
const int MAXN = 100100;
int tree[30][MAXN];
int n;
string s;

void update(int c, int x, int v){
	for(int i=x; i<=n; i+= i&-i)
		tree[c][i] += v;
}

int query(int c, int x){
	int ans=0;
	for(int i=x; i>0; i-= i&-i)
		ans += tree[c][i];
	return ans;
}

int range(int l, int r){
	int ans = 0;
	for(int i=0; i<26; i++){
		if( query(i, r) - query(i, l-1) > 0)
			ans++;
	}
	return ans;
}

int getId(char c){
	return c-'a';
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> s;

	n = s.size();
	for(int i=0; i<n; i++)
		update(getId(s[i]), i+1, +1);

	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int pos;
			char c;
			cin >> pos >> c;
						
			update(getId(s[pos-1]), pos, -1);
			update(getId(c), pos, +1);
			s[pos-1] = c;
		}else{
			int l, r;
			cin >> l >> r;
			cout << range(l, r) << endl;
		}
	}	
	return 0;
}