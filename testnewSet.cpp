//
//  newTest.cpp
//  cs 32 hw 1
//
//  Created by Jacqueline Nguyen on 1/24/23.

#include <iostream>
#include "newSet.h"
#include "CardSet.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Set s;
    s.insert("hi");
    s.insert("bye");
    s.insert("100");
    s.insert("2");
    s.insert("12");
    s.insert("12");
    s.insert("1");
    s.erase("1");

    Set l;
    l.insert("1");
    l.insert("100");
    l.insert("1000");

    l.swap(s);

    
   
    Set m;
           assert(m.empty());
           ItemType x = "arepa";
           assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
           m.insert("chapati");
           assert(m.size() == 1);
           assert(m.get(0, x)  &&  x == "chapati");
           cout << "Passed all tests" << endl;
    
    
    Set ss;
       ss.insert("dosa");
       assert(!ss.contains(""));
       ss.insert("tortilla");
       ss.insert("");
       ss.insert("focaccia");
       assert(ss.contains(""));
       ss.erase("dosa");
       assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("tortilla")  &&
                   ss.contains(""));
       string v;
       assert(ss.get(1, v)  &&  v == "focaccia");
       assert(ss.get(0, v)  &&  v == "");
    
    
    return 0;
}
