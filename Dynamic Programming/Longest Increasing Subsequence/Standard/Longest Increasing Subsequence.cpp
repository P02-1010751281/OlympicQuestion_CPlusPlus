#include <cstdio>

const int Maxn = 100000 + 5;

int Array[Maxn],Equation[Maxn];
int Lenth;

//int Max(int x,int y){
//	return x >= y ? x : y;
//}

/*int Dp(){
	for(int i = 1;i <= Lenth;i++){
		if(Array[i] < Array[i-1]){
			int Position = i;
			while(Position >= 0 && Array[--Position] >= Array[i]);
			Equation[i] = Max(Equation[Position] + 1,Equation[i - 1]);
		}else Equation[i] = Equation[i - 1] + 1;
	}
	return Equation[Lenth];
}*/

int Dp(){
	int MaxLen = 0;
	for(int i = 1;i <= Lenth;i++){
		for(int j = 1;j < i;j++){
			if(Array[j] < Array[i] && Equation[j] > Equation[i])
				Equation[i] = Equation[j];
		}
		if((++Equation[i]) > MaxLen) MaxLen = Equation[i];
	}
	return MaxLen;
}

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++) scanf("%d",&Array[i]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
