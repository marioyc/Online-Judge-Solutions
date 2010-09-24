#include <iostream>
#include <cstdlib>

using namespace std;

long long memo[1001];
long long f(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    
    if(memo[n]!=-1) return memo[n];
    
    int x=2*f(n-1)+f(n-2)+f(n-3);
    memo[n]=x;
    return x;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int n;
    while(cin>>n)
    {
        cout<<f(n)<<endl;
    }
    return 0;
}
