/*
ID: zion_ba1
LANG: C++
TASK: ride
*/

#include <string>
#include <iostream>

using namespace std;

int main(){
    
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    
    int a=1,b=1;
    string s;
    
    cin>>s;
    
    for(int i=0;i<s.size();i++)
    {
        a=a*(s[i]-'A'+1);
        a%=47;
    }
    
    cin>>s;
    
    for(int i=0;i<s.size();i++)
    {
        b=b*(s[i]-'A'+1);
        b%=47;
    }
    
    if(a==b) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    
    return 0;
}
