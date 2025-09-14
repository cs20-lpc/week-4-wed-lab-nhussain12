// #include "LinkedList.hpp"
// #include <string>

// int main() {
//     // call the constructor
//     LinkedList<string> myList;

//     // add elements to the list
//     myList.append("Heart");
//     myList.insert(0, "Your");
//     myList.insert(0, "May");

//     // try replacing as an invalid operation
//     try {
//         myList.replace(-3, "?");
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // add another element
//     myList.append("Citrus");

//     // try inserting as an invalid operation
//     try {
//         myList.insert(5, "kweh");
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // remove an element
//     myList.remove(3);

//     // display the state of the list
//     cout << myList;

//     // get the second element and display it
//     string word = myList.getElement(2);
//     cout << "Element 2: " << word << endl;

//     // create a second list using the copy constructor
//     LinkedList<string> secondList = myList;

//     // modify the second list and display its state
//     secondList.append("Beat");
//     secondList.replace(2, "Drums");
//     cout << secondList;

//     // try removing an element as an invalid operation
//     try {
//         secondList.remove(4);
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // create a third list using the default constructor (max size of 100)
//     LinkedList<string> thirdList;

//     // display the state of the list, should be empty
//     cout << thirdList;

//     // copy the first list to the third list using assignment overload
//     thirdList = myList;

//     // display the length and max size, should match the first list
//     cout << "thirdList length: " << thirdList.getLength() << endl;

//     // add elements to the list
//     thirdList.append("Be A");
//     thirdList.append("Yellow");
//     thirdList.append("Banana");

//     // display the state of the list
//     cout << thirdList;

//     // try getting elements as an invalid operation
//     try {
//         cout << thirdList.getElement(-7) << endl;
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }
//     try {
//         cout << thirdList.getElement(7) << endl;
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // clear out the list and verify it is now empty
//     myList.clear();
//     if (myList.isEmpty()) {
//         cout << "myList is empty!\n";
//     }

//     // terminate
//     return 0;
// }

