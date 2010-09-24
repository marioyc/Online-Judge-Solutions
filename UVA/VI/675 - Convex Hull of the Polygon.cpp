#include<iostream>
#include<vector>

using namespace std;

struct punto{
    int x,y;
    
    punto(int a, int b){
        x=a;
        y=b;
    }
    
    bool operator < (punto  P)const{
        if(x!=P.x) return x<P.x;
        return y<P.y;
    }
};

vector<punto> v;

int producto(punto &A, punto &B, punto &C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

vector<punto> H;

void Hull(){
    int k=0;
    
    H.resize(2*v.size(),punto(0,0));
    
    for(int i=0;i<v.size();i++){
        while(k>=2 && producto(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    for(int i=v.size()-2, t=k+1;i>=0;i--){
        while(k>=t && producto(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    H.resize(k,punto(0,0));
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x,y;
    
    while(scanf("%d, %d",&x,&y)==2) v.push_back(punto(x,y));
        
    sort(v.begin(),v.end());
        
    H.clear();
        
    Hull();
        
    for(int i=0;i<H.size();i++)
        cout<<H[i].x<<", "<<H[i].y<<endl;
    
    return 0;
}
