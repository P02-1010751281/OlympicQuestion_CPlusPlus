#include <cstdio>

const int Maxn = 1000 + 5;

int BagWeight,ThingsNumber;
int Answer[Maxn],Weight[Maxn],Value[Maxn];

int Max(int X,int Y){
	return X > Y ? X : Y;
}

void Dp(){
	for(int i = 1;i <= ThingsNumber;i++)
  		for(int j = BagWeight;j >= Weight[i];j--)
			Answer[j] = Max(Answer[j - Weight[i]] + Value[i],Answer[j]);
}

void Read(){
	scanf("%d%d",&BagWeight,&ThingsNumber);
	for(int i = 1;i <= ThingsNumber;i++) 
		scanf("%d%d",&Weight[i],&Value[i]);
}

int main(){
	Read();
	Dp();
	printf("%d",Answer[BagWeight]);
	return 0;
}
