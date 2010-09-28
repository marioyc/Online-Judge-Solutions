#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    int sum;
    
    while(1){
        getline(cin,s);
        if(s=="#") break;
        
        sum=0;
        
        for(int i=0;i<s.size();i++)
            if(s[i]!=' ') sum+=(i+1)*(s[i]-'A'+1);
        
        cout<<sum<<endl;
    }
    
    return 0;
}
