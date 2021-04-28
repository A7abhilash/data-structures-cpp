#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int partition(int arr[],int start,int end){
	int pivot=arr[end];		// End element is chosen as pivot in our program
	int pIndex=start;
	int temp;
	
	for(int i=start;i<end;i++){
		if(arr[i]<=pivot){
			//swap arr[i] & arr[pIndex]
			temp=arr[i];
			arr[i]=arr[pIndex];
			arr[pIndex]=temp;
			
			pIndex++;
		}
	}
	
	//swap arr[e] & arr[pIndex]
	temp=arr[end];
	arr[end]=arr[pIndex];
	arr[pIndex]=temp;
	
	return pIndex;
}

void quickSort(int arr[],int start,int end){
	if(start<end){
		int p=partition(arr,start,end);
		quickSort(arr,start,p-1);			//Recursice QS call for left partition
		quickSort(arr,p+1,end);			//Recursive QS call for right partition
	}
}


int main(){
	srand(time(0));
	int i,n;

	cout<<"Enter the size:\n";
	cin>>n;
	
	int arr[n];
	for(i=0;i<n;i++){
		arr[i]=rand() % 20000;
	}
		
	cout<<"Array elements:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	quickSort(arr,0,n-1);
	
	cout<<"Sorted Array elements:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
		
	return 0;
}
