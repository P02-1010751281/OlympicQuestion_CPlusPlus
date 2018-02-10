#include<cstdio>

long long A[250000],a,n,m,x,t;

int main(){
	scanf("%lld%lld%lld%lld",&a,&n,&m,&x);
	A[1] = 1;
	for(int i = 2;i <= n;i++) A[i] = A[i-1]+A[i-2];
	if((m-(A[n-3]+1)*a)%(A[n-2]-1)) printf("No answer.");
	else {
		t = (m-(A[n-3]+1)*a)/(A[n-2]-1);
		printf("%lld",(A[x-2]+1)*a+(A[x-1]-1)*t);
	}
	return 0;
}
