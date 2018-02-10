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
    int Total,Ans = 0;
    scanf("%d",&Total);
    for(int i = 0;i < 712;i++){
    	for(int j = 0;j < 712;j++){
    		if(SumN(i) + SumN(j) + SumN(i+j) + 4 == Total) Ans++;
    	}
    }
    printf("%d\n",Ans);
    return 0;
}