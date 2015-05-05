#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <complex>
#include <vector>

using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) < (Y) ? (Y) : (X))
#define THRESCORR 1e-30
#define MAXN 3000
#define MAXLG 13

#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<double> Complex;

Complex tmp[1 << MAXLG];

void FFT(Complex A[], int n, int s = 1){
    int p = __builtin_ctz(n);
    
    for(int i = 0;i < n;++i)
    	tmp[i] = A[i];
    
    for(int i = 0;i < n;++i){
        int rev = 0;
        for(int j = 0;j<p;++j){
            rev <<= 1;
            rev |= ((i >> j) & 1);
        }
        A[i] = tmp[rev];
    }
    
    Complex w,wn;
    
    for(int i = 1;i <= p;++i){
        int M = (1<<i), K = (M>>1);
        wn = Complex(cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M));
        
        for(int j = 0;j<n;j += M){
            w = Complex(1.0, 0.0);
            for(int l = j;l<K+j;++l){
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

Complex a[1 << MAXLG],b[1 << MAXLG];

std::vector<double> crosscorr(const double* x, int xSize, const double * y, int ySize)
{
	std::vector<double> xcorr;

	//! Calculate the mean of the two series x[], y[]
	double xMean = 0.0;
	for (int i = 0; i < xSize; i++) {
	    if (x[i] >= 0.0 && x[i] <= 15.0)
		xMean += x[i] / xSize;
	}

	double yMean = 0.0;
	for (int i = 0; i < ySize; i++) {
	    if (y[i] >= 0.0 && y[i] <= 15.0)
		yMean += y[i] / ySize;
	}

	//! Calculate the denominator (product of standard deviations)
	double xSumCuadraticDiff = 0.0;
	for (int i = 0; i < xSize; i++) {
		xSumCuadraticDiff += pow(x[i] - xMean, 2);
	}
	
	double ySumCuadraticDiff = 0.0;
	for (int i = 0; i < ySize; i++) {
		ySumCuadraticDiff += pow(y[i] - yMean, 2);
	}

	double denom = sqrt(xSumCuadraticDiff * ySumCuadraticDiff);
	if (denom < THRESCORR){
		xcorr.resize(0);
		return xcorr;
	}

	int N = 2 * ySize - 1,lg = 0;

	while((1 << lg) < N) ++lg;
	N = (1 << lg);

	fill(a,a + N,Complex(0,0));
	fill(b,b + N,Complex(0,0));

	for(int i = 0;i < xSize;++i)
		a[i] = x[i] - xMean;

	for(int i = 0;i < ySize;++i)
		b[i] = y[i] - yMean;

	FFT(a,N);
	FFT(b,N);

	for(int i = 0;i < N;++i)
		a[i] = conj(a[i]) * b[i];

	FFT(a,N,-1);

	for(int i = 0;i < ySize - xSize + 1;++i)
		xcorr.push_back(real(a[i]) / denom);

	return xcorr;
}

double findScore(const double* wave, int waveSize, const double* pattern, int patternSize){
	double score = 0.0;
	int minSubvectorLength = 2;

	for (int subvectorStart = 0; subvectorStart <= waveSize - minSubvectorLength; subvectorStart++) {
		for (int subvectorLength = minSubvectorLength; subvectorLength <= MIN(waveSize - subvectorStart, patternSize); subvectorLength++) { 
			std::vector<double> xcorrelation = crosscorr(&(wave[subvectorStart]), subvectorLength, pattern, patternSize);
				
			for (int xcorrelationIndex = 0; xcorrelationIndex < xcorrelation.size(); xcorrelationIndex++) {
				score = MAX(score, xcorrelation[xcorrelationIndex] * subvectorLength);
			}	
    	}
	}

	return score;
}

int main(){
	int P,W;

	cin >> P >> W;

	double p[P],w[W];

	for(int i = 0;i < P;++i)
		cin >> p[i];

	for(int i = 0;i < W;++i)
		cin >> w[i];

	cout << fixed << setprecision(4) << findScore(w,W,p,P) << endl;

	return 0;
}