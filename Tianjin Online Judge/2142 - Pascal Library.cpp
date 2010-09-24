#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,D;
    bool M[100];
    bool ax;
    
    while(1){
        scanf("%d %d",&N,&D);
        if(N==0 && D==0) break;
        
        fill(M,M+N,1);
        
        for(int i=0;i<D;i++){
            for(int j=0;j<N;j++){
                cin>>ax;
                M[j]=M[j]&&ax;
            }
        }
        ax=false;
        for(int i=0;i<N;i++){
            if(M[i]){
                cout<<"yes"<<endl;
                ax=true;
                break;
            }
        }
        
        if(!ax) cout<<"no"<<endl;
    }
    
    return 0;
}
