#include <iostream>

using namespace std;

bool f(int n)
{
    if(n==1) return false;
    
    for(int i=2;n!=1;i++)
    {
        if(n%i==0)
        {
            if(i%10!=3) return false;
            while(n%i==0) n/=i;
        }        
    }
    return true;
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int m;
    
    while(true)
    {
        scanf("%d", &m);
        
        if(m==-1) break;
        
        if(f(m)) printf("%d YES\n",m);
        else printf("%d NO\n", m);
    }
    
    return 0;
}
