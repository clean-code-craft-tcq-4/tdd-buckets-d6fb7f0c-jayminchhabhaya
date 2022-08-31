#include "A2Dconverter.hpp"

int binary_to_number(int binary_digits[], int number_of_digits){
    int output = 0;
    int power = 1;

    for (int i = 0; i < number_of_digits; i++)
    {
        output += binary_digits[(number_of_digits - 1) - i] * power;
        power *= 2;
    }

    return output;
}
int A2DConvert(int numberValue)
{
  return round((10 * (float)numberValue)/ 4094);
}
std::vector<int> Getamperereadings(std::vector<int> bitintvect)
{
    std::vector<int>samples{};
   for (int i = 0; i < bitintvect.size(); i++){
    samples.push_back(A2DConvert(bitintvect[i]));
   }
   return samples;
}