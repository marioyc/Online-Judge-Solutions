#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-7

double f(double x){
    return tan(sin(x)) - sin(tan(x)) + pow(cos(x),5.0) - 0.5;
}

int main(){
    ios::sync_with_stdio(0);    
    
    double a,b;
    int n;
    
    while(cin >> a >> b >> n){
        double l = (double)(b - a) / n;
        
        int ans = 0;
        
        for(int i = 0;i < n;++i){
            double x1 = a + l * i;
            double x2 = x1 + l;
            
            if(f(x1) * f(x2) < eps) ++ans;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
