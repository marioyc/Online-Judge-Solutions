#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    double a,b,c,D,x;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        
        D=b*b-4*a*c;
        
        if(D<0){
            cout<<"No solution!"<<endl;
            continue;
        }
        
        D=sqrt(D);
        
        if(D<1e-6) cout<<fixed<<setprecision(3)<<(-b-D)/2/a<<endl;
        else cout<<fixed<<setprecision(3)<<(-b-D)/2/a<<" "<<(-b+D)/2/a<<endl;
    }
}
