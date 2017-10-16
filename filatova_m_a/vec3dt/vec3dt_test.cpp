#include "vec3dt.h"
#include <iostream>

using namespace std;

int main() 
{
	Vec3dt obj;
	cout << obj << endl;
	Vec3dt obj1(4, 2, 0);
	cout << obj1 << endl;
	obj1 *= 4;
	cout << "*4 " << obj1 << endl;
	obj1 /= 4;
	cout << "/4 " << obj1 << endl;
    cout << "obj + obj1 is " << obj + obj1 << endl;
    cout << "obj * obj1 is " << obj * obj1 << endl;
}
