#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,cont;
    vector<int> p;
    bool primo[32768];
    
    p.push_back(2);
    memset(primo,1,sizeof(primo));
    p[0]=p[1]=0;p[2]=1;
    
    for(int i=2;i<(1<<15);i++){
        if(primo[i]){
            p.push_back(i);
            for(int j=2;j*i<32768;j++) primo[i*j]=0;
        }
    }
    
    while(1){
        scanf("%d",&n);        
        if(n==0) break;
        
        cont=0;
        
        for(int i=0;p[i]<=n/2;i++){
            if(primo[n-p[i]]) cont++;
        }
        
        cout<<cont<<endl;
    }

    return 0;
}
