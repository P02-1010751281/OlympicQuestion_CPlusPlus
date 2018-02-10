#include <cstdio>
#include <algorithm>

const int Maxn = 100000 + 5;

int Lenth,Equation[2][Maxn];
int FirstArray[Maxn],SecondArray[Maxn];

int Dp(){
	int x = 0,Max;
	for(int i = 1;i <= Lenth;i++){
		x ^= 1;
		for(int j = 1;j <= Lenth;j++){
			if(FirstArray[i] == SecondArray[j])
				Equation[x][j] = std::max(std::max(Equation[x ^ 1][j],Equation[x][j - 1]),Equation[x ^ 1][j - 1] + 1);
			else Equation[x][j] = std::max(Equation[x ^ 1][j],Equation[x][j - 1]);
			Max = std::max(Max,Equation[x][j]);
		}
	}
	return Max;
}

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++)
		scanf("%d",&FirstArray[i]);
	for(int i = 1;i <= Lenth;i++)
		scanf("%d",&SecondArray[i]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
