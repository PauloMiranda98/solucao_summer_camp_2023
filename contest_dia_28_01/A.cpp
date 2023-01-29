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

int MOD;

inline int modSum(int a, int b, int mod = MOD){
	int ans = a+b;
	if(ans >= mod) ans -= mod;
	return ans;
}
inline int modSub(int a, int b, int mod = MOD){
	int ans = a-b;
	if(ans < 0) ans += mod;
	return ans;
}
inline int modMul(int a, int b, int mod = MOD){
	return (a*1LL*b)%mod;
}

const int D = 6;
struct Matrix{
  int m[D][D];
  Matrix(bool identify = false){
    memset(m, 0, sizeof(m));
    for (int i = 0; i < D; i++)
      m[i][i] = identify;    
  }
  Matrix(vector<vector<int>> mat){
    for(int i=0; i<D; i++)
      for(int j=0; j<D; j++)
        m[i][j] = mat[i][j];    
  }
  int * operator[](int pos){
    return m[pos];
  }
  Matrix operator*(Matrix oth){
    Matrix ans;
    for (int i = 0; i < D; i++){
      for (int j = 0; j < D; j++){
        int &sum = ans[i][j];
        for (int k = 0; k < D; k++)
          sum = modSum(sum, modMul(m[i][k], oth[k][j]));
      }
    }
    return ans;
  }
};

Matrix fastPow(Matrix base, ll exp){
  Matrix ans(true);
  while(exp){
    if(exp&1LL)
      ans = ans * base;
    base = base*base;
    exp>>=1;
  }
  return ans;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for(int C=1; C<=t; C++){
		
		int a1, b1, c1;
		int a2, b2, c2;
		int f0, f1, f2;
		int g0, g1, g2;
		
		cin >> a1 >> b1 >> c1;
		cin >> a2 >> b2 >> c2;
		cin >> f0 >> f1 >> f2;
		cin >> g0 >> g1 >> g2;
		cin >> MOD;
		
		Matrix base({
			{a1%MOD, b1%MOD, 0, 0, 0, c1%MOD},
			{1%MOD, 0, 0, 0, 0, 0},
			{0, 1%MOD, 0, 0, 0, 0},
			{0, 0, c2%MOD, a2%MOD, b2%MOD, 0},
			{0, 0, 0, 1%MOD, 0, 0},
			{0, 0, 0, 0, 1%MOD, 0}
		});
		
		vector<int> col = {f2%MOD, f1%MOD, f0%MOD, g2%MOD, g1%MOD, g0%MOD};

		cout << "Case " << C << ":" << endl; 
		
		int q;
		cin >> q;
		while(q--){
			int n;
			cin >> n;
			
			int fn = 0, gn = 0;
			if(n <= 2){
				fn = col[2 - n];
				gn = col[5 - n];
			}else{
				auto res = fastPow(base, n-2);
				
				for(int i=0; i<6; i++){
					fn = modSum(fn, modMul(res[0][i], col[i]));
					gn = modSum(gn, modMul(res[3][i], col[i]));
				}
			}
			cout << fn << " " << gn << endl;
		}
	}
	
	return 0;
}
