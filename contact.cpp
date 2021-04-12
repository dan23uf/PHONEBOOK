//
// Created by danie on 4/11/2021.
//

#include "contact.h"

contact::contact() {
    phone_num = -1;
}

contact::contact(string str, int x) {
    this->name = str;
    this->phone_num = x;
}

void contact::show_contact() {
    cout << "Name: " << this->get_name() << endl;
    cout << "Phone #: " << this->get_phone() << endl;
}

string contact::get_name() const {
    return this->name;
}

int contact::get_phone() const {
    return this->phone_num;
}

void contact::change_name(string& s) {
    this->name = s;
}

void contact::change_phone(int& x) {
    this->phone_num = x;
}
