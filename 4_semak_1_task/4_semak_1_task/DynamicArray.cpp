#include "stdafx.h"
#include "stdexcept"
#include <iostream>
#include "DynamicArray.h"
#define SIZE 11


DynamicArray::DynamicArray():
size(SIZE),
array(new int[SIZE]),
capacityField(SIZE)
{
	for (int i = 0; i < size; i++){
		array[i] = 0;
	}
}

DynamicArray::DynamicArray(int sizeEnter) :
size(sizeEnter),
array(new int[sizeEnter]),
capacityField(sizeEnter)
{
	for (int i = 0; i < size; i++){
		array[i] = 0;
	}
}

DynamicArray::DynamicArray(int sizeEnter, int n) :
size(sizeEnter),
array(new int[sizeEnter]),
capacityField(sizeEnter)
{
	for (int i = 0; i < size; i++){
		array[i] = n;
	}
}

DynamicArray::DynamicArray(int sizeEnter, int n, int capacityEnter) :
size(sizeEnter),
array(new int[sizeEnter]),
capacityField(capacityEnter)
{
	for (int i = 0; i < size; i++){
		array[i] = n;
	}
}

DynamicArray::DynamicArray(DynamicArray& src) : //src - source
size(src.size),
array(new int(src.size)),
capacityField(src.capacityField)
{
	for (int i = 0; i < size; i++) {
		array[i] = src.array[i];
	}
}

DynamicArray::DynamicArray(DynamicArray&& src):
size(0),
array(nullptr), 
capacityField(0)
{
	size = src.size;
	array = new int(src.size);
	capacityField = src.capacityField;
	for (int i = 0; i < size; i++) {
		array[i] = src.array[i];
	}
	src.array = nullptr;
	src.size = 0;
	src.capacityField = 0;
}

DynamicArray::~DynamicArray(){
	delete[] array;
}

int DynamicArray::length(){
	return size;
}

int DynamicArray::getElem(int i){
	if (i < 0 || i >= size) {
		throw std::out_of_range("Index does not belong to array.");
	}
	return array[i-1];
}

void DynamicArray::resize(int newSize){
	if (capacityField >= newSize){
		for (int i = size; i < newSize; i++){
			array[i] = 0;
		}
		capacityField -= newSize - size;
		size = newSize;
	}
	else{
		int *buffer= new int[size];
		for (int i = 0; i < size; i++){
			buffer[i] = array[i];
		}
		delete[] array;
		array = new int[newSize];
		for (int i = 0; i < newSize; i++) {
			array[i] = buffer[i];
		}
		delete[] buffer;
		capacityField += size - newSize;
		size = newSize;
	}
}

void DynamicArray::operator=(DynamicArray& arr){
	if (this != &arr) {
		size = arr.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = arr.array[i];
		}
	}
}

void DynamicArray::operator=(DynamicArray&& arr){
	if (this != &arr) {
		delete[] array;
		size = arr.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = arr.array[i];
		}
	}
}

bool operator==(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 == &arr2) {
		return true;
	}
	if (arr1.size != arr2.size) {
		return false;
	}
	for (int i = 0; i < arr1.size; i++) {
		if (arr1.array[i] != arr2.array[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 != &arr2) {
		return true;
	}
	if (arr1.size != arr2.size) {
		return true;
	}
	for (int i = 0; i < arr1.size; i++) {
		if (arr1.array[i] == arr2.array[i]) {
			return false;
		}
	}
	return true;
}

bool operator<(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 == &arr2) {
		return false;
	}
	int min = (arr1.size < arr2.size) ? arr1.size : arr2.size;
	for (int i = 0; i < min; i++) {
		if (arr1.array[i] == arr2.array[i]) {
			continue;
		}
		return arr1.array[i] < arr2.array[i];
	}
	return false;
}

bool operator<=(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 == &arr2) {
		return true;
	}
	return (arr1.array[0] <= arr2.array[0]);
}

bool operator>(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 == &arr2) {
		return false;
	}
	int min = (arr1.size < arr2.size) ? arr1.size : arr2.size;
	for (int i = 0; i < min; i++) {
		if (arr1.array[i] == arr2.array[i]) {
			continue;
		}
		return arr1.array[i] > arr2.array[i];
	}
	return false;
}

bool operator>=(DynamicArray& arr1, DynamicArray& arr2) {
	if (&arr1 == &arr2) {
		return true;
	}
	return (arr1.array[0] >= arr2.array[0]);
}

DynamicArray operator+(DynamicArray& m1, DynamicArray& m2){
	DynamicArray m3 = DynamicArray(m1.size + m2.size);
	for (int i = 0; i < m1.size; i++) {
		m3.array[i] = m1.array[i];
	}
	for (int i = 0; i < m2.size; i++) {
		m3.array[m1.size + i] = m2.array[i];
	}
	return m3;
}
 
void DynamicArray::operator>>(DynamicArray& arr) {
	for (int i = 0; i < arr.size; i++) {
		std::cin >> arr.array[i];
	}
}

void DynamicArray::operator<<(DynamicArray &arr) {
	std::cout << "array: ";
	for (int i = 0; i < arr.size; i++) {
		std::cout << arr.array[i] << (i == arr.size - 1 ? "." : ", ");
	}
}

void DynamicArray::reserve(int n){
	capacityField = size + n;
	if (array != nullptr){
		int *buffer = new int[size];
		for (int i = 0; i < size; i++) {
			buffer[i] = array[i];
		}
		delete[] array;
		array = new int[capacityField];
		for (int i = 0; i < size; i++) {
			array[i] = buffer[i];
		}
		return;
	}
	array = new int[capacityField];
}

int DynamicArray::capacity() {
	return capacityField;
}

void DynamicArray::pushBack(int x) {
	if (capacityField <= size) {
		reserve(1);
	}
	array[size++] = x;
}

int DynamicArray::popBack(){
	int x = array[size--];
	resize(size - 1);
	return x;
}