#include<iostream>
#include<cmath>

using namespace std;

int main(){    
    double d,v,u,t1,t2;
    int T;
    
    cin>>T;
    for(int caso=0;caso<T;caso++){
        cin>>d>>v>>u;
        
        if(v>=u || u==0 || v==0){
            printf("Case %d: can't determine\n",caso+1);
            continue;
        }
        
        t1=d/u;
        t2=d/sqrt(u*u-v*v);
        
        printf("Case %d: %.3lf\n",caso+1,fabs(t2-t1));
    }
}
