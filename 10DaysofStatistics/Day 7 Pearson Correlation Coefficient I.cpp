#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


float cal_pearson_coeff(const vector<float> &a, const vector<float> &b, int n){
	float ma = 0, mb = 0;
	float va = 0, vb = 0;
	float coeff = 0;
	
	for (int i = 0; i < n; ++i){
		ma += a[i];
		mb += b[i];	
	}
	ma /= n;
	mb /= n;
	

	float da, db;
	for (int i = 0; i < n; ++i){
	    da = a[i] - ma;
	    db = b[i] - mb;
	    va += da * da;
	    vb += db * db;
	    coeff += da*db;
	}

	return (coeff/n/sqrt(va/n)/sqrt(vb/n));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<float> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

	float coeff = cal_pearson_coeff(a, b, n);
	cout.precision(2);
    cout << coeff;
    return 0;
}
