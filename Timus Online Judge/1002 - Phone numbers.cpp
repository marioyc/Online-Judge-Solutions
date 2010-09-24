#include<iostream>
#include<vector>
#include<string>

using namespace std;

string convertir(string s){
    string conv="";
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='i'||s[i]=='j') conv+="1";
        else if(s[i]=='a'||s[i]=='b'||s[i]=='c') conv+="2";
        else if(s[i]=='d'||s[i]=='e'||s[i]=='f') conv+="3";
        else if(s[i]=='g'||s[i]=='h') conv+="4";
        else if(s[i]=='k'||s[i]=='l') conv+="5";
        else if(s[i]=='m'||s[i]=='n') conv+="6";
        else if(s[i]=='p'||s[i]=='r'||s[i]=='s') conv+="7";
        else if(s[i]=='t'||s[i]=='u'||s[i]=='v') conv+="8";
        else if(s[i]=='w'||s[i]=='x'||s[i]=='y') conv+="9";
        else conv+="0";
    }
    
    return conv;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string number,aux;
    vector<string> dictionary;
    vector<string> converted;
    int n;
    int dp[101];
    
    while(cin>>number){
        if(number=="-1") break;
        
        cin>>n;
        
        dictionary.clear();
        converted.clear();
        
        for(int i=0;i<n;i++){
            cin>>aux;
            dictionary.push_back(aux);
            converted.push_back(convertir(aux));
        }
        
        fill(dp,dp+number.size()+1,(1<<20));
        dp[0]=0;
        vector<string> sequence(number.size()+1,"");
        
        for(int i=1;i<=number.size();i++){
            for(int j=0;j<n;j++){
                if(converted[j].size()<=i && number.substr(i-converted[j].size(),converted[j].size())==converted[j] && dp[i]>1+dp[i-converted[j].size()]){
                        dp[i]=1+dp[i-converted[j].size()];
                        sequence[i]=sequence[i-converted[j].size()]+dictionary[j]+" ";
                }
            }
        }
        
        if(dp[number.size()]==(1<<20)) cout<<"No solution."<<endl;
        else{
            aux=sequence[number.size()];
            aux.erase(aux.size()-1,1);
            cout<<aux<<endl;
        }
    }
    
    return 0;
}
