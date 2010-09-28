#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){    
    bool p[1000000];
    vector<int> P;
    
    fill(p,p+1000000,true);
    p[0]=p[1]=false;
    
    for(int i=1;i<500000;i++) p[2*i]=false;
    
    for(int i=3;i<1000000;i+=2){
        if(p[i]){
            if(i<500000) P.push_back(i);
            for(int j=2;j*i<1000000;j++) p[i*j]=false;
        }
    }
    
    int n,a,b;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;;i++){
            a=P[i];
            b=n-a;
            
            if(p[b]){
                printf("%d = %d + %d\n",n,a,b);
                break;
            }
        }
    }
    
    return 0;
}
