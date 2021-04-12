
#ifndef PHONEBOOK_CONTACT_H
#define PHONEBOOK_CONTACT_H

#include<bits/stdc++.h>

using namespace std;

class contact {

    string name;
    int phone_num;


public:

    contact();
    contact(string str, int x);

    void show_contact();

    string get_name() const;
    int get_phone() const;

    void change_name(string& s);
    void change_phone(int& x);

};


#endif //PHONEBOOK_CONTACT_H
