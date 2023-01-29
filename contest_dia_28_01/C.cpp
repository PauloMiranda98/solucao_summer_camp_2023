#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 110;

int version;
int used[MAXN*MAXN];

int mex() {
	for(int i=0; ; ++i)
		if(used[i] != version)
			return i;
}

int g[MAXN][MAXN];

void grundy(){
	for(int i=1; i<MAXN; i++){
		for(int j=1; j<MAXN; j++){
			if(i == j)
				continue;
				
			version++;
			for(int k=1; k<i; k++)
				if( (i-k) != j)
					used[g[i-k][j]] = version;
			
			for(int k=1; k<j; k++)
				if(i != (j-k))
					used[g[i][j-k]] = version;
			for(int k=1; k<min(i, j); k++)
				used[g[i-k][j-k]] = version;
				
			g[i][j] = mex();
			//cout << i << "," << j << ": " << g[i][j] << endl;
		}
	}
}

int main() {	
	
	grundy();		
	int n;
	cin >> n;
	
	int ans = 0;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		if(x == y or x==0 or y==0){
			cout << "Y" << endl;
			return 0;
		}
		ans ^= g[x][y];
	}
	
	cout << ((ans != 0) ? "Y" : "N") << endl;
		
	return 0;
	
}
