#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s1,s2;
    int sum1,sum2;
    
    while(getline(cin,s1)){
        getline(cin,s2);
        
        sum1=sum2=0;
        
        for(int i=0;i<s1.size();i++){
            if(islower(s1[i])) sum1+=s1[i]-'a'+1;
            else if(isupper(s1[i])) sum1+=s1[i]-'A'+1;
        }
        
        if(sum1%9==0) sum1=9;
        else sum1%=9;
        
        for(int i=0;i<s2.size();i++){
            if(islower(s2[i])) sum2+=s2[i]-'a'+1;
            else if(isupper(s2[i])) sum2+=s2[i]-'A'+1;
        }
        
        if(sum2%9==0) sum2=9;
        else sum2%=9;
        
        if(sum1>=sum2) printf("%.2f %c\n",sum2*100.0/sum1,'%');
        else printf("%.2f %c\n",sum1*100.0/sum2,'%');
    }

    return 0;
}
