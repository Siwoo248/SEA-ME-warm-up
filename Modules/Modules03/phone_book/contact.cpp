#include "contact.h"

Contact::Contact(const QString& n, const QString& p, const QString& e){
    name = n;
    phone_num = p;
    email = e;
}

// setter
void Contact::setName(const QString& n){
    name = n;
}
void Contact::setPhone_num(const QString& p){
    phone_num = p;
}
void Contact::setEmail(const QString& e){
    email = e;
}
// getter
QString Contact::getName() const{
    return name;
}
QString Contact::getPhone_num() const{
    return phone_num;
}
QString Contact::getEmail() const{
    return email;
}
QString Contact::toString()const{
    return name + " | " + phone_num + " | " + email;
}
