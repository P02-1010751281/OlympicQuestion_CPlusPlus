#include <algorithm>
#include <cstdio>
#include <cstring>

const int Maxn =  250000 + 5;

int Array[Maxn],Number[Maxn],Ans[Maxn];
int ArrayLenth = 1,NumberLenth = 1;
int N;

void Print(){
	for(int i = ArrayLenth;i >= 1;i--) 
		printf("%d",Array[i]);
} 

void Plus(){
	Number[1] += 1;
	for(int i = 1;i <= NumberLenth;i ++){
		if(Number[i] >= 10){
			Number[i + 1] += Number[i] / 10;
			Number[i] %= 10;
			if(i + 1 > NumberLenth) NumberLenth++;
		}
	}
} 

void Multiply(){
	Plus();
	int Lenth = std::max(ArrayLenth,NumberLenth);
	memset(Ans,0,sizeof(Ans));
	for(int i = 1;i <= Lenth;i++){
		for(int j = 1;j <= Lenth;j++) {
			Ans[i + j - 1] += (Array[j] * Number[i]); 
			if(Ans[i + j - 1] >= 10){ 
				Ans[i + j] += (Ans[i + j - 1] / 10);
				Ans[i + j - 1] %= 10;
				if(i + j > Lenth) Lenth = i + j; 
			} 
		}
	}
	for(int i = Lenth;i > 1 && !Ans[i];i--) Lenth--;
	memcpy(Array,Ans,sizeof(Ans));
	ArrayLenth = Lenth;
}

void Factorial(){
	Array[1] = 1;
	for(int i = 1;i <= N;i++)
		Multiply();
}

void Read(){
	scanf("%d",&N);
}

int main(){
	Read();
	Factorial();
	Print();
	return 0;
}

/*
#include<cstdio>

int A[250000],ALen = 0,N;

void Print(){
	for(int i = ALen-1;i >= 0;i--) printf("%d",A[i]);
}

void Factorial(int x){
	A[1] = 1;
	for(int i = 1;i <= x;i++){
		int Tmp = 0;
		for(int j = 0;j < ALen;j++){
			A[j] *= i;
			A[j] += Tmp;
			if(A[j] >= 10){
				Tmp = A[j]/10;
				A[j] %= 10;
				if(j == ALen) ALen++;
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	Factorial(N);
	Print();
	return 0;
}
*/
