//============================================================================
// Name        : Lab1-3.cpp
// Author      : Byron Laferriere
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

//forward declaration
//in C++ variables must precede their call in the code
double strToDouble(string str, char ch);

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.
// first i create a structure named bidInformation that will hold all variables needed for user bets
// we will use string for the first three variables because of the nature of mixed characters that may be input
// for bidAmount I will use a double because of the values that need to be held for each bid. Int would not be able to store a 1.5 i.e.
struct bidInformation {
	string bidTitle;
	string bidFund;
	string bidVehicleID;
	double bidAmount;
};

// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
// the ?type? is our structure previously defined
// the ?variable? will be assigned to a new variable that calls on bidInformation to access its variables
void displayBid(bidInformation bid) {
    cout << "Title: " << bid.bidTitle << endl;
    cout << "Fund: " << bid.bidFund << endl;
    cout << "Vehicle: " << bid.bidVehicleID << endl;
    cout << "Bid Amount: " << bid.bidAmount << endl;

    return;
}

// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
//again we are using the same structure for ?type?
// for ?variable? here we create another variable to access bidinformation

bidInformation getBid() {
    bidInformation someBid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, someBid.bidTitle);

    cout << "Enter fund: ";
    cin >> someBid.bidFund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, someBid.bidVehicleID);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    someBid.bidAmount = strToDouble(strAmount, '$');

    return someBid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information
	// Calling our defined structure again
	// this time we create a 3rd bid variable for the individual user's bid.
	bidInformation userBid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        // Case 1 is calling back to display previously defined userBid and assign variables to input by user. This uses the getBid to input information
        // case 2 is displaying previously entered bid information by the user.
        switch (choice) {
            case 1:
            	userBid = getBid();
                break;
            case 2:
                displayBid(userBid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
