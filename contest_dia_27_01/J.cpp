#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
const double EPS = 1e-9;

typedef ll ftype;

// Ax + By + C = 0

ftype det(ftype a, ftype b, ftype c, ftype d) {
	return a*d - b*c;
}

struct LineInt{
	ftype a, b, c;
	LineInt() {}
	LineInt(ftype a, ftype b, ftype c): a(a), b(b), c(c) {
		normalize();
	}
	LineInt(ftype x1, ftype y1, ftype x2, ftype y2){
		a = y1 - y2;
		b = x2 - x1;
		c = -a*x1 - b*y1;		
		normalize();
	}
	
	void normalize(){
		int mdc = __gcd(abs(a), __gcd(abs(b), abs(c)));
		a /= mdc; b /= mdc; c /= mdc;
		
		if( (a < 0) or ((a==0) and (b < 0)) ){
			a = -a; 
			b = -b; 
			c = -c;
		}		
	}
	bool operator <(const LineInt &oth){
		if(a == oth.a){
			if(b == oth.b)
				return c < oth.c;
			else
				return b < oth.b;
		}
		return a < oth.a;
	}

	bool operator ==(const LineInt &oth){
		return (a == oth.a and b == oth.b and c == oth.c);
	}

};


pll l90(pll p){
	return pll(-p.y, p.x);
}

pll r90(pll p){
	return pll(p.y, -p.x);
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<LineInt> v;
		for(int i=0; i<n; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			LineInt l(a, b, c, d);
			v.push_back(l);
		}	
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		vector<pll> v2;
		for(LineInt l: v){
			v2.push_back(pll(l.a, l.b));
		}	

		map<pll, ll> cont;
		ll ans = 0;
		for(pii p: v2){
			ans += cont[l90(p)];
			ans += cont[r90(p)];
			cont[p]++;
		}
		cout << ans << endl;
	}
			
	return 0;
}