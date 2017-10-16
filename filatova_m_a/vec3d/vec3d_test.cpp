#include "vec3d.h"
#include <iostream>

using namespace std;

int main() 
{
	Vec3d obj;
	cout << obj << endl;
	Vec3d obj1(4, 2, 0);
	cout << obj1 << endl;
	obj1 *= 4;
	cout << "*4 " << obj1 << endl;
	obj1 /= 4;
	cout << "/4 " << obj1 << endl;
    cout << "obj + obj1 is " << obj + obj1 << endl;
    cout << "obj * obj1 is " << obj * obj1 << endl;
}
