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
int mat[14][14];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void printMatrix(){
	cout << endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mat[i][j]>=0)
				cout << ' ';
			cout << mat[i][j] << ' ';
		}
		cout <<endl;
	}	
}

bool valid(int i, int j){
	if(mat[i][j] != -2)
		return false;
	for(int k=0; k<4; k++)
		if(mat[i+dx[k]][j+dy[k]] == -3)
			return false;
	return true;
}

int GrundyNumber(vector<pii> &v){
	bitset<20> bs;
	for(pii &p: v){
		int i = p.first;
		int j = p.second;
		if(valid(i, j)){
			pii copy = p;
			mat[i][j] = -3;
			p = pii(12, 12);
			bs[GrundyNumber(v)] = 1;
			mat[i][j] = -2;
			p = copy;
		}
	}
	int ans=0;
	while(bs[ans])
		ans++;
	return ans;
}

bool valid(int i, int j, int c, int id){
	if(mat[i][j] != c)
		return false;
	for(int k=0; k<4; k++)
		if(mat[i+dx[k]][j+dy[k]] == id)
			return true;
	return false;
}

vector<pii> v;
void dfs2(int i, int j, int c1, int c2, int id){
	if(!valid(i, j, c1, id))
		return;
	v.push_back(pii(i, j));
	mat[i][j] = c2;
	for(int k=0; k<4; k++)
		dfs2(i+dx[k], j+dy[k], c1, c2, id);
}

int solve(int i, int j, int x){	
	dfs2(i, j, 0, -2, x);
	int ans = GrundyNumber(v);
	//printMatrix();
	v.clear();
	dfs2(i, j, -2, -1, x);	
	v.clear();
	return ans;
}

void dfs1(int i, int j, int c1, int c2){
	if(mat[i][j] != c1)
		return;
	mat[i][j] = c2;
	for(int k=0; k<4; k++)
		dfs1(i+dx[k], j+dy[k], c1, c2);
}

int main() {
	memset(mat, -1, sizeof(mat));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char x;
			cin >> x;
			if(x == 'x')
				mat[i][j] = -1;
			else if(x == '.')
				mat[i][j] = 0;
			else 
				mat[i][j] = -2;
		}
	}
	int id = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(mat[i][j] == -2)
				dfs1(i, j, -2, id++);

	//printMatrix();
	
	int ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mat[i][j] == 0){
				for(int k=0; k<4; k++){
					if(mat[i+dx[k]][j+dy[k]] > 0){
						ans ^= solve(i, j, mat[i+dx[k]][j+dy[k]]);	
						break;
					}
				}
			}
		}
	}

	if(ans)
		cout << "First player will win" << endl;
	else
		cout << "Second player will win" << endl;
		
	return 0;
}