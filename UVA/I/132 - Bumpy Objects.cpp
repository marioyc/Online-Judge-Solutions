#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;

struct punto{
    int x,y,ind;
    
    punto(){
    };
    
    punto(int a, int b, int c){
        x=a;
        y=b;
        ind=c;
    }
    
    bool operator < (punto X) const{
        return x<X.x;
    }
};

int area(punto A, punto B, punto C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

vector<punto> Convex_Hull(vector<punto> &P){
    vector<punto> H(2*P.size());
    
    sort(P.begin(),P.end());
    
    int k=0;
    
    for(int i=0;i<P.size();i++){
        while(k>=2 && area(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++]=P[i];
    }
    
    for(int i=P.size()-1,t=k;i>=0;i--){
        while(k>t && area(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++]=P[i];
    }
    
    H.resize(k);
    
    return H;
}

bool base_line(punto CM, punto A, punto B){
    if(area(A,B,CM)<=0) return false;
    if((CM.x-A.x)*(B.x-A.x)+(CM.y-A.y)*(B.y-A.y)<0) return false;
    if((CM.x-B.x)*(A.x-B.x)+(CM.y-B.y)*(A.y-B.y)<0) return false;
    return true;
}

int main(){
    int CMX,CMY,x,y,ind,ans;
    vector<punto> P;
    vector<punto> H;
    punto CM;
    string ID;
    
    while(1){
        cin>>ID;
        if(ID=="#") break;        
        
        cin>>CMX>>CMY;
        CM=punto(CMX,CMY,0);
        
        ind=1;
        P.clear();
        
        while(1){
            cin>>x>>y;
            if(x==0 && y==0) break;
            P.push_back(punto(x,y,ind));
            ind++;
        }
        
        H=Convex_Hull(P);
        
        ans=INT_MAX;
        
        for(int i=0;i<H.size()-1;i++){
            if(base_line(CM,H[i],H[i+1])) ans=min(ans,max(H[i].ind,H[i+1].ind));
        }
        cout<<setw(21)<<setiosflags(ios::left)<<ID<<ans<<endl;
    }
    
    return 0;
}
