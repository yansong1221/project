#pragma once

#include "ServerEngine.h"

#include <vector>
#include <memory>

#include "CppMysql.h"
#include "SpinLock.h"

class ENGINE_API CMYSQLPool
{
public:
	CMYSQLPool();
	~CMYSQLPool();

	void Initialization(const char* szDBAddr, int wPort, const char* szDBName, const char* szUser, const char* szPassword);
	std::shared_ptr<MYSQLConnection> CreateMYSQLConn();

	static CMYSQLPool* GetInstance();

	void UnInitialization();
protected:
	std::vector<std::shared_ptr<MYSQLConnection>> m_Conns;
	SpinLock m_SpinLock;
	static CMYSQLPool* m_pInstance;

	std::string m_szDBAddr;
	int m_wPort;
	std::string m_szDBName;
	std::string m_szUser;
	std::string m_szPassword;

};

