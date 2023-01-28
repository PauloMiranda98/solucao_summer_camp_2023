#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MOD = 1000000007;
const int SQRT = 316;
pair<int, char>  v[100010];
pair<int, char>  table[SQRT+4][SQRT+4][SQRT+4];

char query(int i){
	char c = v[i].S;
	int c_temp = v[i].F;

	int block = i/SQRT;
	for(int a=1; a<SQRT; a++){
		int i_block = i%a;
		if(table[block][i_block][a].F > c_temp){
			c_temp = table[block][i_block][a].F;
			c = table[block][i_block][a].S;
		}
	}
	return c;
}
int temp;
void update(int i, int a, int k, char c){
	temp++;	
	int last = i + a*k;
	
	if(a >= SQRT){
		for(int j=i; j<=last; j+=a)
			v[j] = make_pair(temp, c);
	}else{
		int block1 = i/SQRT + 1;
		int block2 = last/SQRT;
		
		int j = i;
		for(; j<block1*SQRT and j <= last; j += a)
			v[j] = make_pair(temp, c);
		
		for(int b=block1; b < block2; b++){
			table[b][i%a][a] = make_pair(temp, c);
			j += (((b+1)*SQRT-j+a-1)/a)*a;
		}
		for(; j <= last; j += a)
			v[j] = make_pair(temp, c);
	}
}

int n;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	n = s.size();

	for(int i=0; i<n; i++)
		v[i] = make_pair(0, s[i]);
	temp = 1;
	int q;
	cin >> q;
	while(q--){
		int i, a, k;
		char c;
		cin >> i >> a >> k >> c;
		
		update(i-1, a, k, c);
	}
	
	for(int i=0; i<n; i++)
		cout << query(i);
	cout << endl;
	
	return 0;
}
