#include <cstdio>

int N,R;

void Change(int Num){
	int K = Num % R;
	Num /= R;
	if(K < 0){
		K -= R;
		++ Num;
	}
	if(Num != 0) Change(Num);
	if(K > 9) printf("%c",K - 10 + 'A');
	else printf("%d",K);
}

int main(){
	scanf("%d%d",&N,&R);
	printf("%d=",N);
	Change(N);
	printf("(base%d)",R);
	return 0;
}
