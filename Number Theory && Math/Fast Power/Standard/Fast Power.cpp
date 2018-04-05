#include <cstdio>

int FastPower(int A,int B){
	if(B == 1) return A;
	register int Ans = 1;
	while(B){
		if(B & 1) Ans *= A;
		B >>= 1;
		A *= A;
	}
	return Ans;
}

int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	printf("%d",FastPower(A,B));
	return 0;
}
