#include <iostream>
#include <vector>

// Given a large number N, task is to find the factorial of N.
// Example: factorial of 6 is 6*5*4*3*2*1 = 720.
std::vector<int> multiplyNum(long int num, std::vector<int> digits)
{
    long int carryDigits = 0;

    for (std::vector<int>::size_type i = 0; i < digits.size(); ++i)
    {
        long int storeCalculation = digits[i] * num + carryDigits;
        digits[i] = storeCalculation % 10;
        carryDigits = storeCalculation / 10;
    }

    while (carryDigits)
    {
        digits.push_back(carryDigits % 10);
        carryDigits = carryDigits / 10;
    }

    return digits;
}

// Function with recursion
std::vector<int> factorial(long int myNum)
{
    if (myNum <= 1)
    {
        return {1};
    }

    return multiplyNum(myNum, factorial(myNum - 1));
}

int main()
{
    long int bigNum = 100;

    std::vector<int> calcResult = factorial(bigNum);

    for (std::vector<int>::size_type i = calcResult.size(); i > 0; --i)
    {
        std::cout << calcResult[i - 1];
    }

    return 0;
}
