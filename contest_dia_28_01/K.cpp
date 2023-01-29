#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 110;

int g[MAXN][3][3];

void grundy(){
	//Base case depends on the problem
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			g[0][i][j] = 0; 
	
	//Inductive case	
	for(int i=1; i<MAXN; i++){
		for(int a=0; a<3; a++){
			for(int b=0; b<3; b++){
				g[i][0][0] = i&1; 
				g[i][0][1] = i; 
				g[i][0][2] = i; 
				g[i][1][0] = i; 
				g[i][1][1] = 1; 
				g[i][1][2] = 0; 
				g[i][2][0] = i; 
				g[i][2][1] = 0; 
				g[i][2][2] = 1; 
			}
		}			
	}
}

int main() {	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	grundy();		
	int t;
		
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool vez = true;
		int l = -1;
		int a = 0;
		int ans = 0;
		
		for(int i=0; i<(int)s.size(); i++){
			if(s[i] != '.'){
				int b = (s[i]=='X') ? 1 : 2;
				int x = i - l - 1;

				ans ^= g[x][a][b];
				vez = !vez;
				l = i;
				a = b;
			}
		}

		int x = s.size() - l - 1;		
		ans ^= g[x][a][0];
		
		if((ans!=0) == vez){
			cout << "Possible." << endl;		
		}else{
			cout << "Impossible." << endl;					
		}
	}
	
	return 0;
	
}