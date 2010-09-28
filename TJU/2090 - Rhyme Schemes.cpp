#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string add(string A, string B){
	int L = max(A.size(),B.size())+1;
	string C(L,'0');
	
	if(A.size()!=L-1) A = string(L-1-A.size(),'0')+A;
	if(B.size()!=L-1) B = string(L-1-B.size(),'0')+B;
	
	for(int i = L-2;i>=0;--i){
		int cur = C[i+1]-'0';
		int inc = (A[i]-'0')+(B[i]-'0');
		int to_cur = (cur+inc)%10;
		int to_next = (cur+inc)/10;
		C[i+1] = '0'+to_cur;
		C[i] = '0'+to_next;
	}
	
	while(C.size()>1 && C[0]=='0') C.erase(0,1);
	return C;
}

int M;
bool done[50][50];
string memo[50][50];

string solve(int n, int count){
	if(n==M) return "1";
	
	string &ret = memo[n][count];
	if(done[n][count]) return ret;
	done[n][count] = true;
	
	ret = "0";
	for(int i = 0;i<count;++i)
		ret = add(ret,solve(n+1,count));
	ret = add(ret,solve(n+1,count+1));
	
	return ret;
}

int main(){
	int N;
	string ans[51];
	
	for(int i = 1;i<=50;++i){
		M = i;
		memset(done,false,sizeof(done));
		ans[i] = solve(0,0);
	}
	
	while(true){
		scanf("%d",&N);
		if(N==0) break;
		printf("%d %s\n",N,ans[N].c_str());
	}
	
	return 0;
}
