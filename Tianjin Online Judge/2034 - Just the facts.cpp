#include <iostream>
#include <iomanip>

using namespace std;

int memo[10001];
int v[]={6,2,8,4};

int DIG(int n)
{
    if(n==0) return 1;
    
    if(memo[n]!=-1) return memo[n];
    
    if(n%5==0)
    {
        int k=n;
        int j=DIG(n-1);
        while(k%10==0)
            k/=10;
            
        while(k%5==0)
        {
            k/=5;
            j=v[j/2-1];
        }
        j=(j*k)%10;
        memo[n]=j;
        return j;
    }
    
        
    int x=DIG(n-1)*n;
    if(x%10!=0) x%=10;
    else
    {
        while(x%10==0)
            x/=10;
        x%=10;
    }
    memo[n]=x;
    return x;
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N;
    
    memset(memo,-1,sizeof(memo));
        
    while(cin>>N)
        cout<<setw(5)<<setiosflags(ios::right)<<N<<" -> "<<DIG(N)<<endl;

    return 0;
}
