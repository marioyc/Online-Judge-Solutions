#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int C,n,s;
    double prom;
    cin>>C;
    
    for(int i=0;i<C;i++){
        cin>>n;
        vector<int> v(n);
        
        s=0;
        
        for(int j=0;j<n;j++){
            cin>>v[j];
            s+=v[j];
        }
        
        prom=s*1.0/n;
        
        s=0;
        
        for(int j=0;j<n;j++)
            if(v[j]>prom) s++;
            
        cout<<fixed<<setprecision(3)<<s*1.0/n*100<<"%"<<endl;
    }

    return 0;
}
