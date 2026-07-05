#include <iostream>

//Given two integers X and N, write a function to compute X to the power of N.
// We can assume that X and N are small and overflow doesn’t happen.

int calculatePower (int baseNum, int exponent)

{

    if (exponent == 0)

        {

          return 1;

        }

        else

            {

               return baseNum * calculatePower(baseNum, exponent - 1);


            }


}

// Function with for loop


int powerNum (int num, int powerExponent)

{

    int result = 1;


 for (int i = 0; i < powerExponent; i++)

     {

       result *= num;

     }

    return result;

}



int main()
{
     std::cout << "Result with recursive function" << std::endl;
     
     std::cout << calculatePower(2, 4);

     std::cout << "\n\n--------------------------\n";

     std::cout << "Result with for loop" << std::endl;

     std::cout << std::endl;

     std::cout << powerNum(2, 4);


	return 0;
}
