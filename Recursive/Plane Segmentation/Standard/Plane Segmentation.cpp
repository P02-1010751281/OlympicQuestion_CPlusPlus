#include<cstdio>

long long N,P,Ans;

int main(){
	scanf("%lld%lld",&N,&P);
	Ans = 2*P;
	for(int i = P;i < N;i++) Ans += (i+1);
	printf("%lld",Ans);
	return 0;
} 
