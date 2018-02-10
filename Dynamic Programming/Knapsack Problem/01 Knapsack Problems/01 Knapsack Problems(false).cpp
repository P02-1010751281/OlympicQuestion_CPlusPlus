#include <cstdio>
#include<iostream>

struct Bag{
	int Weight;
	int Value;
};

const int Maxn = 1100 + 100;

int BagWeight,ThingsNumber;
int Answer[Maxn][Maxn];

Bag Things[Maxn];

int Max(int X,int Y){
	return X >= Y ? X:Y;
}

inline void DP(){
	for(int i = 1;i <= ThingsNumber;i++)
		for(int j = BagWeight;j > 0;j--)
			Answer[i][j] = Max(Answer[i - 1][j],Answer[i - 1][j - Things[i].Weight] + Things[i].Value);
}

int main(){
	scanf("%d%d",&BagWeight,&ThingsNumber);
//	printf("%d%d",BagWeight,ThingsNumber);
	for(int i = 1;i <= ThingsNumber;i++) scanf("%d%d",&Things[i].Weight,&Things[i].Value);
	DP();
	for(register int i=1;i<=ThingsNumber;i++){
		for(int j=1;j<=BagWeight;j++)
			std::cout<<Answer[i][j]<<" ";
			std::cout<<std::endl;
	}
	printf("%d",Answer[ThingsNumber][BagWeight]);
}

/*
10 4
2 1
3 3
4 5
7 9
*/
