#include <iostream> 
#include <string>


// Write a function to print the reverse of a given string.

// Function with recursion

 void reverseString(const std::string &phrase, std::string::size_type index)
 
 {
 
     if (index == phrase.length()) 
     {
        return; 
    
    }
    
    else
    {
        reverseString(phrase, index + 1);
        
        std::cout << phrase[index];

    }
 }


// Function with loop 

void reverse (const std::string &myString) 

{ 
    
    for (int i = myString.length() - 1; i >= 0; i--)
        std::cout << myString[i];
        
}
    
int main()
{
    std::cout << "Result with recursive function" << std::endl;
    std::string quoteOne = "If a man is part of nature, the work he does is also a part of it.";
    reverseString(quoteOne, 0);
    
    std::cout << "\n\n--------------------------\n";
    
    std::cout << "Result with for loop" << std::endl;
    std::cout << std::endl;
    
    std::string quoteTwo = "It was a dark and stormy night";
    reverse(quoteTwo);
    

    
    return 0;
}
