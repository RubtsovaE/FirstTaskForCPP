#include <iostream>
#ifndef _DYNAMIC_ARRAY_H_

class DynamicArray {
private:
	int *array = nullptr;
	int size;
	int capacityField; 
public:
	DynamicArray(); 
	DynamicArray(int);
	DynamicArray(int, int);
	DynamicArray(int, int, int);
	DynamicArray(DynamicArray&);
	DynamicArray(DynamicArray&&);
	~DynamicArray();
	int length();
	int getElem(int);
	void resize(int);
	void operator=(DynamicArray&);
	void operator=(DynamicArray&&);
	friend bool operator==(DynamicArray&, DynamicArray&);
	friend bool operator!=(DynamicArray&, DynamicArray&);
	friend bool operator<(DynamicArray&, DynamicArray&);
	friend bool operator<=(DynamicArray&, DynamicArray&);
	friend bool operator>=(DynamicArray&, DynamicArray&);
	friend bool operator>(DynamicArray&, DynamicArray&);
	friend DynamicArray operator+(DynamicArray&, DynamicArray&);
	void operator>>(DynamicArray&);
	void operator<<(DynamicArray&); 
	void reserve(int);
	int capacity();
	void pushBack(int x);
	int popBack();
};
#endif