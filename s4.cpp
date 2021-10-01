#include<iostream>
using namespace std;
int numOdd(int* arr,int n){
	int ans=0;
	int cur = 0;
	for(int i=0;i<n;i++){
		if(arr[i]%2==1)
			cur++;
		else{
			ans = max(ans,cur);
			cur=0;
		}
	}
	return max(ans,cur);
}
int main(){
	int array[] = {1,2,3,4,5,7,9};
	cout<<"Number Odd : "<< numOdd(array,7);
	cout<<endl;
	return 0;
}
