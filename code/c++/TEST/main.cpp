#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
include using namespace std;
#define PI 3.14159
class Circle
{
public:
	Circle() {}
	Circle(double, double);
	double SIZE();
	double square();
	Circle operator=(Circle &temp)
	{
		radius = temp.radius;
		high = temp.high;
		return temp;
	}

private:
	double radius;
	double high;
};
Circle::Circle(double r, double h)
{
	radius = r;
	high = h;
}
double Circle::SIZE()
{
	double temp = PI * radius * radius * high;
	return temp;
}
double Circle::square()
{
	double temp = PI * radius * radius;
	return temp;
}
int main()
{
	Circle A(2, 5), B;
	cout

		int
		main()
	{
		int n;
		cin >> n;
		cout << "Counts:";
		for (int i = 0; i < n; i++)
		{
			char sa[100];
			cin >> sa;
			cout << MyNumCount(sa) << " ";
		}

		return 0;
	}
