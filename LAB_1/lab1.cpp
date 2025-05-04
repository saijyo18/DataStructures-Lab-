#include<stdio.h>
//programming to sort the elements 
// bubblesort 
void bubblesort(int arr[], int n)
{
    
    for(int i=0;i<n-1 ; i++)
    {
        for(int j=0; j< n-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//selection sort 
void selectionsort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++) 
    {
        int smallestindex = i;  
        for(int j = i+1; j < n; j++)  
        {
            if(arr[j] < arr[smallestindex])  
            {
                smallestindex = j;
            }
        }

        if(smallestindex != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallestindex];
            arr[smallestindex] = temp;
        }
    }
}

//insertionsort
void insertionsort(int arr[] , int n)
{
    for (int i = 1; i < n; i++) {
        int current = arr[i];      
        int previous = i - 1;    
        
        while (previous >= 0 && arr[previous] > current) {
            arr[previous + 1] = arr[previous];  
            previous--;  
        }

        
        arr[previous + 1] = current;  
    }
    }



int main()
{  
   int arr[] = {45,32,44,2,4,5};
   int n = sizeof(arr)/sizeof(arr[0]);

    int number;
    printf("Choose the number from the following menu :\n");
    printf("1.Bubblesort\n2.Selectionsort\n3.Insertionsort\n4.Exit\n");
    scanf("%d", &number);

    if(number == 1)
    {
        bubblesort(arr,n);
        for(int i = 0 ; i< n ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    if(number == 2)
    {
        selectionsort(arr,n);
        for(int i=0 ; i<n ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

   if(number == 3)
   {
     insertionsort(arr,n);
     for( int i=0 ; i<n ; i++)
     {
        printf("%d ", arr[i]);
     }
     printf("\n");

   }

   if(number == 4)
   {
    printf("Exiting the program.....\n");
    return 0;
   }


    return 0;
}