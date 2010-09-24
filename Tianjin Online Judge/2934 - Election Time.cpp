#include <vector>
#include <algorithm>
#include <iostream>
#define all(v) (v).begin(), (v).end()
using namespace std;

struct X
{
    int ind;
    long long A;
    long long B;
    X(int x,int y, int z)
    {
        ind=x;
        A=y;
        B=z;
    }
};
bool operator <(X a, X b)
{
    return a.A<b.A;
}
int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,K;    
    cin>>N>>K;
    vector <X> v;
    int A,B;
    
    for(int i=0;i<N;i++){
        cin>>A>>B;
        v.push_back(X(i+1,A,B));
    }
    
    sort(v.rbegin(), v.rend());

    int mx=-1;
    int ax;

    for(int i=0;i<K;i++){
        if(v[i].B>mx)
        {
            mx=v[i].B;
            ax=v[i].ind;
        }
    }

    cout<<ax<<endl;

    return 0;
}
