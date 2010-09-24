#include <iostream>

using namespace std;

int mod(int a, int b, int c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        int x=mod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * mod(a,b-1,c))%c;
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int B,P,M;
    
    while(cin>>B>>P>>M)
        cout<<mod(B,P,M)<<endl;

	return 0;
}
