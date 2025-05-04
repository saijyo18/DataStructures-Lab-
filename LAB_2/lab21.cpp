//program to check if a number is a pallindrome or perfect number or armstrong 
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>


using namespace std;

class numbers {
    public:

    int pallindrome(int *num2){
        int *remainder = (int*)malloc(sizeof(int));
        int *sum =(int*)malloc(sizeof(int));
        *sum =0;
    
        int temp = *num2;
        while( temp != 0){
            *remainder = temp % 10;
            (*sum) = ((*sum)*10) + (*remainder);
            temp = temp/10;

        }

        return (*sum);

    }

    int armstrong(int *num1){
         int *count = (int*)malloc(sizeof(int));
         *count = 0;
         int *sum1 = (int*)malloc(sizeof(int));
         *sum1 =0;
         int remainder;
         int temp = *num1;
         while(temp != 0){
                     (*count)++;
                     temp = temp/10;
            }
        temp = *num1;
        while(temp != 0)
        {   
            remainder = temp % 10;
            (*sum1) += int(pow(remainder,(*count)));
            temp = temp/10;
        }

        return (*sum1);

         }
         
    
    int perfectnumber( int *num){
        int *i;
        int *sum = (int*)malloc(sizeof(int));;
        *sum =0;
        i = (int*)malloc(sizeof(int));
        for( (*i) = 1 ; (*i) < (*num) ; (*i)++)
        {
            if((*num) % (*i) == 0 )
            {
                (*sum) = (*sum) + (*i);
            }
        
        }
        free(i);
        return (*sum);
    }

};

int main(){
    
    printf("MENU:\n");
    printf("1 .Pallindrome\n2 .Armstron number\n3 .Perfect number\n4. Exit");
    int choice;
    printf("Choose any option from the menu:");
    scanf("%d",&choice);
    int *number1 = (int*)malloc(sizeof(int));
    int *number = (int*)malloc(sizeof(int));
    int *number2 = (int*)malloc(sizeof(int));
    int *suma = (int*)malloc(sizeof(int));
    int *sump = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));

    switch (choice) {
        case 1:
        printf("Enter the number : ");
        scanf("%d", number2);

        numbers obj2;
        *sump = obj2.pallindrome(number2);
        if((*sump) == (*number2)){
            printf("The number is a pallindrome.\n");
        }
        else{
            printf("The number is not a pallindrome.\n");
        }

        break;

        case 2:

        printf("Enter the number: ");
        scanf("%d", number1);

        numbers obj1;
        (*suma) = obj1.armstrong(number1);
        if ((*suma) == (*number1))
           printf("The number is an armstrong number.\n");
        else 
           printf("The number is not an armstrong.\n");
        break;

        case 3: 

        printf("Enter the number: ");
        scanf("%d", number);
         numbers obj;
         *sum = obj.perfectnumber(number);
         
         if((*sum) == (*number))
         {
             printf("The number is a perfect number.\n");
         }
         else
         {
             printf("The number is not a perfect number.\n");
         }
         free(number);
         break;
        
        case 4:

        printf("Exc=iting from the program.\n");
        break;

    }


   return 0;    
}