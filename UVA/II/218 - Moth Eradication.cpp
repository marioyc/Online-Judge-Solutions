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

vector<punto> v;
vector<punto> H;
int N;

double area(punto &a, punto &b, punto &c){
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

void Hull(){
    int k=0;
    
    sort(v.begin(),v.end());
    H.resize(2*N,punto(0,0));
    
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
    
    double x,y;
    int caso=0;
    double p;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        if(caso>0) cout<<endl;
        caso++;
        
        v.clear();
        for(int i=0;i<N;i++){
            cin>>x>>y;
            v.push_back(punto(x,y));
        }
        
        H.clear();
        Hull();
        
        printf("Region #%d:\n",caso);
        for(int i=H.size()-1;i>=0;i--){
            printf("(%.1f,%.1f)",H[i].x,H[i].y);
            if(i!=0) printf("-");
        }
        p=0;
        for(int i=0;i<H.size()-1;i++)
            p+=sqrt(pow(H[i].x-H[i+1].x,2)+pow(H[i].y-H[i+1].y,2));
        printf("\nPerimeter length = %.2f\n",p);
    }
    
    return 0;
}
