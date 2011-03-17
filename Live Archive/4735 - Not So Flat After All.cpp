#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool isPrime[1000001];
vector<int> p;
int n = 0;

int main(){
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i<=1000000;++i){
        if(isPrime[i]){
            p.push_back(i);
            ++n;
            
            if(i<=1000)
                for(int j = i*i;j<=1000000;j += i)
                    isPrime[j] = false;
        }
    }
    
    int A,B,tc = 1;
    
    while(true){
        scanf("%d %d",&A,&B);
        if(A==0 && B==0) break;
        
        int X = 0,D = 0;
        
        for(int i = 0;i<n;++i){
            if(A%p[i]==0 || B%p[i]==0){
                ++X;
                
                int aux = 0;
                
                while(A%p[i]==0){
                    A /= p[i];
                    ++aux;
                }
                
                while(B%p[i]==0){
                    B /= p[i];
                    --aux;
                }
                
                if(aux>=0) D += aux;
                else D -= aux;
            }
        }
        
        printf("%d. %d:%d\n",tc++,X,D);
    }
    
    return 0;
}
