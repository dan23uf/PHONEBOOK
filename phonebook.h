#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <bits/stdc++.h>
#include "contact.h"
using namespace std;

struct PB_VECTOR{
    //Show Contact INFO
    //ADD CONTACT MANUALLY
    //EDIT EXISTING CONTACT NAME
    //EDIT EXISTING CONTACT PHONE
    //DELETE INDIVIDUAL CONTACT
    //DELETE ALL CONTACT
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACTS TO FILE
    //SEARCH CONTACT BY NAME


private:
    vector<Contact*> ph_contacts;

#include "contact.h"
using namespace std;

struct PB_VECTOR{


    //Show Contact INFO
    //ADD CONTACT MANUALLY
    //EDIT EXISTING CONTACT NAME
    //EDIT EXISTING CONTACT PHONE
    //DELETE INDIVIDUAL CONTACT
    //DELETE ALL CONTACT
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACTS TO FILE
    //SEARCH CONTACT BY NAME

private:

    vector<Contact*> ph_contacts;


public:

    void show_contact(int x){
        this->ph_contacts[x]->show_contact();
    }

    bool add_manual(Contact* cnt){
        ph_contacts.push_back(cnt);
        return true;
    }

    Contact* search_contact_name(string& str){

        int result = helper_search_contact_name(ph_contacts, 0, ph_contacts.size() - 1, str);
        if(result >= 0){
            return ph_contacts[result];
        }
        return nullptr;

    }

    int helper_search_contact_name(vector<Contact*> contacts, int left, int right, const string& to_find){
        while (left <= right) {
            int m = left + (right - left) / 2;

            if (contacts[m]->get_name() == to_find)
                return m;

            if (contacts[m]->get_name() < to_find)
                left = m + 1;
            else
                right = m - 1;
        }

        return -1;
    }

    bool edit_contact_name(string to_edit, string str){
        auto temp = this->search_contact_name(to_edit);
        if(temp){
            temp->change_name(str);
            return true;
        }
        return false;

    }

    bool edit_contact_phone(string to_edit, string x){
        auto temp = this->search_contact_name(to_edit);
        if(temp){
            temp->change_phone(x);
            return true;
        }
        return false;
    }

    bool delete_contact(string str){
        auto temp = this->search_contact_name(str);
        if(temp){
            delete temp;
            temp = nullptr;
            return true;
        }
        return false;

    }

    void delete_all_contacts(){
        for(auto& pointer : ph_contacts)
        {
            delete pointer;
            pointer = nullptr;

        }
        ph_contacts.erase(std::remove(ph_contacts.begin(), ph_contacts.end(), nullptr), ph_contacts.end());
    }

    void show_all(){

        for(auto pointer: ph_contacts){
            pointer->show_contact();
        }
    }

};


struct PB_TRIE { // TRIE

    //TODO Show Contact INFO*
    //TODO ADD CONTACT MANUALLY*
    //TODO EDIT EXISTING CONTACT*
    //TODO DELETE INDIVIDUAL CONTACT*
    //TODO DELETE ALL CONTACT*
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE
    //TODO SEARCH CONTACT*
    //* = implemented

private:
    struct TrieNode{
        //This map contains a char (alphabet) points to a TrieNode
        unordered_map<char, TrieNode*> node;
        bool last;

        TrieNode() //Constructor
        {
            //initialize nodes
            for(char c = 'a'; c <= 'z'; c++)
                node[c] = nullptr;

            last = false;
        }
    };
    TrieNode* root = nullptr; 

public:
    // returns root
    TrieNode* getRoot() {
        return root;
    }

