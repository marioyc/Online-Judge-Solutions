#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;
    int N;
    
    while(1){
        cin>>s;
        if(s=="0") break;
        
        N=0;
        
        for(int i=s.size()-1,j=0;i>=0;i--){
            N+=(s[i]-'0')*((1<<j+1)-1);
            j++;
        }
        
        cout<<N<<endl;
    }

    return 0;
}
