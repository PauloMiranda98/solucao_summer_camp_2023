#include <bits/stdc++.h>
using namespace std;
 
typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const long double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
 
template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    else {
        T g = extGcd(b, a % b, y, x);
        y -= a / b * x; return g;
    }
}
 
template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}
 
template <typename T>
T modDiv(T a, T b, T m) {
    return ((a % m) * modInv(b, m)) % m;
}
 
template<typename T>
T modMul(T a, T b, T m) {
    T x = 0, y = a % m;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % m;
        y = (y * 2) % m; b /= 2;
    }
    return x % m;
}
 
int gaussMOD(vector < vector<ll> > a, vector<ll> & ans, ll M) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for(int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for(int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if(a[sel][col] == 0LL)
            continue;
           
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                ll c = modDiv(a[i][col], a[row][col], M);
                for (int j=col; j<=m; ++j)
                    a[i][j] = ( a[i][j] - ((a[row][j] * c)%M) + M)%M;
            }
        ++row;
    }
 
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = modDiv(a[where[i]][m], a[where[i]][i], M);
           
    for (int i=0; i<n; ++i) {
        ll sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + (ans[j] * a[i][j])%M)%M;
           
        if (sum != a[i][m])
            return 0;
    }
 
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            ans[i] = -1;
           
    return 1;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int caso = 1;
   
    while(t--){
        int n, m, mod;
        cin >> n >> m >> mod;
       
        vector< ll > vans;
        vector< vector<ll> > A;
           
        A.resize(n);
           
        for(int i=0; i < n; i++){
            A[i].resize(n+1, 0);
            A[i][i] = mod-1;       
        }
       
        for(int j=0; j<m; j++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            A[x][y] = 1;
            A[y][x] = 1;         
        }
 
       
        gaussMOD(A, vans, mod);
        ll ans = 1;
        for(int i=0; i<n; i++){
            if(vans[i]==-1)
                ans = (ans*mod)%1000000007LL;          
        }
       
        cout << "Case " << caso << ": " << ans << '\n';    
        caso++;
    }
   
    return 0;
}
 