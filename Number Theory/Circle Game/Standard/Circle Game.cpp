#include <cstdio>

long long N,M,K,X;

long long FastPow(long long X,long long Y){
	long long Ans = 1;
	while(Y){
		if(Y & 1) Ans = Ans * X % N;
		X = X * X % N;
		Y >>= 1;
	}
	return Ans;
}

int main(){
	scanf("%lld%lld%lld%lld",&N,&M,&K,&X);
	printf("%lld",(X + (M * FastPow(10,K) % N) % N) % N);
	return 0;
}
