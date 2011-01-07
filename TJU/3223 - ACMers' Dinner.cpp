#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool valid(string name){
    if(name.find("spicy")!=string::npos) return false;
    if(name.find("sugar")!=string::npos) return false;
    if(name.find("pepper")!=string::npos) return false;
    if(name.find("duck")!=string::npos) return false;
    return true;
}

int main(){
    int T,N;
    double money,p,P[20],eps = 1e-9,a[(1<<10)],b[(1<<10)];
    string name;
    
    cin>>T;
    
    while(T--){
        cin>>money>>N;
        int N2 = 0;
        
        for(int i = 0;i<N;++i){
            cin>>name>>p;
            
            if(valid(name)) P[N2++] = p;
        }
        
        N = N2;
        
        if(N==0) puts("0.00");
        else if(N==1){
            if(P[0]<=money+eps) printf("%.2f\n",P[0]);
            else puts("0.00");
        }else{
            int n1 = N/2,n2 = (N+1)/2;
            int sz1 = (1<<n1),sz2 = (1<<n2);
            
            for(int mask = 0;mask<(1<<n1);++mask){
                a[mask] = 0;
                
                for(int i = 0;i<n1;++i)
                    if(mask & (1<<i))
                        a[mask] += P[i];
            }
            
            for(int mask = 0;mask<(1<<n2);++mask){
                b[mask] = 0;
                
                for(int i = 0;i<n2;++i)
                    if(mask & (1<<i))
                        b[mask] += P[n1+i];
            }
            
            sort(a,a+sz1);
            sort(b,b+sz2);
            
            double ans = 0;
            
            for(int i = 0;i<sz1;++i){
                if(a[i]+b[0]<=money+eps){
                    int lo = 0,hi = sz2-1,mi;
                    
                    while(lo<hi){
                        mi = (lo+hi+1)>>1;
                        
                        if(a[i]+b[mi]>money-eps) hi = mi-1;
                        else lo = mi;
                    }
                    
                    ans = max(ans,a[i]+b[hi]);
                }
            }
            
            printf("%.2f\n",ans);
        }
    }
    
    return 0;
}
