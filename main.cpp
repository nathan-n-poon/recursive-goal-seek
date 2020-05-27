#include <iostream>
#include <cmath>
#define finePrecision 0.000001
#define broadPrecision 0.01
#define fineSensitivity 2.0*finePrecision
#define broadSensitivity 10*broadPrecision
#define goal 42500/15096.04
#define power 4
using namespace std;

double POverA(double interest)
{
  return (pow((1+interest),power)-1.0) / (interest*pow((1.0+interest),power));
}

double result(double arg, double (*f)(double))
{
  return (*f)(arg);
}

double average(double bound, int count)
{ 
  double difference = result(bound, POverA) - (double)goal;
  if (abs(difference) < fineSensitivity)
  {
    cout << "took " << count << " recursions" << endl;
    return bound;
  }
  if(difference < 0)
  {
    return average(bound - bound / pow(2.0,count), count + 1);
  }

  return average(bound + bound / pow(2.0,count), count + 1);
  
}

int main() {
  double avg = 999;

  avg = average(0.5 , 1);

  cout << "calculated interest: " << avg << endl;
  cout << "result: " << result(avg, POverA) << endl;
  cout << "goal: " << goal << endl;
  cout << "difference: " << result(avg, POverA)- goal<<endl; 
  
}