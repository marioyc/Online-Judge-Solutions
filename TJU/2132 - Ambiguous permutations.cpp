#include<iostream>

using namespace std;

int M[100000];
int N[100001];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    bool ok;    
    
    while(1){
        cin>>n;
        
        if(n==0) break;
        
        for(int i=0;i<n;i++){
            cin>>M[i];
            N[M[i]]=i+1;
        }
        
        ok=false;
        
        for(int i=0;i<n && !ok;i++){
            if(M[i]!=N[i+1]) ok=true;
        }
    
        if(!ok) cout<<"ambiguous"<<endl;
        else cout<<"not ambiguous"<<endl;
    }
}
