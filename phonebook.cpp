#include "phonebook.h"
#include "contact.h"

// displays all contacts in the trie in alphabetical order
void phonebook::showAllContacts(char name[], TrieNode* current, int h) {
    if (current == nullptr) // if null
        return;

    if (current->last) { // if last letter, print entire name
        cout << "Name: ";
        for (int i = 0; i < h; i++)
            cout << name[i]; // prints each letter
        cout << endl;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (current->node[c] != nullptr) { // if there is an entry, add that level and go to next letter
            name[h] = c;
            showAllContacts(name, current->node[c], h + 1);
        }
    }
}

// insert a contact into trie
void phonebook::insertContact(string name){
    if (root == nullptr) { // if the root is null
        root = new TrieNode();
    }

    if (searchContact(name)) {
        cout << "contact already exists!" << endl;
        return;
    }
    TrieNode* newNode;
    TrieNode* current = root;

    for(int i = 0; i < name.length(); i++) {
        if(current->node[name[i]] == nullptr) { // if node does not exist, create a new one
            newNode = new TrieNode();
            current->node[name[i]] = newNode;
        }
        current = current->node[name[i]]; // go to next
    }
    current->last = true; // very last letter of contact name
}

// insert multiple contacts
void phonebook::insertIntoTries(string contacts[], int n){
    if (root == nullptr) { // if the root is null
        root = new TrieNode();
    }

    for(int i = 0; i < n; i++)
        insertContact(contacts[i]);
}

// edit a contact
void phonebook::editContact(string oldName, string newName) {
    // delete it and create a new one
    if (searchContact(oldName)) // old name exists
        deleteContact(oldName);
    else {
        cout << "the old name does not exist!" << endl;
        return;
    }
    if (!searchContact(newName)) { // new name does not exist
        insertContact(newName);
    }
    else {
        cout << "the new name already exists!" << endl;
        return;
    }
}

// delete contact
void phonebook::deleteContact(string name) {
    TrieNode* current = root;
    TrieNode* nodeToDelete = root;
    if (current == nullptr) { // no entries
        cout << "please insert a contact before deleting!" << endl;
        return;
    }

    if (!searchContact(name)) { // cannot find contact
        cout << "contact does not exist!" << endl;
        return;
    }

    for(int i = 0; i < name.length(); i++) {
        if (current->node[name[i]] == nullptr) // no children
            return;
        if (current->last) // there is a preexisting word
            nodeToDelete = current->node[name[i]];
        current = current->node[name[i]]; // go to next
    }
    if (!current->last)
        return;

    if (current->node.empty()) { // has no children
        nodeToDelete = nullptr;
    }
    else // has children
        current->last = false;

}

// delete all contacts
void phonebook::deleteAllContacts(TrieNode* current) {
    //TrieNode* current = root;
    if (current == nullptr) // if null
        return;

    for (char c = 'a'; c <= 'z'; c++) {
        if (current->node[c] != nullptr) { // if there is an entry, add that level and go to next letter
            deleteAllContacts(current->node[c]);
            current->last = false;
            current->node[c] = nullptr;
        }
    }
}

// search contact
bool phonebook::searchContact(string name) {
    TrieNode* current = root;
    if (current == nullptr) { // no entries
        cout << "please insert a contact before searching!" << endl;
        return false;
    }

    for (int i = 0; i < name.length(); i++) {
        if (current->node[name[i]] == nullptr)
            return false;
        current = current->node[name[i]]; // go to next
    }

    if (current->last) // if it is currently the last letter
        return true;
    return false;
}