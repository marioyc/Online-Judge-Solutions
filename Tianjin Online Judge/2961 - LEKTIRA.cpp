#include<iostream>
#include<string>

#define all(v) (v).begin(),(v).end()

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s,s1,s2,s3;
    string ans,aux;
    
    cin>>s;
    
    for(int i=0;i<s.size()-2;i++){
        for(int j=i+1;j<s.size()-1;j++){
            s1=s.substr(0,i+1);
            s2=s.substr(i+1,j-i);
            s3=s.substr(j+1,s.size()-j);
            
            reverse(all(s1));
            reverse(all(s2));
            reverse(all(s3));
            
            aux=s1+s2+s3;
            
            if(i==0 && j==1) ans=aux;
            else if(aux<ans) ans=aux;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
