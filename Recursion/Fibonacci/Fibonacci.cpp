#include<cstdio>

int Fib(int x){
	if(x == 0) return 0;
	if(x == 1) return 1;
	return Fib(x-1)+Fib(x-2);
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%d",Fib(N-1));
	return 0;
}
