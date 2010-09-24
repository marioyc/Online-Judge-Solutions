#include <vector>
#include <iostream>
#include <cstdio>

#define all(v) (v).begin(), (v).end()

using namespace std;

int n,k,cont=0,ax=0;

bool D1[15],D2[15];

void backtrack(int a, int x, int y)
{
    if(a==k){
        cont++;
        return;
    }
    
    if(x==0 && y==n) return;
    
    if(!D1[y+x] && !D2[y+n-1-x]){   
        
        D1[y+x]=true;
        D2[y+n-1-x]=true;
            
        backtrack(a+1,x==n-1? 0:x+1,x==n-1? y+1:y);
        
        D1[y+x]=false;
        D2[y+n-1-x]=false;           
    }
    
    backtrack(a,x==n-1? 0:x+1,x==n-1? y+1:y);
    
    return;
}

int main(){    
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    memset(D1,false,sizeof(D1));
    memset(D2,false,sizeof(D2));
    
    while(true)
    {
        scanf("%d %d",&n,&k);
        if(n==0 && k==0) break;
        
        cout<<n<<" "<<k<<" ";
        
        if(k>2*n-1){
            cout<<0<<endl;
            continue;
        }
        
        cont=0;
        
        backtrack(0,0,0);
        
        cout<<cont<<endl;
    }    

    return 0;
}
