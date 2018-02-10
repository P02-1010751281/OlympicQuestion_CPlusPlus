#include <cstdio>

const int Maxn = 10000 + 5;

struct set {
	int Father;
	int SonNumber; 
}Set[Maxn];

int ElementNumber,SetNumber,DoNumber;

int GetFather(int x){
	return x == Set[x].Father ? Set[x].Father : Set[x].Father = GetFather(Set[x].Father); 
} 

void Union(int x,int y){
//	Set[x].SonNumber >= Set[y].SonNumber ? Set[y].Father = x,Set[x].SonNumber += Set[y].SonNumber + 1; : Set[x].Father = y,Set[y].SonNumber += Set[x].SonNumber + 1;;
	int xFather = GetFather(x);
	int yFather = GetFather(y);
	if(Set[xFather].SonNumber >= Set[yFather].SonNumber){
		Set[xFather].SonNumber += Set[yFather].SonNumber + 1;
		Set[yFather].Father = xFather; 
	} else {
		Set[yFather].SonNumber += Set[xFather].SonNumber + 1;
		Set[xFather].Father = yFather; 
	}
}

int main(){
	scanf("%d%d",&ElementNumber,&SetNumber);
	for(int i = 1;i <= ElementNumber;i++) Set[i].Father = i;
	for(int i = 1;i <= SetNumber;i++){
		int TmpF,TmpS;
		scanf("%d%d",&TmpF,&TmpS);
		Union(TmpF,TmpS);
	}
	printf("Data End\n");
	scanf("%d",&DoNumber);
	for(int i = 1;i <= DoNumber;i++){
		int ElementOne,ElementTwo;
		scanf("%d%d",&ElementOne,&ElementTwo);
		GetFather(ElementOne) == GetFather(ElementTwo) ? printf("Yes!\n") : printf("No!\n");
	}
	return 0;
}
