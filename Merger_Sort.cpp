
void merger(int input[] , int si ,int mid ,int ei){
    int i , j;
    int n1 = mid - si +1;
    int n2 = ei - mid ;
    int arr1[n1] , arr2[n2];
    int s = si ;
    for(i=0;i<n1 ; i++)
    {
        arr1[i] = input[s];
        s++;
    }
    for(j=0;j<n2 ; j++)
    {
        arr2[j] = input[s];
        s++;
    }
    i = 0;
    j = 0;
    s = si;
    
    while(i<n1 && j<n2)
    {
       if(arr1[i]>arr2[j])
       {
           input[s] = arr2[j];
           s++;
           j++;
       }
        else
        {
            input[s] = arr1[i];
            i++;
            s++;
        }
    }
    while(i<n1)
    {
        input[s] = arr1[i];
        s++;
        i++;
    }
    while(j<n2)
    {
        input[s] = arr2[j];
        j++;
        s++;
    }
   
    
}
void merge_sort(int input[], int si , int ei){
    if(si>=ei)
        return ;
    int mid = (si+ei)/2;
    merge_sort(input , si ,mid);
    merge_sort(input, mid+1, ei);
    merger(input , si, mid ,ei);
}

void mergeSort(int input[], int size){
	// Write your code here
    int s = 0,e=size-1;
         merge_sort(input , s , e);
    return ;
        
}

// main code
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
