#include <algorithm>
#include <cstdio>

int X,Y;

int ExGcd(int A,int B){
	if(!B){
		X = 1;
		Y = 0;
		return A;
	}
	int Ans = ExGcd(B,A % B),Tmp = X;
	X = Y;
	Y = Tmp - (A / B) * Y;
//	printf("%d %d %d %d %d\n",X,Y,A,B,Tmp);
	return Ans;
}

int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	ExGcd(A/* = std::max(A,B)*/,B/* = std::min(A,B)*/);
	printf("%d",(X + B) % B);
	return 0;
}