    // shows all contacts in trie
    void showAllContacts(char name[], TrieNode* current, int h) {
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

    // manually inserts a contact into trie
    void insertContact(string name) {

        if (root == nullptr) { // if the root is null
            root = new TrieNode();
        }

        if (searchContact(name)) {
            cout << "Insert Failed: Contact already exists!" << endl;
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
        cout << name << " added successfully!" << endl;
    }

    // insert multiple contacts into trie
    void insertIntoTries(string contacts[], int n) {
        if (root == nullptr) { // if the root is null
            root = new TrieNode();
        }

        for(int i = 0; i < n; i++)
            insertContact(contacts[i]);
    }

    // edit contact
    void editContact(string oldName, string newName) {
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

    // deletes a specific contact
    void deleteContact(string name) {
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

    // deletes all contacts in trie
    void deleteAllContacts(TrieNode* current) {
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

    // searches for a contact in trie
    bool searchContact(string name) {
        TrieNode* current = root;
        if (current == nullptr) { // no entries
            //cout << "Search unsuccessful: please insert a contact before searching!" << endl;
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

    //TODO VALIDATIONS
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE
};


struct PB_BST{


    //TODO Show Contact INFO
    //TODO ADD CONTACT MANUALLY
    //TODO EDIT EXISTING CONTACT
    //TODO DELETE INDIVIDUAL CONTACT
    //TODO DELETE ALL CONTACT

    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE
    //TODO SEARCH CONTACT

private:
    vector<Contact*> ph_contacts;

public:


};

struct PB_HEAP{


    //TODO Show Contact INFO
    //TODO ADD CONTACT MANUALLY
    //TODO EDIT EXISTING CONTACT
    //TODO DELETE INDIVIDUAL CONTACT
    //TODO DELETE ALL CONTACT

    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE
    //TODO SEARCH CONTACT

private:
    vector<Contact*> ph_contacts;

public:


};

class phonebook {


    //TODO VECTOR WITH BINARY SEARCH IMPLEMENTATION
    PB_VECTOR ph_vector;
    bool using_vector = false;

    
    //TODO TRIE IMPLEMENTATION
    PB_TRIE ph_trie;
    bool using_trie = false;

    //TODO HEAP IMPLEMENTATION
    bool using_heap = false;

    
    //TODO HEAP IMPLEMENTATION

    bool using_heap = false;
    //TODO BST IMPLEMENTATION

    bool using_bst = false;

    //TODO VALIDATIONS

    //TODO CHANGE BETWEEN IMPLEMENTATIONS
public:


    void start(){

        int input;

        cout << "Which implementation to use: \n"
             << "1. Vector\n"
             << "2. Trie\n"
             << "3. Heap\n"
             << "0. EXIT\n" << endl;

        cin >> input;


        switch (input) {
            case 1:
                using_vector = true;
                break;
            case 2:
                using_trie = true;
                break;
            case 3:
                using_heap = true;
                break;
            default:
                cout << "Invalid option" << endl;
         }

        while (input) {
            cout << "What do you want to do: \n"
                 << "1. Search Contact\n"
                 << "2. Add Contact\n"
                 << "3. Delete Contact\n"
                 << "4. Edit Contact\n"
                 << "5. Show All Contact\n"
                 << endl;

            cin >> input;

            string input_string;
            string input_number;

            if(using_vector){

     void start(){

         int input;

         cout << "Which implementation to use: \n"
            << "1. Vector\n"
            << "2. BST\n"
            << "3. Heap\n"
            << "0. EXIT\n" << endl;

         cin >> input;


         switch (input) {
             case 1:
                 using_vector = true;
                 break;
             case 2:
                 using_bst = true;
                 break;
             case 3:
                 using_heap = true;
                 break;
             default:
                 cout << "Invalid option" << endl;
         }

         while (input) {
             cout << "What do you want to do: \n"
                  << "1. Search Contact\n"
                  << "2. Add Contact\n"
                  << "3. Delete Contact\n"
                  << "4. Edit Contact\n"
                  << "5. Show All Contact\n"
                  << endl;

             cin >> input;

             string input_string;
             string input_number;

             if(using_vector){

                 if(input == 1) {
                     cout << "Enter name to search: ";
                     cin >> input_string;
                     cout << "Searching..." << endl;
                     auto temp = ph_vector.search_contact_name(input_string);
                     if (temp) {
                         temp->show_contact();
                     } else
                         cout << "Contact not Found" << endl;
                 }
                 else if(input == 2) {
                     cout << "Enter name to add: ";
                     cin >> input_string;
                     cout << "Enter phone number to add: ";
                     cin >> input_number;

                     auto temp = new Contact(input_string, input_number);
                     bool flag = ph_vector.add_manual(temp);
                     if(flag){
                         cout << "Contact added." << endl;
                     }
                     else
                         cout << "Error" << endl;
                 }
                 else if(input == 3) {

                 }
                 else if(input == 4) {

                 }
                 else if(input == 5) {
                    ph_vector.show_all();
                 }

             }
    
            else if(using_trie){
                //TODO add insert multiple and delete all?
                if(input == 1) { // search
                    cout << "Enter name to search: ";
                    cin >> input_string;
                    cout << "Searching..." << endl;
                     
                    // TODO: display info when searched
                    if (ph_trie.searchContact(input_string))
                        cout << input_string << " found!" << endl;
                    else
                        cout << input_string << " not found!" << endl;
                }
                 
                else if(input == 2) { // insert
                    cout << "Enter name to add: ";
                    cin >> input_string;
                    //TODO: figure out how to add phone number into trie
                    //cout << "Enter phone number to add: ";
                    //cin >> input_number;

                    ph_trie.insertContact(input_string);
                }

                else if(input == 3) { // delete
                    cout << "Enter name to delete: ";
                    cin >> input_string;

                    cout << "Deleting \"" << input_string << "\"" << endl;
                    ph_trie.deleteContact(input_string);
                }

                else if(input == 4) { // edit
                    string oldName, newName;
                    
                    cout << "Enter name to edit: ";
                    cin >> oldName;
                    
                    cout << "Enter new name: ";
                    cin >> newName;

                    cout << "Editing " << oldName << " to " << newName << ": " << endl;
                    ph_trie.editContact(oldName, newName);
                }

                else if(input == 5) { // show all
                    cout << "Displaying all contacts: " << endl;
                    char name[100]; // max 100 characters
                    ph_trie.showAllContacts(name, ph_trie.getRoot(), 0);
                }

             }

             else if(using_bst){

             }

             else if(using_heap){


             }
         }

     }


};


#endif //PHONEBOOK_PHONEBOOK_H
//TODO TRIE IMPLEMENTATION???
//TODO Show Contact INFO
//TODO ADD CONTACT MANUALLY
//TODO EDIT EXISTING CONTACT
//TODO DELETE INDIVIDUAL CONTACT
//TODO DELETE ALL CONTACT
//TODO LOAD CONTACTS FROM FILE or API
//TODO SAVE CONTACT TO FILE
//TODO SEARCH CONTACT
