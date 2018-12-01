// COMP 218
// Danil Ulmashev
//
// A C++ program that that computes arithmetic sequence of of multi digit numbers
// added together. The program will first do the addition in ones-colums. Once the
// program is done computing the sum of first two digit it will move on to the next
// digit (the ten's colum) with the additional carry number in mind if the sum is
// larger than 9.
// the program uses several loops in order to check through each digit and perform
// the required calculation. Initially this program is set to compute maximum of
// 3 digit numbers, however, these parameters are can be changed by editing
// variables which are place holders for maximum number (maxNum) and maximum digit (maxDigit).
//
//
// Adding libraries.
#include <iostream>
#include <iomanip>


using namespace std;


// Declaring variables for input numbers and their sizes.
int num1, num2;
int maxNum = 999;
int maxDigits = 3;


// Declaring function printHeader to display the Welcome message in the console
// at the beginning of the program.
void printHeader() {
    // Outputting the Welcome message.
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
    cout << "   Welcome to Nancy's Addition Tutorial Program!" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// Declaring function swapNumbers to swap numbers when needed.
void swapNumbers() {
    int tempNum;
    tempNum = num1;
    num1 = num2;
    num2 = tempNum;
} 

// Declaring function inputNumber for the user to type in two numbers in the console.
void inputNumber() {
    int sum;
    while (true) {
        cin >> num1 >> num2;
        // Checks if the firt number is bigger than the second number and if conditions are met they will change places.
        if (num1 < num2) {
            swapNumbers();
        }
        // Checks if the user entered a number which contains more digits than requested.
        if (num1 > maxNum || num2 > maxNum) {
            cout << "The number you've entered has more than " << maxDigits << " digits. Enter again: \n";
        }
        else {
            // Checks if all conditions are met then the program will output the message bellow and exit the loop.
            cout << "You requested the following operation: \n\n";
            cout << setw(6) << " num1:" << "    " << setw(maxDigits) << num1 << endl;
            cout << setw(6) << " num2:" << "   +" << setw(maxDigits) << num2 << endl;
            cout << setw(13) << "-------";
            cout << endl;
            break;
        }
    }
}

// Declaring function addition which will go through each number individually (from ones-column to then tens-colums and so forth)
// and add them together while checking if the sum was a number larger than 9 and pasing the carry to the next column.
void addition() {
    // Requirments for the user input.
    cout << "Enter two numbers with at most " << maxDigits << "-digits each and press enter: ";
    // Calling function inputNumber.
    inputNumber();
    // Declaring internal variables to store values for the answer and the carry.
    // Variables are declared outside the loop to assure that their value does not change after each iteration.
    // Variable answer is an array to hold digits of a number individually.
    int answer[maxDigits];
    int prevCarry = 0;
    // For loop checks through each digit and performs a mathematical computation to move form one digit-colums to the next one
    // starting at ones-column and then checking if the sum has a carry for the column in it.
    for (int i = 1, n = 0; n < maxDigits; i *= 10, n++) {
        // Algorithm that moves the calculation of two numbers from ones=column to the next one.
        int digit1 = (num1 % (i * 10)) / i;
        int digit2 = (num2 % (i * 10)) / i;
        // Computes the sum of digits in a column with the carry of the previous calculation.
        int sum = digit1 + digit2 + prevCarry;
        // Computes the remainder of a sum of two numbers.
        int rem = sum % 10;
        // Computes the carry of the sum of two numbers.
        int carry = sum / 10;
        // Checks and calculates the the sum of digits in each column and addds the carry to the next one of exists.
        if (digit1 != 0 || digit2 != 0 || prevCarry != 0) {
            // Indicates the sequence of steps.
            cout << "Step " << n + 1 << ": addition" << endl;
            // Outputs the message only for the first iteration.
            if (n < 1) {
                cout << " last digit of each number" << endl;
            }
            // Checks if carry is bigger than zero and adds it to the addition of the next colums of digits.
            if (prevCarry > 0) {
                cout << " The carry from previous addition plus the next digit of each number is "  << endl;
                cout << prevCarry << " +";
            }
            // Addition of two digits.
            cout << " " << digit1 << " + " << digit2;
            // Outputting the resluts of additions.
            if (n < maxDigits - 1) {
                cout << " = " << sum << " so answer is " << rem << " with a carry " << carry << endl << endl;
            }
            else {
                cout << " = " << sum << " so answer is " << sum << endl << endl;
            }
        }
        
        // if not the last digit, then setting the remainder, otherwise setting the sum.
        answer[n] = (n < maxDigits - 1) ? rem : sum;
        
        // Saving the carry value for the next iteration of the loop.
        prevCarry = carry;
    }
    // Outputes the final answer.
    cout << "Final answer:" << endl;
    cout << setw(6) << " num1:" << "    " << setw(maxDigits) << num1 << endl;
    cout << setw(6) << " num2:" << "   +" << setw(maxDigits) << num2 << endl;
    cout << setw(13) << "-------" << endl;
    cout << " Answer: ";
    // Removes unnecessary zero digits in the answer.
    bool shouldPrint = false;
    for (int i = maxDigits - 1; i >= 0; i--) {
        if (answer[i] != 0 || shouldPrint) {
            cout << answer[i];
            shouldPrint = true;
        }
    }
    
    // Checking if the answer in the arithmetic addition was correct and comparing to the simple addition of two numbers.
    cout << endl << " Check:  " << num1 + num2 << endl;
    cout << endl << endl << endl;
}


// Main fucntion.
int main() {
    printHeader();
    char doAgain;
    // Checking if user would likes to try the addition program again.
    do {
        // Calling function addition.
        addition();
        cout << "Do you want to try aonther one? (y or Y to repeat) ";
        cin >> doAgain;
        cout << endl << endl << endl;
        // Input y or Y to try again.
    } while(doAgain == 'y' || doAgain == 'Y');
    return 0;
}

