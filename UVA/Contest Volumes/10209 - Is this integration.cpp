#include<iostream>
#include<cmath>
#include<iomanip>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double a;
    
    while(cin>>a){
        cout<<fixed<<setprecision(3)<<a*a*(1-sqrt(3)+PI/3)<<" "<<a*a*(2*sqrt(3)-4+PI/3)<<" "<<a*a*(4-2*PI/3-sqrt(3))<<endl;
    }
    
    return 0;
}
