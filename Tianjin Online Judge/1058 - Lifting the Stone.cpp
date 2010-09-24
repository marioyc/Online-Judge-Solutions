#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int T,N;
    long long x0,y0,x1,y1,x2,y2,Sx,Sy,S;
    double CGx,CGy;
    
    cin>>T;
    
    for(int caso=1;caso<=T;caso++){
        cin>>N;
        
        cin>>x0>>y0;
        
        x1=x0; y1=y0;
        Sx=0; Sy=0; S=0;   
        
        for(int i=0;i<N;i++){
            if(i!=N-1) cin>>x2>>y2;
            else{
                x2=x0;
                y2=y0;
            }
            
            Sx+=(x1+x2)*(x1*y2-y1*x2);
            Sy+=(y1+y2)*(x1*y2-y1*x2);
            S+=(x1*y2-y1*x2);
            
            x1=x2; y1=y2;
        }
        
        CGx=Sx*1.0/(3*S);
        CGy=Sy*1.0/(3*S);
        
        cout<<setprecision(2)<<fixed<<CGx<<" "<<CGy<<endl;
    }
    
    return 0;
}
