//program for linear search and binary seach 
#include<stdio.h>
#include"header.h"

void linearsearch(int arr[], int n, int key);
void binarysearch(int arr[], int n, int key);


int main()
{
    int arr[]= { 2,3,4,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int number, key;

    printf("Enter the number you want to search:\n");
    scanf("%d", &key);
    printf("MENU:\n");
    printf("1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("3.Exit\n");
    printf("Choose the method from above menu:\n");
    scanf("%d", &number);

    if(number == 1)
    {  
        bubblesort(arr,n);
        linearsearch(arr, n, key);
    }

    if(number == 2)
    {
        bubblesort(arr,n);
        binarysearch(arr,n,key);
    }

    if(number == 3)
    {
        printf("Exiting the program....\n");
        return 0;
    }
   return 0;
}

//linearsearch code
void linearsearch(int arr[], int n , int key)
{
    int i;
    int found =0;
    for( i = 0 ; i <n ; i++)
    {
        if(arr[i] == key)
        {
            printf("The number %d is found at %d index\n", key, i);
            found = 1;
            break;

        }
    }
    if(!found)
    {
        printf("The number is not there in the list\n");
    }
}

//binary search to search the element 
void binarysearch(int arr[], int n , int key)
{
    int i;
    int low = 0;
    int high = n-1;
    int mid;
    int found;

    while(low <= high)
    {
        mid =( low + high )/2;
        if(arr[mid] == key)
        {
            printf("The element %d is found at index %d\n", key, mid);
            found = 1;
            break;
        }
        if(arr[mid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
    }

}