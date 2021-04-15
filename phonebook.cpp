//
// Created by danie on 4/11/2021.
//
#include "phonebook.h"
#include "contact.h"

void phonebook::insertContact(string name){
        TrieNode* current = root;

        TrieNode* newNode;
        for(int i = 0; i < name.length(); i++)
        {
            //If node does not exist create a new one
            if(current->node[name[i]] == NULL){
                newNode = new TrieNode();
                current->node[name[i]] = newNode;
            }

            current = newNode;

            //Marks when the contact ends
            if(i == name.length()-1)
               current->last = true;
        }
    }

void phonebook::insertIntoTries(string contacts[], int n){
        root = new TrieNode();

        for(int i = 0; i < n; i++)
            insertContact(contacts[i]);
}