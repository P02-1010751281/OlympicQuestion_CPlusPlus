#include <algorithm>
#include <cstdio>

const int BirthMaxn = 10000 + 5;
const int CakeMaxn = 2000 + 5;

int Birth,CakeNumber;
int Cake[CakeMaxn];
int CEquation[2][BirthMaxn];
int TEquation[2][BirthMaxn];

void Dp(){
	int Now = 0;
	for(int i = 1;i <= CakeNumber;i ++){
		Now ^= 1;
		for(int j = 0;j < Birth;j ++){
			CEquation[Now][j] = CEquation[Now ^ 1][j];
			TEquation[Now][j] = TEquation[Now ^ 1][j];
		}
		CEquation[Now][Cake[i] % Birth] = Cake[i];
		TEquation[Now][Cake[i] % Birth] = 1;
		for(int j = 0;j < Birth;j ++){
			if(TEquation[Now ^ 1][j]){
				if(CEquation[Now ^ 1][j] + Cake[i] > CEquation[Now ^ 1][(j + Cake[i]) % Birth]){
					CEquation[Now][(j + Cake[i]) % Birth] = CEquation[Now ^ 1][j] + Cake[i];
					TEquation[Now][(j + Cake[i]) % Birth] = TEquation[Now ^ 1][j] + 1;
				} else if(CEquation[Now ^ 1][j] + Cake[i] == CEquation[Now ^ 1][(j + Cake[i]) % Birth]){
					TEquation[Now][(j + Cake[i]) % Birth] = std::min(TEquation[Now][(j + Cake[i]) % Birth],TEquation[Now ^ 1][j] + 1);
				}
			}
		}
	}	
	if(CEquation[Now][0])
		printf("%d %d",CEquation[Now][0],TEquation[Now][0]); 
	else printf("no answer");
}

void Read(){
	scanf("%d%d",&Birth,&CakeNumber);
	for(int i = 1;i <= CakeNumber;i ++){
		scanf("%d",&Cake[i]);
	}
}

int main(){
	Read();
	Dp();
	return 0;
}
