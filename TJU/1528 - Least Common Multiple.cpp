#include<iostream>
using namespace std;

int mcd(int &a,int b)
{
    if(a%b==0) return b;
    return mcd(b,a%b);
}

void mcm(int &a,int &b)
{
    a=a/mcd(a,b)*b;
    return;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int m;
    int x;
    int ax;    
    cin>>m;
    while(cin>>m){
        x=1;
        for(int i=0;i<m;i++){
            cin>>ax;
            mcm(x,ax);
        }
        cout<<x<<endl;
    }
    return 0;
}
