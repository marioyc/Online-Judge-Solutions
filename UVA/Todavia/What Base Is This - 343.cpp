#include<iostream>
#include<string>
#include<vector>

using namespace std;

int valor(char c){
    if(c>='0' && c<='9') return c-'0';
    
    if(c>='A' && c<='Z') return c-'A'+10;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);    
    
    string s1,s2;
    vector<long long> v1;
    vector<long long> v2;
    long long ax;
    int n, m;
    bool enc;
    
    while(cin>>s1>>s2){
        n=0;m=0;
        
        for(int i=0;i<s1.size();i++) n=max(n,valor(s1[i])+1);
        for(int i=0;i<s2.size();i++) m=max(m,valor(s2[i])+1);
        cout<<n<<" "<<m<<endl;
        v1.clear(); v2.clear();
        
        for(int i=n;i<=36;i++){
            ax=0;
            for(int j=0;j<s1.size();j++) ax=ax*i+valor(s1[j]);
            v1.push_back(ax);
            cout<<ax<<" ";
        }
        cout<<endl;
        
        for(int i=m;i<=36;i++){
            ax=0;
            for(int j=0;j<s2.size();j++) ax=ax*i+valor(s2[j]);
            v2.push_back(ax);
            cout<<ax<<" ";
        }
        cout<<endl;
        
        enc=0;
        
        for(int i=0;i<v1.size() && !enc;i++){
            for(int j=0;j<v2.size() && !enc;j++){
                if(v1[i]==v2[j]){
                    enc=true;
                    cout<<s1<<" (base "<<i+n<<") = "<<s2<<" (base "<<j+m<<")"<<endl;
                }
            }
        }
        if(!enc) cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;

    }
    
    return 0;
}