#include "LinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    // Test #1: Creating an Empty List
    LinkedList<int> intList;
    cout << "TEST #1: Creating an Empty List\n";
    cout << "List Length: " << intList.getLength() << endl;
    cout << "Check for Emptiness: ";

    if(intList.isEmpty()) {
        cout << "✅" << endl;
    } else {
        cout << "❌"<< endl;
    }

    // String List
    LinkedList<string> stringList;
    cout << "STRING LIST" << endl;
    cout << "List Length: " << stringList.getLength() << endl;
    cout << "Check for Emptiness: ";

    if(stringList.isEmpty()) {
        cout << "✅" << endl;
    } else {
        cout << "❌"<< endl;
    }

    // Test #2: Appending a List
    cout << endl;
    cout << "TEST #2: Appending a List\n";
    cout << "Integer List After Multiple Appends" << endl;
    intList.append(0);
    cout << intList << endl;
    intList.append(1);
    cout << intList << endl;
    intList.append(2);
    cout << intList << endl;

    // String List
    cout << "String List After Multiple Appends" << endl;
    stringList.append("Chocolate");
    cout << stringList << endl;
    stringList.append("Vanilla");
    cout << stringList << endl;

    cout << "Integer List Length: " << intList.getLength() << endl;
    cout << "String List Length: " << stringList.getLength() << endl;

    // Test #3: Getting Elements and Replacing Elements in a List
    cout << endl;
    cout << "TEST #3: Getting/Replacing Elements in a List\n";
    cout << "Integer Value at Position 2: " << intList.getElement(1) << endl;
    cout << "Integer Value at Position -1: ";

    // Try an Invalid Position
    try {
        intList.getElement(-1);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    // Replace Values
    intList.replace(1, 100);
    cout << endl;
    cout << "After Replace Function: " << intList << endl;
    cout << "New Integer Value at Position 2: " << intList.getElement(1) << endl;
    intList.append(300);
    cout << "Integer Value at Position 3: " << intList.getElement(2) << endl;

    // String List
    cout << endl;
    cout << "STRING LIST" << endl;
    stringList.append("Strawberry");
    stringList.append("Mint Chocolate Chip");
    cout << "Appended String List: " << stringList << endl;

    cout << "String Value at Position 3: " << stringList.getElement(2) << endl;
    cout << "String Value at Position 4: " << stringList.getElement(3) << endl;
    stringList.replace(2, "Mint Chocolate Chip");
    stringList.replace(3, "Strawberry");
    cout << "String List with Replace: " << stringList << endl;
    cout << "String Value at Position 6: ";

    // Try an Invalid Replace
    try {
        stringList.replace(5, "Butterscotch");
    } catch (const string& e) {
        cout << e << endl;
    }

    // Test #4: Clearing a List
    cout << endl;
    cout << "TEST #4: Clearing a List\n";
    cout << "Current Integer List: " << intList << endl;
    intList.clear();
    cout << "Integer List After Clear: " << intList << endl;
    cout << "Check for Emptiness: ";

    if(intList.isEmpty()) {
        cout << "✅" << endl;
    } else {
        cout << "❌"<< endl;
    }

    cout << endl;
    cout << "STRING LIST" << endl;
    cout << "Initial String List: " << stringList << endl;
    stringList.clear();
    cout << "String List After Clear: " << stringList << endl;
    cout << "List Length: " << stringList.getLength() << endl;
    cout << "Check for Emptiness: ";

    if(stringList.isEmpty()) {
        cout << "✅" << endl;
    } else {
        cout << "❌"<< endl;
    }

    // Test #5: Clearing an Already Empty List
    cout << endl;
    cout << "TEST #5: Clearing an Already Empty List\n";
    LinkedList<int> emptyList;
    cout << "Initial List (should be empty): " << emptyList << endl;;
    cout << "Initial Length: " << emptyList.getLength() << endl;
    
    // Attempt to clear the empty list
    emptyList.clear();
    cout << "After Clear: " << emptyList << endl;;
    cout << "Length After Clear: " << emptyList.getLength() << endl;
    cout << "Is the list still empty? ";
    
    if(emptyList.isEmpty()) {
        cout << "✅" << endl;
    } else {
        cout << "❌" << endl;
    }

    // Test #6: Inserting/Removing Nodes from a List
    cout << endl;
    cout << "TEST #6: Inserting/Removing Nodes from a List\n";
    LinkedList<int> numList;
    numList.append(30);
    numList.append(48);
    numList.append(70);
    numList.append(83);
    numList.append(95);
    cout << "Initial List: " << numList << endl;
    numList.insert(3, 100);
    cout << "List After Inserting 100 @ Position = 3: " << numList << endl;
    cout << "List After Insert at Invalid Position 6: ";
    try {
        numList.insert(6, 200);
    } catch (const string& e) {
        cout << e << endl;
    }
    numList.remove(3);
    cout << "List After Removing 100: " << numList << endl;
    cout << "List After Removing a Node at Invalid Position -2: ";
    try {
        numList.remove(-2);
    } catch (const string& e) {
        cout << e << endl;
    }
    cout << endl;

    cout << "=> String List\n";
    stringList.append("Chocolate");
    stringList.append("Vanilla");
    stringList.append("Strawberry");
    stringList.append("Mint Chocolate Chip");
    cout << "Initial String List: " << stringList << endl;
    stringList.insert(2, "Butterscotch");
    cout << "String List After Insertion: " << stringList << endl;
    stringList.remove(3);
    cout << "String List After Remove: " << stringList << endl;

    // Test #7: Copying one List to another
    cout << endl;
    cout << "TEST #7: Copying from One List to Another\n";
    cout << "numList: " << numList << endl;
    cout << "intList: " << intList << endl;
    intList = numList;
    cout << "intList After Copy: " << intList << endl;
    cout << "numList After Copy: " << numList << endl;
    cout << endl;

    cout << "=> String List\n";
    LinkedList<string> copiedStringList(stringList);
    cout << "stringList: " << stringList << endl;
    cout << "copiedStringList: " << copiedStringList << endl;

    return 0;
}
