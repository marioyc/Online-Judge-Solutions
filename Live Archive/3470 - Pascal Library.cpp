#include<iostream>

using namespace std;

int main(){
    bool M[100];
    bool aux;
    int N,D;
    
    while(1){
        cin>>N>>D;
        if(N==0 && D==0) break;
        
        for(int i=0;i<N;i++) M[i]=true;
        
        for(int i=0;i<D;i++){
            for(int j=0;j<N;j++){
                cin>>aux;
                M[j]&=aux;
            }
        }
        
        for(int i=0;i<N;i++){
            if(M[i]){
                cout<<"yes"<<endl;
                break;
            }
            if(i==N-1) cout<<"no"<<endl;
        }
    }
    
    return 0;
}
