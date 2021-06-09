#pragma once
#include<string>
#include<iostream>
#include<forward_list>
#include<unordered_map>
#include <set> //is actually not being used, as this .h is a non-STL version of sets

using namespace std;

template<class T>
class SetT
{
public:
	SetT();//done
	SetT(int numBucks); //no idea what this does
	~SetT();//done-ish
	void Add(T elem);//done-ish
	void Remove(T elem);//done-ish
	bool Contains(T elem);//done-ish
	void Union(SetT otherSet);//done-ish
	void Difference(SetT otherSet);//done-ish
	void Intersection(SetT otherSet);//done-ish
	void Filter(bool fnc(T elem));   // Extra Credit
	void Traverse(); //done-ish, and not the originally desired version
	int Size() { return numElems; };//given

	SetT operator+(T elem);		  // Add, done-ish
	SetT operator+(SetT& other);  // Union, done-ish
	SetT operator*(SetT& other);  // Intersection, done-ish
	SetT operator-(T elem);		  // Remove, done-ish
	SetT operator-(SetT& other);  // Difference, done-ish

private:
	forward_list<T>** buckets;	// An array of forward_list's (ie, each index is a forward_list pointer)
	int numBuckets;
	int getHashIndex(const T& elem);//given
	int numElems;
	// Any other private functions and variables you need
};

template<class T>
int SetT<T>::getHashIndex(const T& key)
{
	// This is done... No touching!
	bool touched = true;

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

//what's the purpose of this contructor? 
template<class T>
SetT<T>::SetT(int numBucks)
{

}

template<class T>
SetT<T>::~SetT()
{
	delete buckets; //considering buckets is based on 'new' this should just work, riiight?
}


//the current implementation may not work at all, which is par for the course
//additionally, the buckets are going to be utterly unordered
template<class T>
void SetT<T>::Add(T elem)
{
	// Add elem to the set if it doesn't already contain it
	// Get the bucket index and check to see if the bucket
	// contains elements. If the bucket has never had elements,
	// then initialize the forward_list of that bucket.  Add the
	// element to the bucket.
	int index;
	index = getHashIndex(elem); //Get the bucket index

	if (buckets[index] == nullptr) //check to see if bucket has never had elements
	{
		//how do I initialize the bucket, this can't be it
		//"then initialize the forward_list of that bucket."
		buckets[index]->push_front(elem); //Add the element to the bucket.
	}
	else
	{
		buckets[index]->push_front(elem); //Add the element to the bucket.
	}

	numElems++;
}

//using the STL for forward_list
//simply goes to the bucket, and deletes the desired element
//i believe it automatically searches for the elem
template<class T>
void SetT<T>::Remove(T elem)
{
	int index;
	index = getHashIndex(elem); //Get the bucket index

	buckets[index]->remove(elem); //finds and removes given elem within this bucket

	numElems--;
}

//also using the STL functionality to run through a bucket, and figure out if a given elem is present
template<class T>
bool SetT<T>::Contains(T elem)
{
	int index;
	index = getHashIndex(elem); //Get the bucket index

	for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
	{
		if (buckets[index] == elem)
		{
			return true;
		}
	}

	return false;
}

//should simply be slapping the buckets from otherSet into initial set
template<class T>
void SetT<T>::Union(SetT otherSet)
{
	int index;
	for (int i = 0; i < 100; i++)
	{
		index = getHashIndex(i); //this is probably a bad idea
		if (otherSet.buckets[i] != nullptr)
		{
			for (auto it = otherSet.buckets[index]->begin(); it != otherSet.buckets[index]->end(); ++it)
			{
				//the lists have to be sorted prior to merging
				buckets[index]->sort();
				otherSet.buckets[*it]->sort();
				buckets[index]->merge(*otherSet.buckets[*it]);
				numElems++;
			}
		}
	}
}


//should be deleting buckets if first set has same ones as second set
//yes, this should probably be deleting certain elements, not whole buckets, but i am uncertain of how to do that
template<class T>
void SetT<T>::Difference(SetT otherSet)
{
	int index;
	for (int i = 0; i < 100; i++)
	{
		index = getHashIndex(i); //this is probably a bad idea
		if (otherSet.buckets[i] == buckets[index])
		{
			for (auto it = buckets[index]->begin(); it != buckets[index]->end(); ++it)
			{
				buckets[index]->remove(*it);
				numElems--;
			}
		}
	}

}

//should be deleting buckets that are not in both sets
template<class T>
void SetT<T>::Intersection(SetT otherSet)
{
	int index;
	for (int i = 0; i < 100; i++)
	{
		index = getHashIndex(i); //this is probably a bad idea
		if (otherSet.buckets[i] != buckets[index])
		{
			for (auto it = buckets[index]->begin(); it != buckets[index]->end(); ++it)
			{
				buckets[index]->remove(*it);
				numElems--;
			}

		}
	}
}

//extra credit
template<class T>
void SetT<T>::Filter(bool fnc(T elem))
{
}

//could not figure out how to do traverse as initially intended
//so, tried something else. like everything else, probably won't work, but better than nothing
template<class T>
void SetT<T>::Traverse()
{
	for (int i = 0; i < 100; i++)
	{
		if (buckets[i] != nullptr)
		{
			for (auto it = buckets[i]->begin(); it != buckets[i]->end(); ++it)
			{
				cout << buckets[*it] << " ";
			}
		}
		cout << endl;
	}
}


//each of the following overloaded  operators simply uses the methods above
//if the methods above don't work, then neither do the overloaded operators

template<class T>
inline SetT<T> SetT<T>::operator+(T elem)
{
	SetT result;
	this->Add(elem);
	return result;
}

template<class T>
inline SetT<T> SetT<T>::operator+(SetT<T> & other)
{
	SetT result;
	this->Union(other);
	return result;
}

template<class T>
inline SetT<T> SetT<T>::operator*(SetT & other)
{
	SetT result;
	this->Intersection(other);
	return result;
}

template<class T>
inline SetT<T> SetT<T>::operator-(T elem)
{
	SetT result;
	this->Remove(elem);
	return result;
}

template<class T>
inline SetT<T> SetT<T>::operator-(SetT & other)
{
	SetT result;
	this->Difference(other);
	return result;
}
