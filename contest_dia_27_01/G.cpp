#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll b1, b2, p1, p2;
		
		cin >> b1 >> p1 >> b2 >> p2;
		
		if( (b1 == 0) or (b2==0) ){
			if(b1 < b2){
				cout << "Congrats" << endl;	
			}else if( b1 > b2){
				cout << "HaHa" << endl;				
			}else{
				cout << "Lazy" << endl;				
			}
		}else{
			long double a1 = p1*log(b1);
			long double a2 = p2*log(b2);
			
			if( abs(a1 - a2) < 1e-9){
				cout << "Lazy" << endl;				
			}else{
				if(a1 < a2){
					cout << "Congrats" << endl;	
				}else{
					cout << "HaHa" << endl;				
				}
			}
		}
	}
	return 0;
}