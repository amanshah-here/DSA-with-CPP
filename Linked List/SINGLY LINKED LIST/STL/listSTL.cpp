#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll) {

    //* ITERATORS: used to traverse a container.

    list<int>::iterator itr;    // type of iterarator must be associated with it.

    for (itr = ll.begin(); itr != ll.end(); itr++) {    // .begin(): head Pointer of LL, .end(): tail->next pointer of the LL.
        cout << (*itr) << " -> ";
    }
    cout << "NULL\n";
}

int main() {
    list<int> ll;

    /*####################################################################################*/
    //* .push_front() & .push_back() & .size()

    ll.push_front(2);   // .push_front(): adds element to the front of LL.
    ll.push_front(1);
    
    ll.push_back(3);    // .push_back(): adds element to the last of the LL.
    ll.push_back(4);
    ll.push_back(5);

    
    cout << "Size of Linked List: " << ll.size() << endl;   // .size(): returns the size of the LL.    

    printList(ll);
    /*###################################################################################*/
    //* .front() & .back() 
    
    cout << "Head of Linked List: " << ll.front() << endl;  // .front(): returns the value of head of LL.
    
    cout << "Tail of Linked List: " << ll.back() << endl;   // .back(): returns the value of tail of LL.

    /*###################################################################################*/
    //* .pop_back() & .pop_front()

    ll.pop_front(); // .pop_front(): removes the 1st element of the LL.

    ll.pop_back();  // .pop_back(): removes the last element of the LL.

    printList(ll);
    return 0;
}