
#include "contact.h"

Contact::Contact() {
    phone_num = "-1";

}

Contact::Contact(string str, string x) {
    this->name = str;
    this->phone_num = x;
}

void Contact::center(string str, int num_cols){
    int padding_left = (num_cols/2) - (str.size() / 2);

    for(int i = 0; i < padding_left; i++) cout<< ' ';

    cout<<str;
}

void Contact::show_contact() {
    vector<string> contact = {
            "----------------------------------------------",
            "|NAME: " + this->get_name() +                "|",
            "|PHONE: " + this->get_phone()+               "|",
            "                                               ",
            "                                               ",
            "                                               ",
            "                                               ",
            "-----------------------------------------------",
    };
    int num_cols = 100;

    cout<<endl;
    for(int i = 0; i < num_cols; i++) cout << ' ';
    cout <<endl;

    for(int i = 0; i < contact.size();i++){
        center(contact[i],num_cols);
        cout<<endl;
    }

    cout<<endl;
    for(int i = 0; i < num_cols; i++) cout<<' ';
    cout <<endl;
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
