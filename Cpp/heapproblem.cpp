// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;

int left =( 2 * i) +1;

int right =( 2 * i) +2;

if( left < n && arr [largest] < arr [ left ] )

largest = left ;
if( right < n && arr[ largest] < arr[ right ])

 largest= right;

if( largest != i)
{
swap (arr[i] , arr[largest]);
heapify (arr , n , largest);
}  
     }
   public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    
      int pos = (n-1) / 2 ;
for(int i = pos ; i>= 0 ; i-- ){
heapify( arr , n , i ) ;
 }
    }
   public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
       buildHeap(arr,n);
for (int i = n - 1; i > 0; i--) {
swap(arr[0], arr[i]);
heapify(arr, i, 0);
}
    }
};

 

 

// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}