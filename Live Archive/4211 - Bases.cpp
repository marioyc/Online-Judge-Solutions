#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool isdigit(char c){
	return (c>='0' && c<='9');
}

vector<int> add(vector<int> &a, vector<int> &b){
	int n = a.size(),m = b.size(),sz = max(n,m);
	vector<int> c(sz,0);
	
	for(int i = 0;i<n;i++) c[i] += a[i];
	for(int i = 0;i<m;i++) c[i] += b[i];
	
	while(sz>1 && c[sz-1]==0){
		c.pop_back();
		--sz;
	}
	
	return c;
}

vector<int> multiply(vector<int> &a, vector<int> &b){
	int n = a.size(),m = b.size(),sz = n+m-1;
	vector<int> c(sz,0);
	
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			c[i+j] += a[i]*b[j];
	
	while(sz>1 && c[sz-1]==0){
		c.pop_back();
		--sz;
	}
	
	return c;
}

bool is_root(vector<int> &P, int r){
	int n = P.size();
	long long y = 0;
	
	for(int i = 0;i<n;i++){
		if(abs(y-P[i])%r!=0) return false;
		y = (y-P[i])/r;
    }
	
	return y==0;
}

int main(){
	char c,s1[18],s2[18],op1[18],op2[18];
	int L1,L2,n,m,low_lim;
	vector<int> a,b,roots;
	vector< vector<int> > P1;
	vector< vector<int> > P2;
	bool found;
	
	while(true){
		L1 = 0;
		
		while(true){
			c = getchar();
			if(c=='=') break;
			s1[L1] = c;
			++L1;
		}
		
		if(L1==0) break;
		
		L2 = 0;
		
		while(true){
			c = getchar();
			if(c=='\n') break;
			s2[L2] = c;
			++L2;
		}
		
		low_lim = 2;
		for(int i = 0;i<L1;++i) if(isdigit(s1[i])) low_lim = max(low_lim,s1[i]-'0'+1);
		for(int i = 0;i<L2;++i) if(isdigit(s2[i])) low_lim = max(low_lim,s2[i]-'0'+1);
		
		P1.clear();
		m = 0;
		
		for(int i = 0,j,k;i<L1;i = k){
			for(j = i;j<L1;++j) if(!isdigit(s1[j])) break;
			k = j;
            
			a.clear(); 
			for(j = j-1;j>=i;--j) a.push_back(s1[j]-'0');
			P1.push_back(a);
			
			if(k<L1){
				op1[m] = s1[k];
				++m; ++k;
			}
		}
		
		P2.clear();
		n = 0;
		
		for(int i = 0,j,k;i<L2;i = k){
			for(j = i;j<L2;++j) if(!isdigit(s2[j])) break;
			k = j;
			
			b.clear(); 
			for(j = j-1;j>=i;--j) b.push_back(s2[j]-'0');
			P2.push_back(b);
			
			if(k<L2){
				op2[n] = s2[k];
				++n; ++k;
			}
		}
		
		n = P1.size(); m = 1;
		
		for(int i = 1;i<n;++i){
			if(op1[i-1]=='*') P1[m-1] = multiply(P1[m-1],P1[i]);
			else P1[m++] = P1[i];
		}
		
		a = P1[0];
		for(int i=1;i<m;++i) a = add(a,P1[i]);
		
		n = P2.size(); m = 1;
		
		for(int i=1;i<n;++i){
			if(op2[i-1]=='*') P2[m-1] = multiply(P2[m-1],P2[i]);
			else P2[m++] = P2[i];
		}
		
		b = P2[0];
		for(int i = 1;i<m;++i) b = add(b,P2[i]);
		
		if(a==b) printf("%d+\n",low_lim);
		else{
			n = max(a.size(),b.size());
			a.resize(n,0);
			b.resize(n,0);            
			for(int i = 0;i<n;++i) a[i] = a[i]-b[i];
			
			roots.clear();
			
			while(n>1 && a[0]==0){
				a.erase(a.begin(),a.begin()+1);
				--n;
			}
			
			n = abs(a[0]);
			roots.clear();
			
			for(m = 1;m*m<n;++m){
				if(n%m==0){
					if(m>=low_lim && is_root(a,m)) roots.push_back(m);
					if(n/m>=low_lim && is_root(a,n/m)) roots.push_back(n/m);
				}
			}
			
			if(m*m==n && m>=low_lim && is_root(a,m)) roots.push_back(m);
			
			if(roots.empty()) printf("*\n");
			else{
				n = roots.size();
				sort(roots.begin(),roots.end());
				for(int i = 0;i<n;++i){
					if(i!=0) printf(" ");
					printf("%d",roots[i]);
				}
				printf("\n");
            }
		}
	}
	
	return 0;
}
