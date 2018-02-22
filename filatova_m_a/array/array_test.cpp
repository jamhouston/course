#include <iostream>
#include "array.h"  
int main()
{
	using namespace std;
	Array obj;
	for (int i = 10; i >= 5; --i)
	{
		obj.Push_back(i);
	}
	for (int i = 0; i < obj.Size(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;
	Array obj1;
	obj1 = obj;
	for (int i = 0; i < obj1.Size(); i++)
	{
		cout << obj1[i] << " ";
	}
	cout << endl;
	obj.Insert(2, 0);
	for (int i = 0; i < obj.Size(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;
	int exit;
	cin >> exit;
}
