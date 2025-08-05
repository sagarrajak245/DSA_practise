#include<iostream>
#include<algorithm>
using namespace std;
// it is stable algorithm
// it is inplace algorithm

void insertion_short(int arr[],int size){
for(int i=1;i<size;i++){
    int temp=arr[i];
 
int j=i-1;
    while(j>=0){
if(arr[j]>temp){
    arr[j+1]=arr[j];}// IMP NOTE: "WE ARE SHIFTING HERE NOT SWAPPING"
    else{break;}
j--;
}
arr[j+1]=temp;
}
}


void printarray(int arr[],int size){

 for(int i=0;i<size;i++){

cout<<arr[i]<<" ";
 } 
}
int main(){

int arr[5];

cout<<"enter the array\n";
for(int i=0;i<5;i++){
cin>>arr[i];
}
 insertion_short(arr,5);

cout<< "insertion short applied array is\n";
printarray(arr,5);

return 0;

}