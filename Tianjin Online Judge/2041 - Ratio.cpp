#include <iostream>
#include <cmath>

using namespace std;

int mcd(int a, int b){
    if(a%b==0) return b;
    return mcd(b,a%b);
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a,b;
    double pres;
    int ax;
    int i;
    int dem;
    bool inicio=true;
    while(cin>>a>>b){
        if(!inicio) cout<<endl;
        inicio=false;
        ax=mcd(a,b);
        a/=ax;
        b/=ax;
        i=1;
        pres=6000.0;
        while(true){
            if(fabs(round(1.0*i*a/b)/i-a*1.0/b)<pres){
                pres=fabs(round(1.0*i*a/b)/i-a*1.0/b);
                cout<<round(1.0*i*a/b)<<"/"<<i<<endl;
            }
            if(i==b) break;
            i++;
        }        
    }

    return 0;
}
