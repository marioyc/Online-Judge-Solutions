#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int lcs[1001][1001];

int main(){    
    int n,m;
    string s1,s2;
    
    while(getline(cin,s1)){
        getline(cin,s2);
        n=s1.size();
        m=s2.size();
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m){
                    lcs[i][j]=0;
                    continue;
                }
                if(s1[i]==s2[j]) lcs[i][j]=1+lcs[i+1][j+1];
                else lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
            }
        }
        
        printf("%d\n",lcs[0][0]);
    }
    
    return 0;
}
