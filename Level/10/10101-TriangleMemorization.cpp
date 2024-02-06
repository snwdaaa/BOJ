#include <iostream>

int main()
{
    int ang1, ang2, ang3;
    std::cin >> ang1 >> ang2 >> ang3;

    if (ang1 == 60 && ang2 == 60 && ang3 == 60)
    {
        std::cout << "Equilateral";
        return 0;
    }

    int angSum = ang1 + ang2 + ang3;
    if (angSum == 180)
    {
        if (ang1 != ang2 && ang1 != ang3 && ang2 != ang3)
        {
            std::cout << "Scalene";
        }
        else if (ang1 == ang2 || ang1 == ang3 || ang2 == ang3)
        {
            std::cout << "Isosceles";
        }
    }
    else
    {
        std::cout << "Error";
        return 0;
    }

    return 0;
}