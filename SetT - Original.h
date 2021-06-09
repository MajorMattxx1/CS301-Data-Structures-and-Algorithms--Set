#pragma once
#include<string>
#include<iostream>
#include<forward_list>
#include<unordered_map>
using namespace std;

template<class T>
class SetT
{
public:
	SetT();
	SetT(int numBucks);
	~SetT();
	void Add(T elem);
	void Remove(T elem);
	bool Contains(T elem);
	void Union(SetT otherSet);
	void Difference(SetT otherSet);
	void Intersection(SetT otherSet);
	void Filter(bool fnc(T elem));   // Extra Credit
	void Traverse(void visit(T& elem));
	int Size() { return numElems };

	SetT operator+(T elem);		  // Add
	SetT operator+(SetT& other);  // Union
	SetT operator*(SetT& other);  // Intersection
	SetT operator-(T elem);		  // Remove
	SetT operator-(SetT& other);  // Difference

private:
	forward_list<T>** buckets;	// An array of forward_list's (ie, each index is a forward_list pointer)
	int numBuckets;
	int getHashIndex(const T& elem);
	int numElems;
	// Any other private functions and variables you need
};

template<class T>
int SetT<T>::getHashIndex(const T& key)
{
	// This is done... No touching!

	unordered_map<int, T> mapper;
	typename unordered_map<int, T>::hasher hashFunction = mapper.hash_function();
	return static_cast<int>(hashFunction(key) % numBuckets);
}


template<class T>
SetT<T>::SetT()
{
	// Create an array of forward_lists and initially set each bucket to null
	buckets = new forward_list<T>*[100];
	for (int i = 0; i < 100; i++) {
		buckets[i] = nullptr;
	}
	numBuckets = 100;
}

template<class T>
SetT<T>::~SetT()
{

}

template<class T>
void SetT<T>::Add(T elem)
{
	// Add elem to the set if it doesn't already contain it
	// Get the bucket index and check to see if the bucket
	// contains elements. If the bucket has never had elements,
	// then initialize the forward_list of that bucket.  Add the
	// element to the bucket.

}

template<class T>
void SetT<T>::Remove(T elem)
{
}

template<class T>
bool SetT<T>::Contains(T elem)
{

	return false;
}

template<class T>
void SetT<T>::Union(SetT otherSet)
{

}

template<class T>
void SetT<T>::Difference(SetT otherSet)
{
}

template<class T>
void SetT<T>::Intersection(SetT otherSet)
{
}

template<class T>
void SetT<T>::Filter(bool fnc(T elem))
{
}

template<class T>
SetT<T>::SetT(int numBucks)
{

}

template<class T>
inline SetT<T> SetT<T>::operator+(T elem)
{
	this->Add(elem);
	return result;
}

template<class T>
inline SetT<T> SetT<T>::operator+(SetT<T> & other)
{
	return  SetT();  // Don't keep... just keeps compiler happy
}

template<class T>
inline SetT<T> SetT<T>::operator*(SetT & other)
{
	return SetT();	// Don't keep... just keeps compiler happy
}

template<class T>
inline SetT<T> SetT<T>::operator-(T elem)
{
	return SetT();  // Don't keep... just keeps compiler happy
}

template<class T>
inline SetT<T> SetT<T>::operator-(SetT & other)
{
	return SetT();  // Don't keep... just keeps compiler happy
}
