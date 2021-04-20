#include <iostream>
#include "phonebook.h"

using namespace std::chrono;


int main() {
    PB_VECTOR vector;
    PB_MAP map;
    PB_TRIE trie;
    string data_file = "data.csv";
    string company = "google";

    cout<<"COMPARING IMPLEMENTATION"<<endl;
    cout<<"----------------LOAD----------------"<<endl;

    cout<<"VECTOR: "<<endl;
    auto start = high_resolution_clock::now();
    vector.load_contacts(data_file);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;

    cout<<"MAP: "<<endl;
    start = high_resolution_clock::now();
    map.load_contacts(data_file);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;

    cout<<"TRIE: "<<endl;
    start = high_resolution_clock::now();
    trie.load_contacts(data_file);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;

    cout<<"----------------SEARCH----------------"<<endl;

    cout<<"VECTOR: "<<endl;
    start = high_resolution_clock::now();
    vector.search_contact_name(company);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;

    cout<<"MAP: "<<endl;
    start = high_resolution_clock::now();
    map.search_contact(company);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;

    cout<<"TRIE: "<<endl;
    start = high_resolution_clock::now();
    trie.searchContact(company);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"TIME TAKEN BY FUNCTION: "<<duration.count()<<" microseconds"<<endl<<endl;


    cout << "Starting..." << endl;
    phonebook _phonebook;
    _phonebook.start();
    return 0;
}
