#include<iostream>
#include<string>

using namespace std;

string memo[600][600];

int c;
string s,sum;

string suma(string a,string b)
{
	int c=0;
 
    if(a.size()>b.size()) b=string(a.size()-b.size(),'0')+b; 
 
    if(b.size()>a.size()) a=string(b.size()-a.size(),'0')+a;
 
    sum.clear();
    sum.resize(a.size());
	
    for(int i=a.size()-1;i>=0;i--){
		c+=(a[i]-'0')+(b[i]-'0');
		sum[i]=(char)('0'+c%10);
        c/=10;
    }
	
	if (c!=0){
        s="";
        s+=(char)(c+'0');
        sum.insert(0,s);
    }
	
	return sum;
}

string f(int N, int a){
    if(N==0) return "1";
    if(a>N) return "0";
    
    if(memo[N][a].empty()) memo[N][a]=suma(f(N-a,a),f(N,a+1));
    
    return memo[N][a];
}

int main(){
    int N;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        cout<<f(N,1)<<endl;
    }
    
    return 0;
}
