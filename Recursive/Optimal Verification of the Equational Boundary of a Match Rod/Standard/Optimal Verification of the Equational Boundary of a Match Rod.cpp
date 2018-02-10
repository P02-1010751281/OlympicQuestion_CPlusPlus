#include <cstdio>

const int Number[10] = {6,2,5,5,4,5,6,3,7,6};

int SumN(int x){
	int Sum = 0;
	if (x == 0) return 6; 
	while(x > 0){
		Sum += Number[x%10];
		x /= 10;
	}
	return Sum;
}

int main(){
    int Total,MaxA = 0,MaxB = 0,MaxC = 0;
    scanf("%d",&Total);
    for(int i = 0;i < 1111;i++){
    	for(int j = 0;j < 1111;j++){
    		if(SumN(i) + SumN(j) + SumN(i+j) + 4 == Total) {
    			MaxA = i > MaxA ? i : MaxA;
    			MaxB = j > MaxB ? j : MaxB;
    			MaxC = i+j > MaxC ? i+j : MaxC;
    		}
    	}
    }
    printf("%d\n",MaxA);
    printf("%d\n",MaxB);
    printf("%d",MaxC);
    return 0;
}