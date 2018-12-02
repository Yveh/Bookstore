#ifndef Command_H
#define Command_H

#include "dataSystem.h"
#include "account.h"
#include "database.h"
#include "finance.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

enum ResultType { Executed, Exit };

class CommandSystem
{
private:
	std::fstream dataIO;
	std::vector<DataType> curSelected;

private:
	AccountSystem *Account;
	FinanceSystem *Finance;
	Database *ISBNDatabase;
	Database *nameDatabase;
	Database *authorDatabase;
	Database *keywordDatabase;

public:
	CommandSystem(const std::string &file);
	~CommandSystem();

private:
	std::vector<std::string> parse(std::string str);
	void modify(DataType data);

private:
	ResultType userCommand(std::vector<std::string> token);
	ResultType dataCommand(std::vector<std::string> token);
	void printSelected();

public:
	ResultType runCommand(const std::string &str);
	ResultType runLoadCommand(const std::string &file);
};

#endif Command_H