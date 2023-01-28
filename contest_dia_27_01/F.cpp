#include <bits/stdc++.h>
#define MAXN 200100
using namespace std;
int res;
int vis[MAXN][5];
char pal[MAXN];

int solve(int i, int j, int e){
	if(i > j) return e!=0;
	if(vis[i][e]) return 0;
	vis[i][e] = 1;
	if(e==0){
		int te = solve(i+1,j,1);
		if(te==1){
			res = i;
			return 1;
		}
		int td = solve(i,j-1,2);
		if(td==1){
			res = j;
			return 1;
		}
		if(pal[i] == pal[j]){
			return solve(i+1,j-1,0);
		}
	}
	if(e==1 || e == 2){
		if(pal[i]==pal[j]) return solve(i+1,j-1,e);
		return 0;
	}
	return 0;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> &pal[1];
	int n = (int) strlen(&pal[1]);
	
	int r = solve(1,n,0);
	
	if(r==1){
		cout << "YES" << endl;
		cout << res << endl;
	}else{
		cout << "NO" << endl;
	}
	
	
	return 0;
}