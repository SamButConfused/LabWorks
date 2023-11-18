#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
 
// function to print distance
void distance(float x1, float y1,
            float z1, float x2,
            float y2, float z2)
{
    float d = sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) +
                pow(z2 - z1, 2) * 1.0);
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << " Distance is " << d;
    return;
}
 
// Driver Code
int main()
{
    float x1 = 1;
    float y1 = -9;
    float z1 = 8;
    float x2 = 11;
    float y2 = -5;
    float z2 = 12;
     
    // function call for distance
    distance(x1, y1, z1,
            x2, y2, z2);
    return 0;
}
