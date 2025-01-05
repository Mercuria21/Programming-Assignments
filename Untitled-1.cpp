#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

const int MAX_COMPLAINTS = 100;

char complaintTypes[MAX_COMPLAINTS][20];
char complaintTitles[MAX_COMPLAINTS][50];
char complaintDetails[MAX_COMPLAINTS][200];
char complaintLocations[MAX_COMPLAINTS][50];
char complaintDates[MAX_COMPLAINTS][20];
char complaintStatuses[MAX_COMPLAINTS][10];
int complaintTicketIDs[MAX_COMPLAINTS];
int complaintCount = 0;

// Function prototypes
void mainmenu(void);
void fname(char[]);
void lname(char[]);
void npassword(char[]);
void cpassword(char[]);
void idtype(char[]);
void phonenum(char[]);
void email(char[]);
void identification(char[], char[], char[]);
void registerUser(void);
void login (void);
void resetPassword(void);
void submitComplaints(void);
void viewComplaints(void);

void getCurrentDate(char[]);
void generateTicketID(int&);

char registeredUserID[30];
char registeredPassword[30];

int main(void) {
   int choice;
   do {
        mainmenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character after cin
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                submitComplaints();
                break;
            case 5:
                viewComplaints();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0); // Assuming 0 is the exit option
    return 0;
}

void mainmenu(void) {
    cout << "Main Menu: " << '\n'
         << "Please enter the number for the corresponding task needed." << '\n'
         << "1. Register New Account" << '\n'
         << "2. Log in" << '\n'
         << "3. Password Reset" << '\n'
         << "4. Write complaint/s" << '\n'
         << "5. View complaint/s" << '\n'
         << "0. Exit\n";
}

void fname(char firstn[]) {
    cout << "Enter first name: ";
    cin.getline(firstn, 30);

    firstn[0]=firstn[0]-32;
    firstn[1]=firstn[1]-32;
}

void lname(char lastn[]) {
    cout << "Enter Last name: ";
    cin.getline(lastn, 30);

}

void npassword(char newpass[]) {
    cout << "Enter New Password: ";
    cin.getline(newpass, 30);
}

void cpassword(char confirm[]) {
    cout << "Enter again to confirm Password: ";
    cin.getline(confirm, 30);
}

void idtype(char idty[]) {
    int opt;

    cout << "List of ID type:" << '\n'
         << "\n1. Identification card (ID)" << '\n'
         << "2. Passport" << '\n'
         << "3. Company Number" << '\n'
         << "\nEnter number to corresponding ID type: ";
    cin >> opt;
    cin.ignore(); // Ignore newline character after cin

    switch (opt) {
        case 1:
            cout << "\nEnter your IC: ";
            cin.getline(idty, 13);
            break;
        case 2:
            cout << "\nEnter your Passport: ";
            cin.getline(idty, 10);
            break;
        case 3:
            cout << "\nEnter your Company Number: ";
            cin.getline(idty, 12);
            break;
        default:
            cout << "\nInvalid Input";
            break;
    }
}
void phonenum(char pnumber[]) {
    cout << "Enter your Phone Number: ";
    cin.getline(pnumber, 12);
}

void email(char elecmail[]) {
    cout << "Enter your Email: ";
    cin.getline(elecmail, 30);
}
void identification(char firstname[], char lastname[], char identity[]) {
    char user_id[30]; // Array to hold the user ID
    strncpy(user_id, firstname, 2);
    user_id[2] = '\0';

    strncat(user_id, lastname, 3);

    strncat(user_id, identity + strlen(identity) - 6, 6);
    cout << "User ID: " << user_id << endl;

    strncpy(registeredUserID, user_id, sizeof(registeredUserID) - 1);
    registeredUserID[sizeof(registeredUserID) - 1] = '\0';
}
void registerUser(void) {
    char firstn[30], lastn[30], newpass[30], confirm[30], idty[30], pnumber[12], elecmail[30];
    fname(firstn);
    lname(lastn);
    npassword(newpass);
    cpassword(confirm);
    idtype(idty);
    phonenum(pnumber);
    email(elecmail);
    identification(firstn, lastn, idty);
    strncpy(registeredPassword, newpass, sizeof(registeredPassword) - 1);
    registeredPassword[sizeof(registeredPassword) - 1] = '\0';
    cout << "Registration Successful!\n";
}
void login(void) {
    char user_id[30], password[30];
    cout << "Enter User ID: ";
    cin.getline(user_id, 30);
    cout << "Enter Password: ";
    cin.getline(password, 30);

    if (strcmp(user_id, registeredUserID) == 0 && strcmp(password, registeredPassword) == 0) {
            cout << "Login Successful!\n";
    }
    else {
      cout << "Invalid User ID or Password.\n";
    }
}
void resetPassword(void) {
    char user_id[30], newpass[30], confirm[30];
    cout << "Enter User ID: ";
    cin.getline(user_id, 30);

    if (strcmp(user_id, registeredUserID) == 0) {
            cout << "Enter new password: ";
            cin.getline(newpass, 30);
            cout << "Enter again to confirm new password: ";
            cin.getline(confirm, 30);

            if (strcmp(newpass, confirm) == 0) {
                    strncpy(registeredPassword, newpass, sizeof(registeredPassword) - 1);
                    registeredPassword[sizeof(registeredPassword) - 1] = '\0';
                    cout << "Password reset successful!\n";
                    }
            else {
                    cout << "Passwords do not match. Try again.\n";
            }
    }
    else {
       cout << "Invalid User ID.\n";
    }
}
void submitComplaints(void) {
    int numberOfComplaints;
    cout << "Enter number of complaints to submit: ";
    cin >> numberOfComplaints;
    cin.ignore(); // Ignore newline character after cin

    for (int i = 0; i < numberOfComplaints && complaintCount < MAX_COMPLAINTS; i++) {
          cout << "Complaint " << (i + 1) << ":\n";
          cout << "Enter Type (Complaints, Suggestions, Appreciation, Requests, Questions): ";
          cin.getline(complaintTypes[complaintCount], 20);
          cout << "Enter Title: ";
          cin.getline(complaintTitles[complaintCount], 50);
          cout << "Enter Details: ";
          cin.getline(complaintDetails[complaintCount], 200);
          cout << "Enter Location (e.g., Johor, Kedah, Kelantan, Kuala Lumpur, etc.): ";
          cin.getline(complaintLocations[complaintCount], 50);

          getCurrentDate(complaintDates[complaintCount]);
          strcpy(complaintStatuses[complaintCount], "New");
          generateTicketID(complaintTicketIDs[complaintCount]);
          complaintCount++;
    }
}
void viewComplaints(void) {
    cout << "List of Complaints:\n";
    cout << "Type\tTitle\tLocation\tDate\t\tStatus\tTicket ID\n";
    for (int i = 0; i < complaintCount; i++) {
            cout << complaintTypes[i] << '\t'
                 << complaintTitles[i] << '\t'
                 << complaintLocations[i] << '\t'
                 << complaintDates[i] << '\t'
                 << complaintStatuses[i] << '\t'
                 << complaintTicketIDs[i] << '\n';
    }
}
void getCurrentDate(char date[]) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(date, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
}
void generateTicketID(int &ticketID) {
    static int lastTicketID = 0;
    ticketID = ++lastTicketID;
}
