#include <cstdio>

const int Maxn = 1000;

int Large;
int Atlas[Maxn][Maxn];

void ReadAtlas(){
	int Tmp;
	for(int i = 1;i <= Large;i++){
		for(int j = 1;j <= Large;j++){
			scanf("%d",&Tmp);
			Atlas[i][j] = Tmp ? Tmp : (int)1e9+7;
		}
	}
}

int Min(int X,int Y){
	return X <= Y ? X : Y;
}

void Floyed(){
	for(int TransferPoint = 1;TransferPoint <= Large;TransferPoint++)
		for(int Begin = 1;Begin <= Large;Begin++)
			for(int End = 1;End <= Large;End++)
				Atlas[Begin][End] = Min(Atlas[Begin][TransferPoint] + Atlas[TransferPoint][End],Atlas[Begin][End]);
}

int main(){
	int Begin,End;
	scanf("%d",&Large);
	ReadAtlas();
	scanf("%d%d",&Begin,&End);
	Floyed();
	printf("%d",Atlas[Begin][End]);
	return 0;
}
