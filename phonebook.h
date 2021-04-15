//
// Created by danie on 4/11/2021.
//

#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <bits/stdc++.h>
using namespace std;

class phonebook {
    private:
    struct TrieNode{
        //This map conatins a char (alphabet) points to a TrieNode
        unordered_map<char, TrieNode*> node;

        bool last;
        //Constructor
        TrieNode()
        {
            //initialize nodes
            for(char c = 'a'; c <= 'z'; c++)
                node[c] = NULL;
          
          last = false;
        }
    };

    //Root Tree
    TrieNode* root = NULL;

    public:
    //TODO Show Contact INFO
    //TODO ADD CONTACT MANUALLY
    void insertContact(string name);
    //Insert all the Contacts into the Trie
    void insertIntoTries(string contacts[], int n);
    //TODO EDIT EXISTING CONTACT
    //TODO DELETE INDIVIDUAL CONTACT
    //TODO DELETE ALL CONTACT

    //TODO VALIDATIONS
    //TODO LOAD CONTACTS FROM FILE or API
    //TODO SAVE CONTACT TO FILE


    //TODO SEARCH CONTACT

    //TODO HEAP IMPLEMENTATION
    //TODO VECTOR WITH BINARY SEARCH IMPLEMENTATION
    //TODO BST IMPLEMENTATION
    //TODO TRIE IMPLEMENTATION???

};


#endif //PHONEBOOK_PHONEBOOK_H
