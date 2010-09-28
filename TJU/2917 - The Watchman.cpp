#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    float S;
    
    while(true){
        cin>>S;
        if(S<0) break;
        
        cout<<fixed<<setprecision(2)<<sqrt(2*S)<<endl;
    }

    return 0;
}
