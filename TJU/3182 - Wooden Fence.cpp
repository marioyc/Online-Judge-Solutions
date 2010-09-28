#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct punto{
    int x,y;
    
    punto(){
    }
    
    punto(int a, int b){
        x=a;
        y=b;
    }
    
    bool operator < (punto P) const{
        if(x!=P.x) return x<P.x;
        return y>P.y;
    }
};

int area(punto A, punto B, punto C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;    
}

double length(vector<punto> &P){
    int k=0;
    sort(P.begin(),P.end());
    
    int n=P.size();
    vector<punto> H(2*n);
    
    for(int i=0;i<n;i++){
        while(k>=2 && area(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++]=P[i];
    }
    
    for(int i=n-1,t=k;i>=0;i--){
        while(k>t && area(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++]=P[i];
    }
    
    
    double ans=0.0;
    
    for(int i=0;i<k-1;i++) ans+=sqrt(pow(H[i].x-H[i+1].x,2.0)+pow(H[i].y-H[i+1].y,2.0));
    
    return ans;
}

int main(){    
    int x[16],y[16],v[16],l[16];
    int n,value,aux_value,aux_l;
    vector<punto> P;
    double L;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        value = 0;
        
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&x[i],&y[i],&v[i],&l[i]);
            value += v[i];
        }
        
        for(int mask=1;mask<(1<<n);++mask){
            P.clear();
            
            aux_value = 0;
            aux_l = 0;
            
            for(int i=0;i<n;i++){
                if((mask & (1<<i))!=0){
                    aux_value += v[i];
                    aux_l += l[i];
                }else P.push_back(punto(x[i],y[i]));
            }
            
            if(aux_value>value) continue;
            
            L=length(P);
            if(aux_l>=L && aux_value<value) value = aux_value;
        }
        
        printf("The lost value is %d.\n",value);
    }
    
    return 0;
}
