#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll ans = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		int t, d;
		cin >> t >> d;
		if(t <= ans){
			ans += d;
		}else{
			ans = t + d;
		}
	}
	cout << ans << endl;
	return 0;
}