#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl

#define F first
#define S second
#define PB push_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define for1n(i, n) for(int i = 1; i <= int(n); i++)
#define for1r(i, n) for(int i = int(n); i >= 1; i--)
#define ms(x, v) memset((x), (v), sizeof(x))
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

const int MOD = 1000000007;
const int MAXN = 200010;

vector<int> entra[MAXN];
vector<int> sai[MAXN];

int n;


struct BIT{
	
	#define NBIT MAXN
	
	int tree[NBIT];
	
	//QueryV: O(log(n)), returns the sum of 1 to i
	int queryV(int i){	
		int s = 0;

		while(i > 0){
			s += tree[i];
			i -= (i & -i);
		}
		
		return s;
	}

	//QueryP: O(log(n))
	int queryP(int v){
		int sum = 0;
		int pos = 0;
		#define LOGN 19
		
		for(int i=LOGN; i>=0; i--){
			if( (pos + (1 << i) < NBIT) and (sum + tree[pos + (1 << i)] < v) ){
				sum += tree[pos + (1 << i)];
				pos += (1 << i);
			}
		}

		return pos + 1;
	}

	//update: O(log(n)), sum value in v[i]
	void update(int i, int value){				
		while(i < NBIT){ 
			tree[i] += value;
			i += (i & -i);
		}
	}
	
};

BIT bit;


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		int a, b;
		cin >> a >> b;

		entra[a].PB(i);
		sai[b].PB(i);
	}
	
	for(int i=1; i<=n; i++){
		for(int x: entra[i])
			bit.update(x, 1);
		
		int ans = bit.queryP(i);		

		if(ans > n)
			cout << "-1 ";
		else
			cout << ans << " ";

		for(int x: sai[i])
			bit.update(x, -1);
		
	}
	cout << endl;
	
	return 0;
}