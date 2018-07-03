/*
 * copyright Abderrahmen Rakez
 *
 * */

#include <stdio.h>
#include <typeinfo>
#include "./Set.h"

/* constructor [[*/
// _________________________________________________________________________
template<class T>
Set<T>::Set() {
    _elements = new T[1];
    _size = 1;
    // initialize the list with "pipes"
    if (typeid(T) == typeid(int)) {
        for (int i = 0; i < _size; ++i) {
            _elements[i] = '|';
        }
    }
    _numberOfElements = 0;
}
/*]]*/

/* destructor [[*/
// _________________________________________________________________________
template<class T>
Set<T>::~Set() {
    delete[] _elements;
}
/*]]*/

/* insert [[*/
// _________________________________________________________________________
template <class T>
void Set<T>::insert(T c) {
    // condition to check if the size of the array is not enough
    // else create new array with enough space (2 * size)
    if (_size == _numberOfElements) {
        _size *= 2;
        // copy the elements
        T *resize = new T[_size];
        for (int i = 0; i < _size; ++i) {
            resize[i] = '|';
        }
        for (int i = 0; i < _numberOfElements; ++i) {
            resize[i] = _elements[i];
        }
        // delete the old array
        delete[] _elements;
        // create the array with the new size
        _elements = new T[_size];
        for (int i = 0; i < _size; ++i) {
            _elements[i] = resize[i];
        }

        // delete the resize array
        delete[] resize;
    }
    // add element to list if it's not exist
    if (_numberOfElements < _size) {
        // check if the element already exists
        if (!lookup(c)) {
            _elements[_numberOfElements] = c;
            _numberOfElements++;
        }
    }
}
/*]]*/

/* lookup [[*/
// _________________________________________________________________________
template <class T>
bool Set<T>::lookup(T a) const {
    // go through all elements
    for (int i = 0; i < _size; ++i) {
        // if exist
        if (_elements[i] == a) {
            return true;
        }
    }
    return false;
}
/*]]*/

/* erase [[*/
// _________________________________________________________________________
template<class T>
void Set<T>::erase(T c) {
    // do erase if exist
    if (lookup(c)) {
        for (int i = 0; i < _numberOfElements; ++i) {
            if (_elements[i] == c) {
                printf("erase\n");
                // erase by switching the last element to
                // position of the erased element
                _elements[i] = _elements[_numberOfElements - 1];
                _elements[_numberOfElements - 1] = '|';
                _numberOfElements--;
            }
        }
    }
}
/*]]*/

template class Set<int>;

int Set<char>::_counter = 0;

// special case char

/* constructor [[*/
// _________________________________________________________________________
Set<char>::Set() {
    _elements = new char[300];
    for (int i = 0; i < 300; ++i) {
        _elements[i] = static_cast<char>(i + 65);
    }
    _size = 0;
    _numberOfElements = 0;
}
/*]]*/

/* destructor [[*/
// _________________________________________________________________________
Set<char>::~Set() {
    delete[] _elements;
}
/*]]*/

/* insert [[*/
// _________________________________________________________________________
void Set<char>::insert(char c) {
    // size
    _size = 300;
    // store each element in the position of his own
    // dec value
    if (!lookup(c)) {  // check if exist
        if (int(c) < 0) {
            int cInt = (~c - 1) + 4;
            _elements[cInt] = c;
        } else {
            _elements[int(c)] = c;
        }
    }
}
/*]]*/

/* lookup [[*/
// _________________________________________________________________________
bool Set<char>::lookup(char c) {
    // return false, if no elements in the list
    if (_size == 0) {
        return false;
    }
    // if exist
    if (int(c) < 0) {
        int cInt = (~c - 1) + 4;
        if (_elements[cInt] == c) {
            return true;
        }
    }
    else if (_elements[int(c)] == c) {
        return true;
    }
    return false;
}
/*]]*/

/* erase [[*/
// _________________________________________________________________________
void Set<char>::erase(char c) {
    // counter to check all elements
    // do erase if exist
    if (lookup(c)) {
        _elements[int(c)] = c + 1;
    }
}
/*]]*/

/* printElement [[*/
void Set<char>::printElement() {
    for (int i = 0; i < _size; ++i) {
        printf("element %d\n", _elements[i]);
    }
}
/*]]*/
