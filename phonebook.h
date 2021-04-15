
#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H

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
