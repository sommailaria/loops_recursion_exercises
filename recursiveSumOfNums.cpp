// Given a number n, find the sum of the first n natural numbers

#include <iostream>

// Function with recursion
int sumNumbers(int num) 
{
    
    if (num <= 1) return num;
    
    else 
        return num + sumNumbers(num - 1);

 }
 

 // Function with loop
 
 int addNumbers(int num) 
 
 
 { 
     int sum = 0;
     int counter = num;
     
     for(int i = 0; i < counter; i++)
     { 
         
        sum = sum + num;
        num--;
       
     }
     
        return sum;
    }
 
 
int main()
{
    std::cout << "Result of function with recursion:" << std::endl;
    
	std::cout << sumNumbers(5) << std::endl;
    
    std::cout << "Result of function with loop:" << std::endl;
    
    std::cout << addNumbers(5);
}
