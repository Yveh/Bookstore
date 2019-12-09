#ifndef UserInterface_H
#define UserInterface_H

#include <map>
#include "dataSystem.h"

class UserInterface
{
public:
	static std::string read()
	{
		std::string ret = "";
		do
		{
			getline(std::cin, ret);
			while (ret.length() > 0 && ret.back() == '\r') ret.pop_back();
		} while (ret.length() == 0);
		return ret;
	}
private:
	static std::string ask(const std::string &str)
	{
		std::cerr << str;
		std::string ret = read();
		return ret;
	}

public:
	static void showManual()
	{
		std::map<int, std::string> corres = { {1,"login"},{2,"logout"},{3,"add user"},{4,"register"},{5,"delete"},
		{6,"change password"}, {7,"select a book"}, {8,"modify"},{9,"import"},{10,"show book"},{11,"show finance"},
		{12,"buy book"},{13,"report finance status"},{14,"report employee"},{15,"show log"},{16,"report myself"} };
		for (auto u : corres) std::cerr << "Enter " << u.first << " for " << u.second << std::endl;
	}

	static std::string getInput(bool root)
	{
		std::cerr << "Type of Operation: ";
		std::string str = read();
		int op = stringToInteger(str);
		switch (op)
		{
			case 1:
				return "su " + ask("Password: ") + " " + ask("ID: ");
			case 2:
				return "logout";
			case 3:
				return "useradd " + ask("name: ") + " " + ask("Password: ") + " " + ask("Authority Level: ") + " " + ask("ID: ");
			case 4:
				return "register " + ask("name: ") + " " + ask("Password: ") + " " + ask("ID: ");
			case 5:
				return "delete " + ask("ID: ");
			case 6:
				return "passwd " + ask("NewPassword: ") + ((!root) ? (" " + ask("OldPassword ")) : "") + " " + ask("ID: ");
			case 7:
				return "select " + ask("ISBN: ");
			case 8:
				return "modify " + ask("Type: (Enter -Type=xxx)");
			case 9:
				return "import " + ask("Quantity: ") + " " + ask("Price: ");
			case 10:
				return "show " + ask("Type: (Enter -Type=xxx)");
			case 11:
				return "show finance";
			case 12:
				return "buy " + ask("Quantity: ") + " " + ask("ISBN: ");
			case 13:
				return "report finance";
			case 14:
				return "report employee";
			case 15:
				return "log";
			case 16:
				return "report myself";
			default:
				return "";
		}
	}
};

#endif