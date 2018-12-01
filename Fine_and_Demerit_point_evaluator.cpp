// COMP 218
// Danil Ulmashev
//
// A C++ program that checks through several diffrent cases where a car driver breaks the law while
// using the cell phone. A program provides with a choice of four diffrent locations of where the
// offence could happen following by the information such as number of previous offences, amount of
// experience and type of phone. The program has a basic numerical user input by the end of which
// the result will show the amount to pay, demerit points and decide if the driver may continue
// driving or not.


// Adding libraries
#include <iostream>
#include <iomanip>

using namespace std;


// --------------------------
// Handling print of messages
// --------------------------

// Prints welcome header
void printHeader() {
    cout << "------****------****------****------****------****------\n"
            "      Welcome to the Fine and Demerit Point Evaluator!\n"
            "               based on Crazy Nancy\'s Criteria\n"
            "------****------****------****------****------****------\n"
            << endl;
}

// Prints message to take away the driver's license
void messageTakeAwayLicense(int fine) {
    cout << "--> Officer, write a ticket for " << fine << " take away their driver's license and make arrangemets to have the car towed right away.\n";
}

// Prints message to issue ticket
void messageWriteTicket(int fine, int demPoints) {
    cout << "--> Officer, write a ticket for " << fine << " and inform the driver that they have now "<< demPoints << " demerit points.\n";
}

// Prints message at the end to the ticket handling
void messageGoodJob() {
    cout << endl;
    cout << "Good job officer! Crazy Nancy\'s tells you to keep up the good work!!!!\n" << endl;
}


// ----------------------------
// Handling offcier's questions
// ----------------------------

// Requesting number of previous demirit points
int askPrevDemPoints() {
    int demPointsPrev;
    cout << "Last question officer! How many demerit points did the driver have prior to being stopped? ";
    cin >> demPointsPrev;
    cout << endl;
    return demPointsPrev;
}

// Requesting info if it is the first offence
bool askIfFirstOffence() {
    char answer;
    cout << "Officer, is this the driver\'s 1st offence (answer with y for yes and anything else for no)? ";
    cin >> answer;
    cout << endl;
    return (answer != 'y' && answer != 'Y');
}

// Requesting how old is the driving license
int askHowManyMonthsLicense() {
    int numOfMonths;
    cout << "Officer, how many months has the driver been driving? ";
    cin >> numOfMonths;
    cout << endl;
    return numOfMonths;
}

// Requesting if the phone is an iPhone
bool askIfIPhone() {
    char answer;
    cout << "Officer, is the cellphone in question an iPhone (answer with y for yes and anything else for no)? ";
    cin >> answer;
    cout << endl;
    return (answer != 'y' && answer != 'Y');
}

// -----------------
// Handling offenses
// -----------------

// Handling total demirit points to
void handleTotalDemPoints(int fine, int demPoints) {
    demPoints += askPrevDemPoints();
    if (demPoints >= 12) {
        messageTakeAwayLicense(fine);
    }
    else {
        messageWriteTicket(fine, demPoints);
    }
}

// Handling stop at highway
void handleHighway() {
    int fine = 80;
    int demPoints = 1;
    if (askIfFirstOffence()) {
        demPoints += 1;
    }
    handleTotalDemPoints(fine, demPoints);
}

// Handling stop in the school zone
void handleSchoolZone() {
    int fine = 80;
    int demPoints = 4;
    if (askHowManyMonthsLicense() < 24) {
        messageTakeAwayLicense(fine);
        return;
    }
    handleTotalDemPoints(fine, demPoints);
}

// Handling stop at the stop sign or red light
void handleStop() {
    int fine = 80;
    int demPoints = 1;
    if (askIfIPhone()) {
        fine += 20;
        demPoints += 1;
    }
    handleTotalDemPoints(fine, demPoints);
}

// Handling other stops
void handleOther() {
    int fine = 90;
    int demPoints = 3;
    handleTotalDemPoints(fine, demPoints);
}

// Declaring the function handleOffenseLocation to handle the user input of the offense location.
void handleOffenceLocations() {
    
    // Outputting instructions for the user.
    int choice;
    cout << "Welcome Officer - I need some information before I tell you what the fine and demerit points are.\n"
            "Here are the possible locations\n";
    cout << "        1 - Driver was stopped on the highway\n";
    cout << "        2 - In a school zone\n";
    cout << "        3 - Car is stopped at a Stop sign or traffic light\n";
    cout << "        4 - None of the abone\n";
    cout << "Please enter the digit corresponding to your case: "; 
    cin >> choice;
    cout << endl;
    
    // Switch allowing the user to choose one out of four options.
    switch(choice) {
        case 1: handleHighway(); break;    // Calling function handleHighway.
        case 2: handleSchoolZone(); break; // Calling function handleSchoolZone.
        case 3: handleStop(); break;       // Calling function handleStop.
        case 4: handleOther(); break;      // Calling function handleOther;
        default: cout << "Case " << choice << "does not exist." << endl;
    }  
}

// Main functions
int main() {
    printHeader();
    handleOffenceLocations();
    messageGoodJob();
    return 0;
}

