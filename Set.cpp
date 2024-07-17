//
//  Set.cpp
//  cs 32 hw 1
//
//  Created by Jacqueline Nguyen on 1/20/23.
//

#include "Set.h"
#include <iostream>
using namespace std;

Set::Set() {
    nOfItems = 0;
}

bool Set::empty() const{
    return nOfItems == 0;
}
// Return true if the set is empty, otherwise false.

int Set::size() const{
    return nOfItems;
}  // Return the number of items in the set.

bool Set::insert(const ItemType& value) {
    if (nOfItems == DEFAULT_MAX_ITEMS) {
        return false;
    }
    if (nOfItems == 0) {
        nOfItems = 1;
        set[0] = value;
            return true;
    }

    for (int i = 0; i < nOfItems; i++) {
        if (set[i] == value)
        return false;
    }

    for (int i = 0; i < nOfItems; i++) {
        if (set[i] > value) {

        for (int j = nOfItems; j > i; j--) {
            set[j] = set[j - 1];
        }

        set[i] = value;
        nOfItems++;
        return true;
        }
    }

    set[nOfItems] = value;
    nOfItems++;

    return true;
}
  // Insert value into the set if it is not already present.  Return
  // true if the value is actually inserted.  Leave the set unchanged
  // and return false if value is not inserted (perhaps because it
  // was already in the set or because the set has a fixed capacity and
  // is full).

bool Set::erase(const ItemType& value) {
    for (int i = 0; i < nOfItems; i++) {
        if (value == set[i]) {
            for(int j = i; j < nOfItems-1; j++) {
                set[j] = set[j+1];
            }
            nOfItems--;
            return true;
        }
    }

    return false;
}
  // Remove the value from the set if it is present.  Return true if the
  // value was removed; otherwise, leave the set unchanged and
  // return false.

bool Set::contains(const ItemType& value) const{
    for (int i= 0; i < nOfItems; i++) {
        if(set[i]==value) {
            return true;
        }
    }
    return false;
}
  // Return true if the value is in the set, otherwise false.

bool Set::get(int i, ItemType& value) const{
    if (i < 0 || i >= nOfItems)
            return false;
    value = set[i];
    return true;
}
  // If 0 <= i < size(), copy into value the item in the set that is
  // strictly greater than exactly i items in the set and return true.
  // Otherwise, leave value unchanged and return false.


void Set::swap(Set& other) {
    ItemType temp[DEFAULT_MAX_ITEMS];
    int newNOfItems = 0;

    // loop for setting temp
    if (nOfItems >= other.nOfItems) {
        newNOfItems= nOfItems;
        for (int i = 0; i < newNOfItems; i++) {
            temp[i] = set[i];
        }
        for (int i = 0; i < other.nOfItems; i++) {
            set[i]= other.set[i];
        }
        for (int i = 0; i < nOfItems; i++) {
            other.set[i]= temp[i];
        }
        nOfItems = other.nOfItems;
        other.nOfItems= newNOfItems;
    } else {
        newNOfItems = other.nOfItems;
        for (int i = 0; i < newNOfItems; i++) {
            temp[i] = other.set[i];
        }
        for (int i = 0; i < nOfItems; i++) {
            other.set[i]=set[i];
        }
        for (int i = 0; i < other.nOfItems; i++) {
            set[i]= temp[i];
        }
        other.nOfItems= nOfItems;
        nOfItems = newNOfItems;
    }

//    cout << "og " << endl;
//    for (int i = 0; i < nOfItems; i++) {
//        cout << set[i] << endl;
//    }
//    cout << "other" << endl;
//    for (int i = 0; i < other.nOfItems; i++) {
//        cout << other.set[i] << endl;
//    }
}
  // Exchange the contents of this set with the other one.

void Set::dump() const {
    cerr << nOfItems << endl;
    for (int i = 0; i < nOfItems; i++) {
        cerr << set[i] << endl;
    }
}
