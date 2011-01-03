#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps=1e-6;

struct segment{
    double L,R;
    string s;
    
    segment(){
    }
    
    segment(const double _L, const double _R, const string _s){
        L=_L; R=_R; s=_s;
    }
    
    bool operator < (const segment &X) const{
        if(fabs(L-X.L)>eps) return L<X.L;
        return R>X.L;
    }
}a[100000];

bool used[100000];

int main(){
    int T,M,n,cont;
    double l,r,X,X2;
    bool done;
    string s1,s2,s;
    
    cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        cin>>M;
        
        n=0;
        
        while(1){
            cin>>s1>>s2;
            s=s1+" "+s2;
            istringstream is(s);
            is>>l>>r;
            
            if(fabs(l)<eps && fabs(r)<eps) break;
            if(r<=-eps) continue;
            
            a[n++]=segment(l,r,s);
        }
        
        sort(a,a+n);
        fill(used,used+n,false);
        
        done=true;
        X=cont=0;
        
        for(int i=0;i<n && X<M-eps;){
            if(a[i].L<=X+eps){
                X2=a[i].R;
                
                int pos=i;
                
                while(i<n && a[i].L<=X+eps){
                    if(a[i].R>X2-eps){
                        pos=i;
                        X2=a[i].R;
                    }
                    i++;
                }
                
                if(X2<=X+eps){
                    done=false;
                    break;
                }else X=X2;
                
                used[pos]=true;
                cont++;
            }else i++;
        }
        
        if(tc>1) cout<<endl;
        
        if(!done || X<M) cout<<0<<endl;
        else{
            cout<<cont<<endl;
            for(int i=0;i<n;i++) if(used[i]) cout<<a[i].s<<endl;
        }
    }
    
    return 0;
}
