
#ifndef PHONEBOOK_CONTACT_H
#define PHONEBOOK_CONTACT_H

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Contact {

    string name;
    string phone_num;


public:

    Contact();
    Contact(string str, string x);

    void show_contact();

    string get_name() const;
    string get_phone() const;
    void center(string str, int num_cols);
    void change_name(string& s);
    void change_phone(string& x);

};


struct ContactComparator
{

    bool operator ()(const Contact* c1, const Contact* c2)
    {
        if(c1->get_name() == c2->get_name())
            return c1->get_name() < c2->get_name();
        return c1->get_name() < c2->get_name();
    }
};


#endif //PHONEBOOK_CONTACT_H
