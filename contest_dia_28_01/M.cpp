#include <bits/stdc++.h>
using namespace std;
// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int dp[200002][3][3][3];
string str[3];
int n;
int solve(int i, int f, int s, int t){
	if(f > 1 or s > 1 or t > 1) return 0;
	if(i == n) return dp[i][f][s][t] = 1;
	if(dp[i][f][s][t] != -1) return dp[i][f][s][t];
	int ans = 0;
	
	for(char c = 'a'; c <= 'z'; c++){
		ans = min(3, ans + solve(i + 1, f + (str[0][i] != c), s + (str[1][i] != c), t + (str[2][i] != c)));
	}
	
	return dp[i][f][s][t] = ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> str[0] >> str[1] >> str[2];
	
	n = str[0].size();
	
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0, 0, 0);
	if(ans == 0){
		cout << "Impossible" << endl;
	}else if(ans != 1){
		cout << "Ambiguous" << endl;
	}else{
		string answer;
		int i = 0, f = 0, s = 0, t = 0;
		while(i != n){
			for(char c = 'a'; c <= 'z'; c++){
				if(dp[i][f][s][t] == solve(i + 1, f + (str[0][i] != c), s + (str[1][i] != c), t + (str[2][i] != c))){
					answer += c;
					f += (str[0][i] != c);
					s += (str[1][i] != c);
					t += (str[2][i] != c);
					i++;
				}
			}
		}
		cout << answer << endl;
	}
	
	return 0;
}
