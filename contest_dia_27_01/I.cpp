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

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double PI = acos(-1);

const int MOD = 1000000007;
const int MAXN = 110;
const double EPS = 1e-9;
int n, k;
ll dp[MAXN][MAXN][MAXN];
ll vp[MAXN];

ll solve(int i, int j, int p){
	if(i==j)
		return p*1LL*vp[i];	
	if(p == k)
		return INFLL;
	if(dp[i][j][p] != -1LL)
		return dp[i][j][p];
	
	ll ans = INFLL;
	for(int k=i; k<j; k++){
		ans = min(ans, solve(i, k, p+1) + solve(k+1, j, p+1));
	}
	return dp[i][j][p] = ans;
	
}

int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	ll sum = 0;
	for(int i=0; i<n; i++){
		cin >> vp[i];
		sum += vp[i];
	}
	sort(vp, vp+n);
	ll ans = solve(0, n-1, 0);
	if(ans >= INFLL){
		cout << "No solution" << endl;
	}else{
		ll g = __gcd(ans, sum);
		ans /= g;
		sum /= g;
		cout << ans <<"/" << sum << endl;
	}
	return 0;
}