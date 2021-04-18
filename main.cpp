#include <iostream>
#include "phonebook.h"
#include "contact.h"

int main() {
    cout << "Starting..." << endl;
    phonebook _phonebook = phonebook();

    cout << "testing insert: " << endl;
    string names[] = {"apple", "bob", "cat", "acorn", "pies"};
    _phonebook.insertIntoTries(names, 5);
    _phonebook.insertContact("apple");
    cout << endl;

    cout << "testing search: " << endl;
    if (_phonebook.searchContact("pie"))
        cout << "found" << endl;
    else cout << "not found" << endl;
    if (_phonebook.searchContact("bob"))
        cout << "found" << endl;
    else cout << "not found" << endl;
    cout << endl;

    cout << "testing show all contacts: " << endl;
    char name[100]; // max 100 characters
    _phonebook.showAllContacts(name, _phonebook.getRoot(), 0);
    cout << endl;

    cout << "deleting \"bob\"" << endl;
    _phonebook.deleteContact("bob");
    _phonebook.showAllContacts(name, _phonebook.getRoot(), 0);
    cout << endl;

    cout << "testing edit: " << endl;
    _phonebook.editContact("acorn", "zebra");
    _phonebook.showAllContacts(name, _phonebook.getRoot(), 0);
    cout << endl;

    cout << "testing delete all: " << endl;
    _phonebook.deleteAllContacts(_phonebook.getRoot());
    _phonebook.showAllContacts(name, _phonebook.getRoot(), 0);


    return 0;
}
