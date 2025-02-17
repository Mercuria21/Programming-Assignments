/*
Created by Danial Johan on 30/10/2024
PROBLEM: Write a complete C++ program of a simple mobile phone bill. A call is charged 5 cents per minute. The
cost for line rental is RM19.90 per month. The tax for the overall bill is 6%. Calculate the total amount
the user needs to pay to the Telco based on the number of minutes the user uses his/her mobile phone
for call each month

IOFC: Input: minutes
      Output: totalBill 
      Formula: callCost = minutes * call_rate;
               preTaxTotal = line_rental + callCost;
               taxAmount = preTaxTotal * tax_rate;
               totalBill = preTaxTotal + taxAmount;

      Conditions: n/a

IO FORMAT: Line 1: Enter the number of minutes used: minutes
           Line 2: 
           Line 3: ---------- Mobile Phone Bill ----------
           Line 4: Line Rental: line_rental
           Line 5: Call Charges: call_rate
           Line 6: Tax (6%): tax_rate
           Line 7: ---------------------------------------
           Line 8: Total Bill: totalBill

VARIABLES/CONSTANTS: 1. line_rental
                     2. call_rate
                     3. tax_rate
                     4. minutes
                     5. callCost
                     6. preTaxTotal
                     7. taxAmount
                     8. totalBill

PSEUDOCODE: 
          START
            SET line_rental = 19.90, call_rate = 0.05, tax_rate = 0.06
            INPUT minutes
            CALCULATE callCost = minutes * call_rate
            CALCULATE preTaxTotal = line_rental + callCost
            CALCULATE taxAmount = preTaxTotal * tax_rate
            CALCULATE totalBill = preTaxTotal + taxAmount
            OUTPUT dotted line and message and totalBill
          END

TEST CASES: Input:
                  minutes: 9
            Output: 
                  ---------- Mobile Phone Bill ----------
                  Line Rental: RM 19.90
                  Call Charges (RM 0.05 per minute): RM 0.45
                  Tax (6%): RM 1.22
                  ---------------------------------------
                  Total Bill: RM 21.57
                  
I hereby declare that this C++ program is the result of my
own work. No part of the program has been copied or altered
from other student(s)or by other student(s)or from other
sources such as ChatGPT, books, Internet, etc.
*/

#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    // Constants
    const double line_rental = 19.90;
    const double call_rate = 0.05;
    const double tax_rate = 0.06;

    // Variables
    int minutes;
    double callCost, preTaxTotal, taxAmount, totalBill;

    // Input
    cout << "Enter the number of minutes used: ";
    cin >> minutes;

    // Calculations
    callCost = minutes * call_rate;
    preTaxTotal = line_rental + callCost;
    taxAmount = preTaxTotal * tax_rate;
    totalBill = preTaxTotal + taxAmount;

    // Output
    cout << fixed << setprecision(2);
    cout << "\n---------- Mobile Phone Bill ----------" << endl;
    cout << "Line Rental: RM " << line_rental << endl;
    cout << "Call Charges (RM " << call_rate << " per minute): RM " << callCost << endl;
    cout << "Tax (6%): RM " << taxAmount << endl;
    cout << "---------------------------------------" << endl;
    cout << "Total Bill: RM " << totalBill << endl;

    return 0;
}
