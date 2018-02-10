#include<cstdio>
#include<cstring>

long long A,B,C,N;

int main(){
	scanf("%lld",&N);
	A = 0;
	B = 1;
	C = 1;
	for(int i = 2;C <= N;i++){
		A = B;
		B = C;
		C = A+B;
	} 
	printf("m=%lld\n",A);
	printf("%lld",B);
	return 0;
} 
