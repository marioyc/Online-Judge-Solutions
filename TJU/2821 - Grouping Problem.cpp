#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,sum,min_diff,aux;
    int W[15];
    
    while(cin>>N,N!=0){
        sum=0;
        
        for(int i=0;i<N;i++){
            cin>>W[i];
            sum+=W[i];
        }
        
        min_diff=(1<<20);
        
        for(int mask=1;mask<(1<<N);mask++){
            aux=0;
            
            for(int i=0;i<N;i++)
                if((mask & (1<<i))!=0) aux+=W[i];
            
            min_diff=min(min_diff,abs(sum-2*aux));
        }
        
        cout<<min_diff<<endl;
    }
    
    return 0;
}
