#include "pch.h"
#include "DBThread.h"

//jdbc ? : DBMS와 통신을 담당 
//기존 각 DBMS마다 jdbc드라이버가 필요했는데 통일시킴

DBThread::DBThread()
{
	driver = nullptr;
	con = nullptr;
	stmt = nullptr;
}

DBThread::~DBThread()
{
	disconnect();
	delete con;
}
void DBThread::Init()
{
	mythread = std::thread([&]() { DBThread::Proc(); });
}
void DBThread::Proc()
{
	Connect();

}
void DBThread::disconnect()
{
	con->close();
}

int DBThread::Connect()
{
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "rootpass");
	con->setSchema("mysql");

	return 0; //SUCCESS
}

void DBThread::SwitchDatabase(const std::string& name)
{
	try {
		con->setSchema(sql::SQLString(name.c_str()));
		stmt = con->createStatement();
	}
	catch (sql::SQLException & e) {
		// err
	}
}

std::shared_ptr<sql::ResultSet> DBThread::ExecuteQuery(const std::string& query)
{
	databaseLock.lock();
	std::shared_ptr<sql::ResultSet> res;
	try {
		res.reset(stmt->executeQuery(query.c_str()));
	}
	catch (sql::SQLException & e) {
		// err
	}
	databaseLock.unlock();

	return res;
}

bool DBThread::Execute(const std::string& query)
{
	databaseLock.lock();
	bool res = false;
	try {
		res = stmt->execute(query.c_str());
	}
	catch (sql::SQLException & e) {
		// err
	}
	databaseLock.unlock();

	return res;
}