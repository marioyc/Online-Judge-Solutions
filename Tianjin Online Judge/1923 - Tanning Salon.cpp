#include <string>
#include <iostream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,m,cont;
    string s;
    
    char M[26];
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        cin>>s;
        
        memset(M,0,sizeof(M));
        m=0;
        cont=0;
        
        for(int i=0;i<s.size();i++){
            if(M[s[i]-'A']==1) m--;
            else if(M[s[i]-'A']==0 && m+1<=n){
                M[s[i]-'A']=1;
                m++;
            }else if(M[s[i]-'A']==0 && m+1>n){
                cont++;
                M[s[i]-'A']=-1;
            }
        }
        if(cont==0) cout<<"All customers tanned successfully."<<endl;
        else cout<<cont<<" customer(s) walked away."<<endl;
    }

    return 0;
}
