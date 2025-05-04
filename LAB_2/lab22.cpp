// to find the area of square, rectangle , cuboid and cube using classes 

#include<iostream>
#include<stdio.h>
using namespace std;

class areas {
    private:
    int length;
    int bredth;
    int height;

    public:
    
    areas(){   //constructor
       length =1;
       bredth =1;
       height =1;
    }
    void setlength(int l){
        length = l;
    }
    
    void setbredth(int b){
        bredth = b;
    }

    void setheight(int h){
        height = h;
    }
    
    
   float area_square();

   float area_cube();
   
   float area_rectangle();
  
   float area_cuboid();
   
};


int main() {
    areas obj;
    obj.setlength(2);
    obj.setbredth(1);
    obj.setheight(2);
    int choice;

    printf("MENU\n");
    printf("AREA OF:\n");
    printf("1.SQUARE\n2.CUBE\n3.RECTANGLE\n4.CUBOID\n5.EXIT\n");
    printf("Choose from the below menu:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        cout << "The area of the square is : " << obj.area_square() << endl;
        break;

        case 2:
         cout << "The area of the cube is : " << obj.area_cube() << endl;
         break;

        case 3:
        cout << "The area of the rectangle is: " << obj.area_rectangle() << endl;
        break;

        case 4:
        cout << "The area of the cuboid is: " << obj.area_cuboid() << endl;
        break;

        case 5:
        cout << "Exiting the program....\n" << endl;
        break;

    }

   
    return 0; 
}
//Function definitions 
   float areas::area_square(){  //function to cal area ofsquare 

     return (length*length);

   }

   float areas::area_cube(){  //function to cal area of cube

    return (6*length*length);

   }
   
   float areas::area_rectangle(){   //function to cal area of rectangle

           return length*bredth;
   }
  
   float areas::area_cuboid(){     //function to calculate area of cuboid 
        return 2*((length*bredth) + (bredth*height) + (height*length));
   }