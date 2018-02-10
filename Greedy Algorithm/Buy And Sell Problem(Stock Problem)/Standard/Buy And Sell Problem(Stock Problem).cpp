#include <cstdio>

const int Maxn = 100000;

int DirectMoney[Maxn];
int Money,Total;

void Greedy(){
	int Day = 0;
	while(++Day <= Total)
		if(DirectMoney[Day] >= DirectMoney[Day-1])
			Money *= DirectMoney[Day];
}

int main(){
	scanf("%d%d",&Money,&Total);
	for(int i = 1;i <= Total;i++)
		scanf("%d",&DirectMoney[i]);
	Greedy();
	printf("%d",Money);
	return 0;
}
