#pragma once
#include "MyThread.h"

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

class DBThread : public MyThread
{
private:
	void disconnect();

	std::mutex databaseLock;

	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
public:

	explicit DBThread();
	virtual ~DBThread();

	DBThread(const DBThread&) = delete;
	DBThread& operator=(const DBThread&) = delete;

	virtual void Init();
	virtual void Proc();

	int Connect();
	void SwitchDatabase(const std::string& name);

	bool Execute(const std::string& query);
	std::shared_ptr<sql::ResultSet>  ExecuteQuery(const std::string& query);
};