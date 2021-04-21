#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <bits/stdc++.h>
#include "contact.h"
using namespace std;

struct PB_VECTOR {

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
        sort(ph_contacts.begin(),ph_contacts.end(), ContactComparator());
        int result = helper_search_contact_name(ph_contacts, 0, ph_contacts.size() - 1, str);
        if(result >= 0){
            return ph_contacts[result];
        }
        return nullptr;

    }

    int search_contact_name_int(string& str){
        sort(ph_contacts.begin(),ph_contacts.end(), ContactComparator());
        int result = helper_search_contact_name(ph_contacts, 0, ph_contacts.size() - 1, str);
        return result;
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
        string empty = "-1";
        auto temp = this->search_contact_name_int(str);
        if(temp >= 0){
            delete ph_contacts[temp];
            ph_contacts[temp]->change_name(empty);
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

    void load_contacts(string& file_name){
        ifstream in_file(file_name);

        string line;
        string headers;

        getline(in_file, headers);

        string name;
        string phone_number;

        if(in_file.is_open()){
            while (getline(in_file, line)){
                istringstream stream(line);

                getline(stream,name,',');
                getline(stream,phone_number);

                auto temp = new Contact(name, phone_number);
                this->add_manual(temp);
            }
        }
        else
            cout<< "File at: " << file_name << " could not be opened" << endl;
    }

};


struct PB_TRIE {

private:
    struct TrieNode{
        //This map contains a char (alphabet) points to a TrieNode
        unordered_map<char, TrieNode*> node;
        bool last;
        Contact* contact;

        TrieNode() //Constructor
        {
            //initialize nodes
            for(char c = 'a'; c <= 'z'; c++)
                node[c] = nullptr;
            node[' '] = nullptr;
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
    void showAllContacts(TrieNode* current, vector<Contact*> &res) {
        if (current == nullptr) // if null
            return;
        if (current->last) { // if last letter, print entire name
            res.push_back(current->contact);
        }
        for (int i = 0; i < 26; i++) {
            if (current->node[(char)i + 65] != nullptr) { // if there is an entry, add that level and go to next letter
                showAllContacts(current->node[(char)i + 65], res);
            }
            if (current->node[(char)i + 97] != nullptr) {
                showAllContacts(current->node[(char)i + 97], res);
            }
            if (current->node[(char)i + 32] != nullptr) {
                showAllContacts(current->node[(char)i + 32], res);
            }
        }
    }

    // manually inserts a contact into trie
    void insertContact(string name, string number) {

        if (root == nullptr) { // if the root is null
            root = new TrieNode();
        }

        if (searchContact(name) != nullptr) {
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
        Contact* newContact = new Contact();
        newContact->change_name(name);
        newContact->change_phone(number);
        current->contact = newContact;
    }

    // insert multiple contacts into trie
    void insertIntoTries(Contact* contacts[], int n) {
        if (root == nullptr) { // if the root is null
            root = new TrieNode();
        }

        for(int i = 0; i < n; i++)
            insertContact(contacts[i]->get_name(), contacts[i]->get_phone());
    }

    // edit contact's name
    void editContact(string oldName, string newName) {
        // delete it and create a new one
        if (searchContact(oldName)) { // old name exists
            if (!searchContact(newName)) { // new name does not exist, so we can edit
                searchContact(oldName)->change_name(newName);
                string number = searchContact(oldName)->get_phone();
                deleteContact(oldName);
                insertContact(newName, number);
            }
            else { // cant edit
                cout << "The new name \"" << newName << "\" already exists!" << endl;
                return;
            }
        }
        else {
            cout << "The old name \"" << oldName << "\" does not exist!" << endl;
            return;
        }
    }

    // edit contact's phone number
    void editContactNum(string contact, string newNum) {
        if (searchContact(contact)) // contact exists
                searchContact(contact)->change_phone(newNum);
        else {
            cout << "The old name \"" << contact << "\" does not exist!" << endl;
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

        if (searchContact(name) == nullptr) { // cannot find contact
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
        else { // has children
            current->last = false;
            delete current->contact;
            current->contact = nullptr;
        }
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

    // searches for a SINGLE contact in trie
    Contact* searchContact(string name) {
        TrieNode* current = root;
        if (current == nullptr)  // no entries
            return nullptr;

        for (int i = 0; i < name.length(); i++) {
            if (current->node[name[i]] == nullptr)
                return nullptr;
            current = current->node[name[i]]; // go to next
        }

        if (current->last)  // if it is currently the last letter and has no children
            return current->contact;
        else
            return nullptr;
    }

    // returns ALL contacts with searched prefix
    vector<Contact*> searchContactAutocomplete(string name) {
        vector<Contact*> results;
        TrieNode* current = root;
        if (current == nullptr) { // no entries
            return results; //empty
        }

        for (int i = 0; i < name.length(); i++) {
            if (current->node[name[i]] == nullptr)
                return results; //empty
            current = current->node[name[i]]; // go to next
        }

        if (current->last && current->node.empty()) { // if it is currently the last letter and has no children
            results.push_back(current->contact);
            return results;
        }
        //return current->contact;
        if (!current->node.empty()) {
            vector<Contact*> results;
            showAllContacts(current, results);
            return results;
        }
        else {
            return results; // empty
        }
    }

    // load contacts from csv file
    void load_contacts(string& file_name){
        ifstream in_file(file_name);

        string line;
        string headers;

        getline(in_file, headers);

        string name;
        string phone_number;

        if(in_file.is_open()){
            while (getline(in_file, line)){
                istringstream stream(line);

                getline(stream,name,',');
                getline(stream,phone_number);

                this->insertContact(name, phone_number);
            }
        }
        else
            cout<< "File at: " << file_name << " could not be opened" << endl;
    }
};



struct PB_MAP{

private:
    unordered_map<string, Contact*> ph_contacts;


public:

    //Show Contact INFO
    void show_all_contacts(){
        for(auto elem: ph_contacts){
            elem.second->show_contact();
        }
    }
    //ADD CONTACT MANUALLY
    bool add_contact_manual(Contact* cnt){
        ph_contacts[cnt->get_name()] = cnt;
    }
    //EDIT EXISTING CONTACT
    bool edit_contact_name(string old_name, string new_name){
        if(this->search_contact(old_name)){
            ph_contacts[old_name]->change_name(new_name);
            ph_contacts[new_name] = ph_contacts[old_name];
            ph_contacts.erase(old_name);
            return true;
        }
        else
            return false;
    }
    bool edit_contact_number(string name, string new_phone){
        if(this->search_contact(name)){
            ph_contacts[name]->change_phone(new_phone);
            return true;
        }
        else
            return false;
    }

    // DELETE INDIVIDUAL CONTACT
    bool delete_contact(string name){
        auto found = this->search_contact(name);
        if(found){
            delete found;
            ph_contacts[name] = nullptr;
            return true;
        }
        else
            return false;
    }
    // DELETE ALL CONTACT
    bool delete_all_contact(){
        for(auto elem: ph_contacts){
            this->delete_contact(elem.second->get_name());

        }
        return true;
    }

    //LOAD CONTACTS FROM FILE or API
    void load_contacts(string& file_name){
        ifstream in_file(file_name);

        string line;
        string headers;

        getline(in_file, headers);

        string name;
        string phone_number;

        if(in_file.is_open()){
            while (getline(in_file, line)){
                istringstream stream(line);

                getline(stream,name,',');
                getline(stream,phone_number);

                auto temp = new Contact(name, phone_number);
                this->add_contact_manual(temp);
            }
        }
        else
            cout<< "File at: " << file_name << " could not be opened" << endl;
    }

    //SEARCH CONTACT
    Contact* search_contact(string name){
        auto found = ph_contacts.find(name);
        if(found != ph_contacts.end())
            return found->second;
        else
            return nullptr;
    }

};


class phonebook {

    PB_VECTOR ph_vector;
    bool using_vector = false;


    PB_TRIE ph_trie;
    bool using_trie = false;

    PB_MAP ph_map;
    bool using_map = false;

public:

    void center(string str, int num_cols){
        int padding_left = (num_cols/2) - (str.size() / 2);

        for(int i = 0; i < padding_left; i++) cout<< ' ';

        cout<<str;
    }

     void start(){

         int input;
         vector<string> menu1 = {
                 "----------------------------------------------",
                 "|          CHOOSE AN IMPLEMENTATION           |",
                 "|          1 - VECTOR                         |",
                 "|          2 - TRIE                           |",
                 "|          3 - MAP                            |",
                 "|                                             |",
                 "|                                             |",
                 "-----------------------------------------------",
         };

         vector<string> menu2 = {
                 "----------------------------------------------",
                 "|                  PHONEBOOK                  |",
                 "|          1 - SEARCH CONTACT                 |",
                 "|          2 - ADD CONTACT                    |",
                 "|          3 - DELETE CONTACT                 |",
                 "|          4 - EDIT CONTACT NAME              |",
                 "|          5 - EDIT CONTACT PHONE             |",
                 "|          6 - SHOW ALL                       |",
                 "|          7 - CHANGE IMPLEMENTATIONS         |",
                 "|          0 - EXIT                           |",
                 "-----------------------------------------------",
         };
         int num_cols = 100;

         cout<<endl;
         for(int i = 0; i < num_cols; i++) cout << ' ';
         cout<<endl;

         for(int i = 0; i < menu1.size();i++){
             center(menu1[i],num_cols);
             cout<<endl;
         }

         cout<<endl;
         for(int i = 0; i < num_cols; i++) cout<<' ';
         cout<<endl;
       
         cin >> input;

         string data_file = "data.csv";

        switch (input) {
            case 1:
                using_vector = true;
                ph_vector.load_contacts(data_file);
                break;
            case 2: {
                using_trie = true;
                //string data_file = "data.csv";
                cout << "Loading contacts from file..." << endl;
                ph_trie.load_contacts(data_file);
                cout << "Successfully loaded.\n" << endl;
                break;
            }
            case 3:
                using_map = true;
                ph_map.load_contacts(data_file);
                break;
            default:
                cout << "Invalid option" << endl;
                start();
        }


         while (input) {
             cout<<endl;
             for(int i = 0; i < num_cols; i++) cout << ' ';
             cout<<endl;

             for(int i = 0; i < menu2.size();i++){
                 center(menu2[i],num_cols);
                 cout<<endl;
             }

             cout<<endl;
             for(int i = 0; i < num_cols; i++) cout<<' ';
             cout<<endl;
             cin >> input;

             string input_string;
             string input_number;

             
             if(using_vector) {


                 if (input == 1) {
                     cout << "ENTER NAME TO SEARCH: ";
                     cin.ignore();
                     getline(cin, input_string);
                     cout << "Searching..." << endl;
                     auto temp = ph_vector.search_contact_name(input_string);
                     if (temp) {
                         temp->show_contact();
                     } else
                         cout << "Contact not Found" << endl;
                 } else if (input == 2) {
                     cout << "ENTER NAME TO ADD: ";
                     cin >> input_string;
                     cout << "ENTER PHONE TO ADD: ";
                     cin >> input_number;

                     auto temp = new Contact(input_string, input_number);
                     bool flag = ph_vector.add_manual(temp);
                     if (flag) {
                         cout << "Contact added." << endl;
                     } else
                         cout << "Error" << endl;
                 } else if (input == 3) {
                     cout << "ENTER CONTACT NAME TO BE DELETED: ";
                     cin >> input_string;
                     ph_vector.delete_contact(input_string);
                 } else if (input == 4) {
                     cout << "ENTER OLD CONTACT NAME: ";
                     cin >> input_string;
                     string old_name = input_string;
                     cout << "ENTER NEW CONTACT NAME: ";
                     cin >> input_string;
                     cout << endl;
                     ph_vector.edit_contact_name(old_name, input_string);
                 } else if (input == 5) {
                     cout << "ENTER CONTACT NAME: ";
                     cin >> input_string;
                     string old_name = input_string;
                     cout << "ENTER NEW PHONE: ";
                     cin >> input_number;
                     cout << endl;
                     ph_vector.edit_contact_phone(old_name, input_number);
                 } else if (input == 6) {
                     ph_vector.show_all();
                 } else if (input == 7) {
                     using_vector = false;
                     start();
                 }
             }
             else if(using_trie){

                if(input == 1) {
                    cout << "ENTER NAME TO SERACH: ";
                    cin.ignore();
                    getline(cin,input_string);
                    cout << "Searching..." << endl;

                    vector<Contact*> results = ph_trie.searchContactAutocomplete(input_string);
                    if (!results.empty()) {
                        for (auto i : results) {
                            i->show_contact();
                        }
                        cout << endl;
                    }

                    else
                        cout << input_string << " not found!" << endl;
                }

                else if(input == 2) { // insert
                    cout << "ENTER NAME TO ADD: ";
                    cin.ignore();
                    getline(cin, input_string, '\n');
                    if (ph_trie.searchContact(input_string) != nullptr)
                        cout << "Error: contact already exists!" << endl;
                    else {
                        cout << "ENTER PHONE NUMBER TO ADD: ";
                        cin >> input_number;

                        ph_trie.insertContact(input_string, input_number);
                    }
                }

                else if(input == 3) { // delete
                    cout << "ENTER NAME TO DELETE: ";
                    cin.ignore();
                    getline(cin, input_string);

                    cout << "Deleting \"" << input_string << "\"" << endl;
                    ph_trie.deleteContact(input_string);
                }

                else if(input == 4) { // edit
                    string oldName, newName;

                    cout << "ENTER NAME TO EDIT: ";
                    cin.ignore();
                    getline(cin, oldName);

                    cout << "ENTER NEW NAME: ";
                    getline(cin, newName);

                    cout << "Changing " << oldName << " to " << newName << ": " << endl;
                    ph_trie.editContact(oldName, newName);
                }

                else if(input == 5) { // edit
                    string contact, newNum;

                    cout << "ENTER CONTACT TO EDIT: ";
                    cin.ignore();
                    getline(cin, contact);

                    cout << "ENTER NEW PHONE: ";
                    getline(cin, newNum);

                    cout << "Changed " << contact << "'s phone number to " << newNum << endl;
                    ph_trie.editContactNum(contact, newNum);
                }

                else if(input == 6) { // show all
                    cout << "Displaying all contacts: " << endl;
                    vector<Contact*> results;
                    ph_trie.showAllContacts(ph_trie.getRoot(),results);

                    for (auto i : results)
                        i->show_contact();
                    cout << endl;
                }

                else if (input == 7) {
                    using_trie = false;
                    start();
                }

            }
             else if(using_map) {

                 if (input == 1) {
                     cout << "ENTER NAME TO SEARCH: ";
                     cin.ignore();
                     getline(cin,input_string);
                     cout << "Searching..." << endl;
                     auto temp = ph_map.search_contact(input_string);
                     if (temp) {
                         temp->show_contact();
                     } else
                         cout << "Contact not Found" << endl;
                 } else if (input == 2) {
                     cout << "ENTER NAME TO ADD: ";
                     cin.ignore();
                     getline(cin,input_string);
                     cout << "ENTER PHONE NUMBER TO ADD: ";
                     cin.ignore();
                     getline(cin,input_number);

                     auto temp = new Contact(input_string, input_number);
                     bool flag = ph_map.add_contact_manual(temp);
                     if (flag) {
                         cout << "Contact added." << endl;
                     } else
                         cout << "Error" << endl;
                 } else if(input == 3) {
                     cout << "ENTER CONTACT TO BE DELETED: ";
                     cin.ignore();
                     getline(cin,input_string);
                     cout << ph_map.delete_contact(input_string) << endl;
                 }
                 else if(input == 4) {
                     cout << "ENTER OLD CONTACT NAME: ";
                     cin.ignore();
                     getline(cin,input_string);
                     string old_name = input_string;
                     cout << "ENTER NEW CONTACT NAME: ";
                     cin.ignore();
                     getline(cin,input_string);
                     cout << endl;
                     ph_map.edit_contact_name(old_name, input_string);
                 }
                 else if(input == 5) {
                     cout << "ENTER CONTACT NAME: ";
                     cin.ignore();
                     getline(cin,input_string);
                     string old_name = input_string;
                     cout << "ENTER NEW CONTACT PHONE: ";
                     cin.ignore();
                     getline(cin,input_number);
                     cout << endl;
                     ph_map.edit_contact_number(old_name, input_number);
                 }
                 else if(input == 6) {
                     ph_map.show_all_contacts();
                 } else if (input == 7) {
                     using_map = false;
                     start();
                 }
             }
         }
         cout << "GOODBYE!" << endl;
    }
};


#endif //PHONEBOOK_PHONEBOOK_H
