#include <cstdio>

const int Maxn = 100;

int BagWeight,ThingsNumber;
int Answer[Maxn],Weight[Maxn],Value[Maxn];

int Max(int X,int Y){
	return X > Y ? X : Y;
}

int main(){
	scanf("%d%d",&BagWeight,&ThingsNumber);
	for(int i = 1;i <= ThingsNumber;i++) scanf("%d%d",&Weight[i],&Value[i]);
	for(int i = 1;i <= ThingsNumber;i++)
  		for(int j = Weight[i];j >= BagWeight;j--)
			Answer[j] = Max(Answer[j - Weight[i]] + Value[i],Answer[j]);
	printf("%d",Answer[BagWeight]);
	return 0;
}
