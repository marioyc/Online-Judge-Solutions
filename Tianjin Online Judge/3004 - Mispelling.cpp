#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,m;
    string s;
    
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>m>>s;
        
        s.erase(m-1,1);
        
        cout<<i<<" "<<s<<endl;
    }

    return 0;
}
