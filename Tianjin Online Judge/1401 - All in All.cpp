#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s1,s2;
    int n,cont;

    while(cin>>s1>>s2){
        n=s1.size();
        cont=0;
        
        for(int i=0;i<s2.size() && cont<n;i++)
            if(s2[i]==s1[cont]) cont++;
            
        if(cont==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
