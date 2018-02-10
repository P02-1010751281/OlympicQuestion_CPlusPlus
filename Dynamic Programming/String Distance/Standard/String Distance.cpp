#include <algorithm>
#include <cstdio>
#include <cstring>

const int Maxn = 2000 + 5;

int EmptyLenth,FLenth,SLenth;
int Equation[Maxn][Maxn];
char FirstArray[Maxn],SecondArray[Maxn];

void Prepare(){
	FLenth = strlen(FirstArray);
	SLenth = strlen(SecondArray);
	for(int i = 1;i <= FLenth;i++)
		Equation[i][0] = i * EmptyLenth;
	for(int i = 1;i <= SLenth;i++)
		Equation[0][i] = i * EmptyLenth;
}

int Dp(){
	for(int i = 1;i <= FLenth;i++)
		for(int j = 1;j <= SLenth;j++)
			Equation[i][j] = std::min(std::min(Equation[i - 1][j],Equation[i][j - 1]) + EmptyLenth,Equation[i - 1][j - 1] + abs(FirstArray[i - 1] - SecondArray[j - 1]));
	return Equation[FLenth][SLenth];
}

void Read(){
	scanf("%s",FirstArray);
	scanf("%s",SecondArray);
	scanf("%d",&EmptyLenth);
}

int main(){
	Read();
	Prepare();
	printf("%d",Dp());
	return 0;
}
