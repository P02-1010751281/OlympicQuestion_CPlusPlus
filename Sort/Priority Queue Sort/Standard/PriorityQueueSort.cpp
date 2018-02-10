#include<cstdio>
#include<queue>

std::priority_queue <int> Sort;

int main(){
	int Len,Tmp;
	scanf("%d",&Len);
	for(int i = 0;i < Len;i++){
		scanf("%d",&Tmp);
		Sort.push(-Tmp);
	}
	for(int i = 0;i < Len;i++) {
		printf("%d ",-Sort.top());
		Sort.pop();
	}
	return 0;
}
