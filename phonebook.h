#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <bits/stdc++.h>
using namespace std;

class phonebook {
private:
    struct TrieNode{
        //This map contains a char (alphabet) points to a TrieNode
        unordered_map<char, TrieNode*> node;
        bool last;

        TrieNode()//Constructor
        {
            //initialize nodes
            for(char c = 'a'; c <= 'z'; c++)
                node[c] = nullptr;

            last = false;
        }
    };

    //Root Tree
    TrieNode* root = nullptr;

public:
    TrieNode* getRoot() {
        return root;
    }

    // Show Contact INFO
    void showAllContacts(char name[], TrieNode* current, int height);
    //ADD CONTACT MANUALLY
    void insertContact(string name);
    //Insert all the Contacts into the Trie
    void insertIntoTries(string contacts[], int n);
    // EDIT EXISTING CONTACT
    void editContact(string oldName, string newName); // **fix
    // DELETE INDIVIDUAL CONTACT
    void deleteContact(string name);
    // DELETE ALL CONTACT
    void deleteAllContacts(TrieNode* current);

    //TODO VALIDATIONS
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE

    // SEARCH CONTACT
    bool searchContact(string name);

    //TODO HEAP IMPLEMENTATION
    //TODO VECTOR WITH BINARY SEARCH IMPLEMENTATION
    //TODO BST IMPLEMENTATION
    //TODO TRIE IMPLEMENTATION???

};


#endif //PHONEBOOK_PHONEBOOK_H