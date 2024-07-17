//
//  CardSet.cpp
//  cs 32 hw 1
//
//  Created by Jacqueline Nguyen on 1/22/23.
//

#include <iostream>
#include "CardSet.h"
using namespace std;

CardSet::CardSet(){
    
}

bool CardSet::add(ItemType cardNumber) {
    return cardNumberSet.insert(cardNumber);
}

int CardSet::size() const {
    return cardNumberSet.size();
}

void CardSet::print() const {
    ItemType x;
    for(int i = 0; i < cardNumberSet.size(); i++) {
        cardNumberSet.get(i, x);
        cout << x << endl;
    }
}
