
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
int isOutOfRange(float value, float lowerBound, float upperBound)
{
  return (value < lowerBound || value > upperBound);
}
int isGreaterThan(float value, float threshold)
{
  return (value > threshold);
}
bool batteryIsOk(float temperature, float soc, float chargeRate) 
{ 
  int count = 0;
  count = count + isOutOfRange(temperature, 0, 45);
  count = count + isOutOfRange(soc, 20, 80);
  count = count + isGreaterThan(chargeRate, 0.8);
  printf("count value: %d\n", count);
  if (count > 1)
  {
    printf("Battery not okay\n");
    return false;
  }
  else
  {
    return true;
  }
}
int main()
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
 
