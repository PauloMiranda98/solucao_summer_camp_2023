#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;

	int b0=0, b1=0;
	for(int i=0; i<=n; i++){
		if(i & 1)
			b1++;
		else
			b0++;
	}

	vector<bool> v(n+1, false);
	vector<int> vp(n);
	vector<bool> va(n);
		
	for(int i=0; i<n; i++)
		vp[i] = i+1;
		
	for(int k=0; (1<<k) <= n; k++){
		int a0=0, a1=0;
		for(int i=0; i<(int)vp.size(); i++){
			cout << "? " << vp[i] << " " << k << endl;
			bool ans;
			cin >> ans;
			va[i] = ans;
			if(ans)
				a1++;
			else
				a0++;
		}
		vector<int> aux;
		if(a0 == b0){
			for(int i=0; i<(int)vp.size(); i++){
				if(va[i]){
					aux.push_back(vp[i]);
				}
			}
			for(int i=0; i<=n; i++){
				if( (i & (1<<k)) == 0){
					v[i] = true;
				}
			}
			vp = aux;
		}else{
			for(int i=0; i<(int)vp.size(); i++){
				if(!va[i]){
					aux.push_back(vp[i]);
				}
			}
			for(int i=0; i<=n; i++){
				if(i & (1<<k)){
					v[i] = true;					
				}
			}

			vp = aux;			
		}
		
		b0 = b1 = 0;
		for(int i=0; i<=n; i++){
			if(!v[i]){
				if(i & (1<<(k+1)))
					b1++;
				else
					b0++;
			}
		}
		
	}
	
	for(int i=0; i<=n; i++){
		if(!v[i]){
			cout << "! " << i << endl;
			return 0;
		}
	}
	return 0;
}