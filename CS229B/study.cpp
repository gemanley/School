#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int operate (int a, int b)
{
	return a*b;
}

float operate (float a, float b)
{
	return a*b;
}

union hi {
	char a;
	int b;
} un;

int main()
{
	int a = 2, b = 4;
	float n = 2.0;
	un.b = 1064;
	cout << un.a;
	return 0;
}
