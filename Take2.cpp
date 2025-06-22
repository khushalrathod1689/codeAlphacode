#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isUserRegistered(const string& username) {
    ifstream userFile(username + ".txt");
    return userFile.good();
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    if (isUserRegistered(username)) {
        cout << "Error: Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream userFile(username + ".txt");
    userFile << username << endl << password;
    userFile.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;

    if (!isUserRegistered(username)) {
        cout << "Error: Username not found. Please register first.\n";
        return false;
    }

    cout << "Enter password: ";
    cin >> password;

    ifstream userFile(username + ".txt");
    getline(userFile, storedUsername);
    getline(userFile, storedPassword);
    userFile.close();

    if (storedUsername == username && storedPassword == password) {
        cout << "Login successful! Welcome, " << username << "!\n";
        return true;
    } else {
        cout << "Error: Incorrect password. Try again.\n";
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid option. Exiting program.\n";
    }

    return 0;
}