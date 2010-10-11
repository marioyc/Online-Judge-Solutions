#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int T;
    double N,ans;
    string s,u;
    
    cin>>T;
    
    for(int tc = 1;tc<=T;++tc){
        cin>>N>>s;
        
        if(s=="kg") ans = N*2.2046, u = "lb";
        else if(s=="lb") ans = N*0.4536, u = "kg";
        else if(s=="l") ans = N*0.2642, u = "g";
        else ans = N*3.7854, u = "l";
        
        printf("%d %.4lf %s\n",tc,ans,u.c_str());
    }
    
    return 0;
}
