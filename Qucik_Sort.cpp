
#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot=arr[end];

    int i=start-1;
    int j=start;

    for(;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
        
}

void quick_Sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int p=partition(arr,start,end);
        quick_Sort(arr,start,p-1);
        quick_Sort(arr,p+1,end);
    }
    else   
        return ;
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    int s = 0;
    int  e = size-1;
    quick_Sort(input , s , e);

}
//main code
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



