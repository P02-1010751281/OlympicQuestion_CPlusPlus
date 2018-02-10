#include <algorithm>
#include <cstdio>

const int Maxn = 40 + 5;
const int AMaxn = 350 + 5;
const int CMaxn = 5;

int CardsNumber,ArrayLenth;
int Array[AMaxn],Cards[CMaxn];
int Equation[Maxn][Maxn][Maxn][Maxn];

int Dp(){
	Equation[0][0][0][0] = Array[1];
	for(int OneStep = 0;OneStep <= Cards[1];OneStep++){
		for(int TwoStep = 0;TwoStep <= Cards[2];TwoStep++){
			for(int ThreeStep = 0;ThreeStep <= Cards[3];ThreeStep++){
				for(int FourStep = 0;FourStep <= Cards[4];FourStep++){
					int NextPosition = OneStep * 1 + TwoStep * 2 + ThreeStep * 3 + FourStep * 4 + 1;
					if(OneStep) Equation[OneStep][TwoStep][ThreeStep][FourStep] = std::max(Equation[OneStep][TwoStep][ThreeStep][FourStep],Equation[OneStep - 1][TwoStep][ThreeStep][FourStep] + Array[NextPosition]);
					if(TwoStep) Equation[OneStep][TwoStep][ThreeStep][FourStep] = std::max(Equation[OneStep][TwoStep][ThreeStep][FourStep],Equation[OneStep][TwoStep - 1][ThreeStep][FourStep] + Array[NextPosition]);
					if(ThreeStep) Equation[OneStep][TwoStep][ThreeStep][FourStep] = std::max(Equation[OneStep][TwoStep][ThreeStep][FourStep],Equation[OneStep][TwoStep][ThreeStep - 1][FourStep] + Array[NextPosition]);
					if(FourStep) Equation[OneStep][TwoStep][ThreeStep][FourStep] = std::max(Equation[OneStep][TwoStep][ThreeStep][FourStep],Equation[OneStep][TwoStep][ThreeStep][FourStep - 1] + Array[NextPosition]);
				}
			}
		}
	}
	return Equation[Cards[1]][Cards[2]][Cards[3]][Cards[4]];
}

void Read(){
	scanf("%d%d",&ArrayLenth,&CardsNumber);
	for(int i = 1;i <= ArrayLenth;i++)
		scanf("%d",&Array[i]);
	for(int i = 1;i <= CardsNumber;i++){
		int Tmp;
		scanf("%d",&Tmp);
		Cards[Tmp]++;
	}
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
