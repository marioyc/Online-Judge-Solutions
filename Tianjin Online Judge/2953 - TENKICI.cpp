#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,moves;
    
    cin>>N;
    
    vector<int> I(N);
    vector<int> J(N);
    
    for(int i=0;i<N;i++) cin>>I[i]>>J[i];
    
    sort(I.begin(),I.end());
    sort(J.begin(),J.end());
    
    moves=0;
    
    for(int i=1;i<=N;i++) moves+=abs(I[i-1]-i)+abs(J[i-1]-i);
    
    cout<<moves<<endl;
    
    return 0;
}
