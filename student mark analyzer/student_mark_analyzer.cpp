#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

void inputData(int marks[], string names[], int rollNos[], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter roll number for student " << i + 1 << ": ";
        cin >> rollNos[i];
        cout << "Enter name for student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, names[i]);
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

void displayData(int marks[], string names[], int rollNos[], int n) {
    cout << "\nRollNo\tName\tMarks\n";
    for (int i = 0; i < n; i++) {
        cout << rollNos[i] << "\t" << names[i] << "\t" << marks[i] << endl;
    }
}

void calculateStats(int marks[], int n) {
    int sum = 0, max = marks[0], min = marks[0];
    for (int i = 0; i < n; i++) {
        sum += marks[i];
        if (marks[i] > max) max = marks[i];
        if (marks[i] < min) min = marks[i];
    }
    double average = (double)sum / n;
    cout << "Average: " << average << ", Max: " << max << ", Min: " << min << endl;
}

void bubbleSort(int marks[], string names[], int rollNos[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && marks[j] > marks[j + 1]) || (!ascending && marks[j] < marks[j + 1])) {
                swap(marks[j], marks[j + 1]);
                swap(names[j], names[j + 1]);
                swap(rollNos[j], rollNos[j + 1]);
            }
        }
    }
    cout << "Marks sorted successfully.\n";
}

void searchByRoll(int rollNos[], string names[], int marks[], int n, int roll) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (rollNos[i] == roll) {
            cout << "Student Found: Roll No: " << rollNos[i] << ", Name: " << names[i] 
                 << ", Marks: " << marks[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Student with Roll Number " << roll << " not found." << endl;
}

void searchByName(string names[], int marks[], int rollNos[], int n, string searchName) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (names[i] == searchName) {
            cout << "Student Found: Roll No: " << rollNos[i] << ", Name: " << names[i] 
                 << ", Marks: " << marks[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Student with name '" << searchName << "' not found." << endl;
}

int main() {
    int marks[MAX], rollNos[MAX], n = 0, choice;
    string names[MAX];

    while (true) {
        cout << "\n--- Student Marks Analyzer ---\n";
        cout << "1. Input Student Data\n";
        cout << "2. Display All Data\n";
        cout << "3. Calculate Average, Max, Min\n";
        cout << "4. Sort Marks\n";
        cout << "5. Search by Roll Number\n";
        cout << "6. Search by Name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            inputData(marks, names, rollNos, n);
        } 
        else if (choice == 2) {
            if (n > 0) displayData(marks, names, rollNos, n);
            else cout << "Please input data first.\n";
        } 
        else if (choice == 3) {
            if (n > 0) calculateStats(marks, n);
            else cout << "Please input data first.\n";
        } 
        else if (choice == 4) {
            if (n > 0) {
                int order;
                cout << "Enter 1 for ascending, 0 for descending: ";
                cin >> order;
                bubbleSort(marks, names, rollNos, n, order == 1);
                displayData(marks, names, rollNos, n);
            } else cout << "Please input data first.\n";
        } 
        else if (choice == 5) {
            if (n > 0) {
                int roll;
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                searchByRoll(rollNos, names, marks, n, roll);
            } else cout << "Please input data first.\n";
        } 
        else if (choice == 6) {
            if (n > 0) {
                string searchName;
                cout << "Enter Name to search: ";
                cin.ignore();
                getline(cin, searchName);
                searchByName(names, marks, rollNos, n, searchName);
            } else cout << "Please input data first.\n";
        } 
        else if (choice == 7) {
            cout << "Exiting Student Marks Analyzer.\n";
            break;
        } 
        else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
