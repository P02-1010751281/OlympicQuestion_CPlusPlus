#include <cstdio>

int X,Y;

int ExGcd(int A,int B){
	if(B == 0){
		X = 1;
		Y = 0;
		return A;
	}
	int Tmp = X,Ans = ExGcd(B,A%B);
	X = Y;
	Y = X - A/B*Y;
	return Ans;
}

int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	printf("Greatest Common Divisor : %d",ExGcd(A,B));
	return 0;
}
