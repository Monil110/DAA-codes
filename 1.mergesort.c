#include<stdlib.h>
#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
 	int n1=mid-left+1,n2=right-mid;
 	int larr[n1],rarr[n2];
 	for(int i=0;i<n1;i++)larr[i]=arr[i+left];
 	for(int j=0;j<n2;j++)rarr[j]=arr[j+mid+1];
 	int i=0,j=0,k=left;
 	while(i<n1 && j<n2){
 	 if(larr[i]<=rarr[j])arr[k++]=larr[i++];
 	 else arr[k++]=rarr[j++];
 	}
	while(i<n1)arr[k++]=larr[i++];
 	while(j<n2)arr[k++]=rarr[j++];
 }

void ms(int arr[],int left,int right) {
	if(left<right){
		int mid=left+(right-left)/2;
		ms(arr,left,mid);
		ms(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main(){
	int n;int arr[n];
	printf("\n Enter the elements of the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	ms(arr,0,n-1);
	return 0;
}