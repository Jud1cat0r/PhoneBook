#pragma once
class User;
class PhoneBook;

class User
{
protected:
	char* name;
	string info;
	string telD;
	string telM;
	string telR;
	int sizeChar = 0;
	static int counter;
	int id = 0;
public:
	User()
	{

	}
	User(const char name[], string info, string telD, string telM, string telR)
	{
		sizeChar = strlen(name);
		this->name = new char[sizeChar + 1];
		for (int i = 0; i < sizeChar; i++)
		{
			this->name[i] = name[i];
		}
		this->name[sizeChar] = '\0';
		this->info = info;
		this->telD = telD;
		this->telM = telM;
		this->telR = telR;
		this->id = User::counter;
		User::counter++;
	}

	int& inkId()
	{
		return this->id -= 1;
	}

	User(const User& user)
	{
		this->info = user.info;
		this->telD = user.telD;
		this->telM = user.telM;
		this->telR = user.telR;
		this->id = user.id;
		this->sizeChar = user.sizeChar;
		this->name = new char[sizeChar +1];
		for (int i = 0; i < sizeChar; i++)
		{
			this->name[i] = user.name[i];
		}
		this->name[sizeChar] = '\0';
	}

	void operator =(const User& user)
	{
		this->info = user.info;
		this->telD = user.telD;
		this->telM = user.telM;
		this->telR = user.telR;
		this->id = user.id;
		this->sizeChar = user.sizeChar;
		this->name = new char[sizeChar + 1];
		for (int i = 0; i < sizeChar; i++)
		{
			this->name[i] = user.name[i];
		}
		this->name[sizeChar] = '\0';
	}

	friend ostream& operator <<(ostream& out, User& user)
	{
		out << user.id << ". " << "Name - " << user.name << " : " << "Home phone - " << user.telD << " : " << "Mob phone - " << user.telM << " : " << "Work phone - " << user.telR;
		return out;
	}

	bool findName(const char str[])
	{
		bool flag;
		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[0] == str[0])
			{
				if (name[i] == str[i]) flag = true;
				else return false;
			}
			else return false;
		}
		if (flag == true) return true;
	}

	void print()
	{
		cout << id << ". " << "Name - " << name << " : " << "Home phone - " << telD << " : " << "Mob phone - " << telM << " : " << "Work phone - " << telR << endl;
	}

	~User()
	{
		delete[]name;
	}
};



class PhoneBook
{
private:
	string nameBook;
	int size = 0;
	User* user = nullptr;
public:
	PhoneBook(string nameBook)
	{}
	void addUser(const User& user2)
	{
		User* buf = new User[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = user[i];
		}
		buf[size] = user2;
		delete[]user;
		user = buf;
		size++;
	}

	void delUser(int index)
	{
		User* buf = new User[size - 1];
		for (int i = 0; i < index - 1; i++)
		{
			buf[i] = user[i];
		}
		for (int i = index; i < size; i++)
		{
			user[i].inkId();
			buf[i - 1] = user[i];
		}
		delete[]user;
		user = buf;
		size--;
	}

	void findUser(const char str[])
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (user[i].findName(str) == true)
			{
				user[i].print();
				flag = true;
			}
		}
		if(flag == false) cout << "User not found";
	}

	void writeFile(string path) 
	{
		ofstream out(path);
		for (int i = 0; i < size; i++) 
		{
			out << user[i] << endl;
		}
		out.close();
	}

	void showFile(string path) 
	{
		string str;
		ifstream in(path);
		if (in.is_open()) 
		{
			while (getline(in, str)) 
			{
				cout << str << endl;
			}
		}
		in.close();
	}

	void printBok()
	{
		cout << nameBook << endl;
		for (int i = 0; i < size; i++)
		{
			user[i].print();
		}
	}
	~PhoneBook()
	{
		delete[]user;
	}

};

