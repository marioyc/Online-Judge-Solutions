#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n,m,a,b,cont;
    
    int A[20001];
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        
        memset(A,0,sizeof(A));
        
        for(int j=0;j<n;j++){
            cin>>a;
            A[a+10000]++;
        }
        
        cont=0;
        
        cin>>m;
        
        for(int j=0;j<m;j++){
            cin>>b;
            cont+=A[-b+10000];
        }
        
        cout<<cont<<endl;
    }

    return 0;
}
