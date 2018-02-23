#ifndef QUEUEA_H
#define QUEUEA_H

#include <iosfwd>
#include <iostream>
#include "array.h"

class QueueA
{

public:
	QueueA() = default;
	~QueueA();

	void Pop();
	void Push(int item);
	bool IsEmpty();
	ptrdiff_t GetTop();

private:
  int head_ { 0 };
  int tail_ { 0 };
  Array queue;


};



#endif
