#include <iostream>
using namespace std;

int square(int x);

int main()
{
  cout << "Hello, World!" << "\t" << square(5) << endl;
}

int square(int x)
{
  return x * x;
}