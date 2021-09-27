#include<stdio.h>

int arr[10] = { 12, 1324, 3243, 43, 44, 88, 12333, 34, 33, 4};

int main()
{
    
	int sum = 0;
        int size = sizeof(arr);
  
    	//add all elements to the variable sum.
    	for(int i = 0; i < size; i++)
        	sum = sum + arr[i]; // same as sum += arr[i];
    
    	//print the result
    	printf("Sum of the array = %d\n",sum);
    
   	 return 0;
}




