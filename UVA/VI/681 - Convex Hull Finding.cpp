#include<iostream>
#include<vector>

using namespace std;

struct punto{
    int x,y;
    
    punto(int a, int b){
        x=a;
        y=b;
    }
    
    bool operator < (punto P) const{
        if(x!=P.x) return x<P.x;
        return y<P.y;
    }
};

vector<punto> v;
vector<punto> H;
int N;

int area(punto &A, punto &B, punto &C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

void Hull(){
    int k=0;
    
    sort(v.begin(),v.end());
    H.resize(2*N,punto(0,0));
    
    for(int i=0;i<N;i++){
        while(k>=2 && area(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    for(int i=N-2,t=k+1;i>=0;i--){
        while(k>=t && area(H[k-2],H[k-1],v[i])<=0) k--;
        H[k++]=v[i];
    }
    
    H.resize(k-1,punto(0,0));
}



int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int caso,ax,a,b,pos,x,y;
    
    cin>>caso;
    cout<<caso<<endl;
    
    for(int i=1;i<=caso;i++){
        cin>>N;
        
        v.clear();
        
        for(int j=0;j<N;j++){
            cin>>a>>b;
            v.push_back(punto(a,b));
        }
        
        H.clear();
        Hull();
        
        cout<<H.size()+1<<endl;
        
        x=(1<<30); y=(1<<30);
        for(int j=0;j<H.size();j++){
            if(H[j].y<y || (H[j].y==y && H[j].x<x)){
                y=H[j].y;
                x=H[j].x;
                pos=j;
            }
        }
        
        for(int j=0;j<H.size();j++)
            cout<<H[(j+pos)%H.size()].x<<" "<<H[(j+pos)%H.size()].y<<endl;
        cout<<H[pos].x<<" "<<H[pos].y<<endl;
        
        if(i!=caso){
            cin>>ax;
            cout<<ax<<endl;
        }
    }
}
