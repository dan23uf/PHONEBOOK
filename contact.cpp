

#include "contact.h"

Contact::Contact() {
    phone_num = "-1";

}

Contact::Contact(string str, string x) {
    this->name = str;
    this->phone_num = x;
}

void Contact::show_contact() {
    cout << "Name: " << this->get_name() << endl;
    cout << "Phone #: " << this->get_phone() << endl;
}

string Contact::get_name() const {
    return this->name;
}

string Contact::get_phone() const {
    return this->phone_num;
}

void Contact::change_name(string& s) {
    this->name = s;
}

void Contact::change_phone(string& x) {
    this->phone_num = x;
}
