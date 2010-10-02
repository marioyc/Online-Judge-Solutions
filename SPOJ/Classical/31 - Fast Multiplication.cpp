#include <cstdio>
#include <cstring>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<long double> Complex;

void FFT(vector<Complex> &A, int s){
	int n = A.size(), p = 0;
	
	while(n>1){
	    p++;
	    n >>= 1;
	}
	
	n = (1<<p);
	
	vector<Complex> a = A;
	
	for(int i = 0; i < n; ++i){
		int rev = 0;
		for(int j = 0; j < p; ++j){
			rev <<= 1;
			rev |= ( (i >> j) & 1 );
		}
		A[i] = a[rev];
	}
	
	Complex w, wn;
	
	for(int i = 1; i <= p; ++i){
		int M = 1 << i;
		int K = M >> 1;
		wn = Complex( cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M) );
		for(int j = 0; j < n; j += M){
			w = Complex(1.0, 0.0);
			for(int l = j; l < K + j; ++l){
				Complex t = w;
				t *= A[l + K];
				Complex u = A[l];
				A[l] += t;
				u -= t;
				A[l + K] = u;
				w *= wn;
			}
		}
	}
	
	if(s==-1){
        for(int i = 0;i<n;++i)
            A[i] /= (double)n;
    }
}

vector<Complex> FFT_Multiply(vector<Complex> &P, vector<Complex> &Q){
    int n = P.size()+Q.size();
    while(n!=lowbit(n)) n += lowbit(n);
    
    P.resize(n,0);
    Q.resize(n,0);
    
    FFT(P,1);
    FFT(Q,1);
    
    vector<Complex> R;
    for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
    
    FFT(R,-1);
    
    return R;
}

const long long B = 100000;
const int D = 5;

int main(){
    int n,l1,l2,L;
    char s1[10001],s2[10001];
    vector<Complex> P,Q,ans;
    vector<long long> N;
    
    scanf("%d",&n);
    
    for(int tc = 1;tc<=n;tc++){
        scanf("%s %s",s1,s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        
        P.clear(); Q.clear();
        
        for(int i = l1-1,val;i>=0;){
            val = 0;
            for(int j = D-1;j>=0;--j) if(i>=j) val = val*10+(s1[i-j]-'0');
            i -= D;
            P.push_back(Complex(val,0));
        }
        
        for(int i = l2-1,val;i>=0;){
            val = 0;
            for(int j = D-1;j>=0;--j) if(i>=j) val = val*10+(s2[i-j]-'0');
            i -= D;
            Q.push_back(Complex(val,0));
        }
        
        ans = FFT_Multiply(P,Q);
        L = ans.size();
        
        N.clear();
        for(int i = 0;i<L;++i) N.push_back((long long)round(real(ans[i])));
        
        for(;L>1 && N[L-1]==0;){
            N.pop_back();
            --L;
        }
        
        for(int i = 0;i<L;++i){
            if(N[i]>=B){
                if(i==L-1){
                    N.push_back(N[i]/B);
                    L++;
                }else N[i+1] += N[i]/B;
                N[i] %= B;
            }
        }
        
        for(int i = L-1;i>=0;--i){
            if(i<L-1){
                int d = 0, aux = N[i];
                
                if(aux>0){
                    while(aux>0){
                        aux /= 10;
                        ++d;
                    }
                }else d = 1;
                
                for(int j = d;j<D;++j) printf("0");
            }
            printf("%lld",N[i]);
        }
        printf("\n");
    }
    
    return 0;
}


