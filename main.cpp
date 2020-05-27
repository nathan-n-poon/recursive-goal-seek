#include <iostream>
#include <cmath>
#define finePrecision 0.000001
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
  if (abs(difference) < finePrecision)
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
  clock_t tStart = clock();
  double avg = 999;

  avg = average(0.5 , 1);

  cout << "took " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds to complete" << endl;
  cout << "calculated interest: " << avg << endl;
  cout << "result: " << result(avg, POverA) << endl;
  cout << "goal: " << goal << endl;
  cout << "difference: " << result(avg, POverA)- goal<<endl; 
  
}