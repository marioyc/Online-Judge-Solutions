#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    bool M[3000];
    bool ok;
    int n,a,b;    
    
    while(cin>>n){
        ok=true;
        
        for(int i=0;i<n;i++) M[i]=0;
        
        cin>>a;
        
        for(int i=1;i<n;i++){
            cin>>b;
            if(a==b || M[abs(b-a)] || abs(b-a)>=n) ok=0;
            else M[abs(b-a)]=1;
            a=b;
        }
        
        if(ok) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
    
}
