#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    point(int _x, int _y){
        x = _x; y = _y;
    }
    
    void normalize(){
        if(x!=0 || y!=0){
            int g = __gcd(x,y);
            x /= g; y /= g;
        }
        
        if(x<0) x = -x, y = -y;
    }
    
    bool operator < (point P)const{
        if(x!=P.x) return x < P.x;
        return y < P.y;
    }
}P1[700],P2[700];

int main(){
    int T,n;
    
    cin>>T;
    
    string line;
    getline(cin,line);
    getline(cin,line);
    
    while(T--){
        n = 0;
        
        while(getline(cin,line)){
            if(line=="") break;
            sscanf(line.c_str(),"%d %d",&P1[n].x,&P1[n].y);
            ++n;
        }
        
        int ans = 2;
        
        for(int i = 0;i<n;++i){
            for(int j = 0,k = 0;j<n;++j){
                if(j != i){
                    P2[k] = point(P1[i].x-P1[j].x,P1[i].y-P1[j].y);
                    P2[k].normalize();
                    ++k;
                }
            }
            
            sort(P2,P2+(n-1));
            int aux = 1;
            
            for(int j = 1;j+1<n;++j){
                if(P2[j].x!=P2[j-1].x || P2[j].y!=P2[j-1].y) aux = 1;
                else ++aux;
                ans = max(ans,aux+1);
            }
        }
        
        cout<<ans<<endl;
        if(T>0) cout<<endl;
    }
    
    return 0;
}
