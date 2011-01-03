#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct punto{
    double x,y;
    
    punto(double a, double b){
        x=a;
        y=b;
    }
    
    bool operator < (punto P) const{
        if(x!=P.x) return x<P.x;
        return y<P.y;
    }
};

double area(punto &A, punto &B, punto &C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

int n;

vector<punto> v;
vector<punto> H;

void Hull(){
    H.clear();
    H.resize(v.size()*2,punto(0,0));
    
    int k=0;
    
    sort(v.begin(),v.end());
    
    
    for(int i=0;i<v.size();i++){
        while(k>=2 && area(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    for(int i=v.size()-2,t=k+1;i>=0;i--){
        while(k>=t && area(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    H.resize(k,punto(0,0));
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double sum1,sum2,S;
    double x,y;
    double cx,cy;
    
    while(1){
        cin>>n;
        if(n<3) break;
        
        v.clear();
        
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v.push_back(punto(x,y));
        }
        
        Hull();
        
        S=0;        
        for(int i=0;i<H.size()-1;i++) S+=H[i].x*H[i+1].y-H[i+1].x*H[i].y;
        S/=2;        
        
        sum1=0;
        for(int i=0;i<H.size()-1;i++) sum1+=(H[i].x+H[i+1].x)*(H[i].x*H[i+1].y-H[i+1].x*H[i].y);
        
        sum2=0;
        for(int i=0;i<H.size()-1;i++) sum2+=(H[i].y+H[i+1].y)*(H[i].x*H[i+1].y-H[i+1].x*H[i].y);
        
        cx=sum1/6/S;
        cy=sum2/6/S;
        
        printf("%.3f %.3f\n",cx,cy);
    }
    
    return 0;
}
