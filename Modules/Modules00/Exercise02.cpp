#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    vector<vector<string>> PhoneBook;
    vector<vector<string>> BookMark;
    string name, PhoneNumber, NickName;
    vector<string> person(3);

    while (true) {
        cout << "Enter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        string command;
        cin >> command;

        if (command == "ADD") {
            cout << "a. Name: ";
            cin >> name;
            cout << "b. Phone Number(unique): ";
            cin >> PhoneNumber;
            for (int i = 0; i < PhoneBook.size(); i++) {
                if (PhoneNumber == PhoneBook[i][1]) {
                    cout << "Don`t use same phone number!" << endl;
                    cout << "b. Phone Number(unique): ";
                    cin >> PhoneNumber;
                }
                else {
                    continue;
                }
            }

            cout << "c. Nickname: ";
            cin >> NickName;

            person[0] = name;
            person[1] = PhoneNumber;
            person[2] = NickName;

            PhoneBook.push_back(person);
            continue;
        }

        else if (command == "SEARCH") {
            for (int i = 0; i < PhoneBook.size(); i++) {
                cout << i + 1 << ". Name: " << PhoneBook[i][0]<< endl;
            }
            cout << "Choose index display details of the contact (1)" << endl;
            cout << "Bookmark the contact(2)" << endl;
            cout << "Input(-1 to exit): ";
            int n;
            cin >> n;

            if (n == 1) {  // view contact
                while (true) {
                    int num;
                    cout << "Choose the index number of contact (-1 to exit): ";
                    cin >> num;
                    if (num == -1) {
                        break;
                    }
                    else if (num > 0 && num <= PhoneBook.size()+1) {
                        cout << num << ". Name: " << PhoneBook[num - 1][0] << "  PhoneNumber : " << PhoneBook[num - 1][1] << "  NickName : " << PhoneBook[num - 1][2] << endl;
                    }
                    else {
                        cout << "Wrong index" << endl;
                        break;
                    }
                }
            }
            else if (n == 2) {  // add to bookmark
                while (true) {
                    cout << "Enter the index of the contact to bookmark (-1 to exit): ";
                    int n;
                    cin >> n;
                    if (n == -1) break;
                    if (n > 0 && n <= PhoneBook.size()) {
                        BookMark.push_back(PhoneBook[n - 1]);
                    }
                    else {
                        cout << "Wrong index!" << endl;
                        cout << "Enter the index of the contact to bookmark (-1 to exit): ";
                        int n;
                        cin >> n;
                    }
                }
            }
            else if (n == -1) {
                continue;
            }
        }
        else if (command == "REMOVE") {
            cout << "Enter the index of the contact to remove (-1 to exit): ";
            int n;
            cin >> n;
            if (n == -1) continue;
            if (n >= 1 && n <= PhoneBook.size()) {
                for (int i = 0; i < BookMark.size(); i++) {
                    if (PhoneBook[n - 1][1] == BookMark[i][1]) {
                        BookMark.erase(BookMark.begin() + i);
                        break;
                    }
                }
                PhoneBook.erase(PhoneBook.begin() + n - 1);
            }
            else {
                cout << "Wrong index!" << endl;
                break;
            }
        }

        else if (command == "EXIT") {
            break;
        }

        else if (command == "BOOKMARK") {
            for (int i = 0; i < BookMark.size(); i++) {
                cout << i + 1 << ". Name: " << BookMark[i][0] << ", Phone: " << BookMark[i][1] << ", Nickname: " << BookMark[i][2] << endl;
            }
        }

        else {
            cout << "Enter command (ADD, SEARCH, REMOVE, EXIT)" << endl;
            continue;
        }
    }

    return 0;
}