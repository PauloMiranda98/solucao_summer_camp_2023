#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
inline int modSum(int a, int b, int mod = MOD){
	int ans = a+b;
	if(ans > mod) ans -= mod;
	return ans;
}
inline int modMul(int a, int b, int mod = MOD){
	return (a*1LL*b)%mod;
}
const int D = 9;
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
	Matrix ans(1);
	while(exp){
		if(exp&1LL)
			ans = ans*base;
		base = base*base;
		exp>>=1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	Matrix base({{0, 16, 0, 9, 0, 4, 0, 1, 0}, 
	             {1 , 0, 0, 0, 0, 0, 0, 0, 0},
	             {0 , 1, 0, 0, 0, 0, 0, 0, 0},
	             {0 , 0, 1, 0, 0, 0, 0, 0, 0},
	             {0 , 0, 0, 1, 0, 0, 0, 0, 0},
	             {0 , 0, 0, 0, 1, 0, 0, 0, 0},
	             {0 , 0, 0, 0, 0, 1, 0, 0, 0},
	             {0 , 0, 0, 0, 0, 0, 1, 0, 0},
	             {0 , 0, 0, 0, 0, 0, 0, 1, 0}});
	
	vector<int> v = {1, 1, 17, 17, 282, 282, 4670, 4670, 77328};
	if(n < 45){
		cout << v[n/5] << endl;
	}else{
		auto ans = fastPow(base, (n/5) - 8);
		int res = 0;
		for(int i=0; i<D; i++)
			res = modSum(res, modMul(ans[0][i], v[D-i-1]));		
		cout << res << endl;
	}
	return 0;
}