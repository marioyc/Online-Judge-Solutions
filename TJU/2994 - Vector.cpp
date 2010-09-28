#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n;
    string s1,s2;
    int x,a,b;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        getline(cin,s1);
        getline(cin,s1);
        getline(cin,s2);
        istringstream is1(s1);
        istringstream is2(s2);
        
        x=0;
        for(int j=0;j<n;j++){
            is1>>a;
            is2>>b;
            x+=a*b;
        }
        cout<<x<<endl;
    }

    return 0;
}
