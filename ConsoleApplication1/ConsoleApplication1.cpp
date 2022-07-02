#include <iostream>
#include "PhoneBook.cpp"

int User::counter = 1;


int main()
{

    User u1("Ivanov1", "Info", "123456789", "123456789", "123456789");
    User u2("Ivanov2", "Info", "123456789", "123456789", "123456789");
    User u3("Ivanov3", "Info", "123456789", "123456789", "123456789");
    User u4("Ivanov4", "Info", "123456789", "123456789", "123456789");
    PhoneBook b1("Work");
    b1.addUser(u1);
    b1.addUser(u2);
    b1.addUser(u3);
    b1.addUser(u4);
    b1.printBok();
    b1.delUser(3);
    b1.printBok();
    b1.findUser("Ivanov");
    string path = { "C:\\Users\\Pavel\\Desktop\\123.txt" };
    b1.writeFile(path);
    b1.showFile(path);
}

