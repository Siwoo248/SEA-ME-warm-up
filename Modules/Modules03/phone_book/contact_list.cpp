#include "contact_list.h"

Contact_list::Contact_list(){}

void Contact_list::add_contact(const Contact& contact){
    contact_book.append(contact);
}

void Contact_list::delete_contact(const QString& name){
    for(int i=0; i<contact_book.size(); i++){
        if(contact_book[i].getName()==name){
            contact_book.removeAt(i);
        }
        else{
            i++;
        }
    }
}

Contact Contact_list::search_contact(const QString& name) const{
    for(int i=0; i<contact_book.size(); i++){
        if(contact_book[i].getName()==name){
            return contact_book[i];
        }
    }
    return Contact();
}


QVector<Contact> Contact_list::getAllContacts() const {
    return contact_book;
}
