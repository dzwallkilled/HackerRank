#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<float> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<float> tempa, tempb;
    tempa = a, tempb = b;
    sort(tempa.begin(),tempa.end());
    sort(tempb.begin(),tempb.end());
    map<float, int> ordera, orderb;
    for (int i = 0; i < n; ++i) {
        ordera[tempa[i]] = i;
        orderb[tempb[i]] = i;
    }
    
    float coeff = 0;
    for (int i = 0; i < n; ++i){
        coeff += pow((ordera[a[i]] - orderb[b[i]]), 2);
    }
    
    coeff = 1 - 6*coeff/n/(n*n-1);
    cout.precision(3);
    cout << coeff;
    return 0;
}

