#include <algorithm>
#include <cstdio>

const int BirthMaxn = 10000 + 5;
const int CakeMaxn = 2000 + 5;

int Birth,CakeNumber;
int Cake[CakeMaxn];
int CEquation[CakeMaxn][BirthMaxn];
int TEquation[CakeMaxn][BirthMaxn];

void Dp(){
	for(int i = 1;i <= CakeNumber;i ++){
		for(int j = 0;j < Birth;j ++){
			CEquation[i][j] = CEquation[i - 1][j];
			TEquation[i][j] = TEquation[i - 1][j];
		}
		CEquation[i][Cake[i] % Birth] = Cake[i];
		TEquation[i][Cake[i] % Birth] = 1;
		for(int j = 0;j < Birth;j ++){
			if(TEquation[i - 1][j]){
				if(CEquation[i - 1][j] + Cake[i] > CEquation[i - 1][(j + Cake[i]) % Birth]){
					CEquation[i][(j + Cake[i]) % Birth] = CEquation[i - 1][j] + Cake[i];
					TEquation[i][(j + Cake[i]) % Birth] = TEquation[i - 1][j] + 1;
				} else if(CEquation[i - 1][j] + Cake[i] == CEquation[i - 1][(j + Cake[i]) % Birth]){
					TEquation[i][(j + Cake[i]) % Birth] = std::min(TEquation[i][(j + Cake[i]) % Birth],TEquation[i - 1][j] + 1);
				}
			}
		}
	}	
	if(CEquation[CakeNumber][0])
		printf("%d %d",CEquation[CakeNumber][0],TEquation[CakeNumber][0]); 
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
