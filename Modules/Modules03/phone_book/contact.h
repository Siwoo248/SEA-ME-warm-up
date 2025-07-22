#ifndef CONTACT_H
#define CONTACT_H

#include<QString>
using namespace std;

class Contact
{
private:
    QString name;
    QString phone_num;
    QString email;
public:
    Contact(const QString& name = "", const QString& phone_num = "", const QString& email = "");

    // setter
    void setName(const QString& name);
    void setPhone_num(const QString& phone_num);
    void setEmail(const QString& email);

    // getter
    QString getName() const;
    QString getPhone_num() const;
    QString getEmail() const;
    QString toString() const;

};

#endif // CONTACT_H
