#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include"contact.h"
#include<QVector>

class Contact_list
{
private:
    QVector<Contact> contact_book;
public:
    Contact_list();
    void add_contact(const Contact& contact);
    void delete_contact(const QString& name);
    Contact search_contact(const QString& name) const;
    QVector<Contact> getAllContacts() const;

};

#endif // CONTACT_LIST_H
