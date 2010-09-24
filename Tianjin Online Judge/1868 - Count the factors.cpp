#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,n,cont,raiz;
    bool primo[1010];
    vector<int> p;
    
    memset(primo,1,sizeof(primo));
    
    p.push_back(2);
    
    primo[0]=primo[1]=0; primo[2]=1;
    
    for(int i=3;i<1010;i+=2){
        if(primo[i]){
            p.push_back(i);
            for(int j=2;j*i<1010;j++) primo[i*j]=0;
        }
    }
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        cont=0;
        n=N;
        
        for(int i=0;p[i]<=sqrt(N);i++){
            if(N%p[i]==0){
                while(N%p[i]==0) N/=p[i];
                cont++;
            }
        }
        if(N!=1) cont++;
        cout<<n<<" : "<<cont<<endl;
    }

    return 0;
}
