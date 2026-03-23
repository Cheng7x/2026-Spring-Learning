#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	double m, t, s, ans;
	cin >> m >> t >> s;
	
	if (t == 0){ 
		cout << 0;
		return 0;
	}
	
	else ans = m - ceil(s / t) ;
	
	if (ans <= 0) cout << 0;
	else cout << static_cast<int>(ans);
	
	return 0;
}
