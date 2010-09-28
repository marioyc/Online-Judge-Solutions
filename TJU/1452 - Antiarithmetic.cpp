#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    int M[10000];
    bool ok;
    
    while(1){
        scanf("%d:",&n);
        if(n==0) break;
        
        vector<int> ind(n);
        
        for(int i=0;i<n;i++){
            scanf("%d",&M[i]);
            ind[M[i]]=i+1;
        }
        
        ok=false;
        
        for(int i=0;i<n-2 && !ok;i++)
            for(int j=i+1;j<n-1 && !ok;j++)
                if(2*M[j]-M[i]>0 && 2*M[j]-M[i]<n && ind[2*M[j]-M[i]]>ind[M[j]]) ok=true;
        
        if(ok) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}
