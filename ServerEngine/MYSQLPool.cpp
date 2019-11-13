
#include "MYSQLPool.h"
#include <mutex>


CMYSQLPool* CMYSQLPool::m_pInstance = new CMYSQLPool;

CMYSQLPool::CMYSQLPool()
{

}
CMYSQLPool::~CMYSQLPool()
{

}
void CMYSQLPool::Initialization(const char* szDBAddr, int wPort, const char* szDBName, const char* szUser, const char* szPassword)
{
	m_szDBAddr = szDBAddr;
	m_wPort = wPort;
	m_szDBName = szDBName;
	m_szUser = szUser;
	m_szPassword = szPassword;

	std::unique_lock<SpinLock> ul(m_SpinLock);

	for (size_t i = 0; i < std::thread::hardware_concurrency() * 2; ++i)
	{
		MYSQLConnection* pDataBaseHelper = new MYSQLConnection;
		pDataBaseHelper->open(m_szDBAddr.c_str(), m_szUser.c_str(), m_szPassword.c_str(), m_szDBName.c_str(), m_wPort);
		m_FreeConns.push_back(pDataBaseHelper);
	}
}

MYSQLConnection* CMYSQLPool::CreateMYSQLConn()
{
	std::unique_lock<SpinLock> ul(m_SpinLock);

	MYSQLConnection* pDataBaseHelper = NULL;

	if (!m_FreeConns.empty())
	{
		pDataBaseHelper = m_FreeConns.front();
		m_FreeConns.pop_front();
		m_UseConns.push_back(pDataBaseHelper);

		return pDataBaseHelper;
	}

	pDataBaseHelper = new MYSQLConnection;
	pDataBaseHelper->open(m_szDBAddr.c_str(), m_szUser.c_str(), m_szPassword.c_str(), m_szDBName.c_str(), m_wPort);
	m_UseConns.push_back(pDataBaseHelper);

	return pDataBaseHelper;
}


void CMYSQLPool::RecoverMYSQLConn(MYSQLConnection* pDataBaseHelper)
{
	std::unique_lock<SpinLock> ul(m_SpinLock);

	auto iter = std::find(m_UseConns.begin(), m_UseConns.end(), pDataBaseHelper);
	if (iter == m_UseConns.end())
	{
		return;
	}
	m_FreeConns.push_back(pDataBaseHelper);
	m_UseConns.erase(iter);
}

CMYSQLPool* CMYSQLPool::GetInstance()
{
	return m_pInstance;
}

void CMYSQLPool::UnInitialization()
{
	for (auto v : m_FreeConns)
	{
		delete v;
	}
	m_FreeConns.clear();


	for (auto v : m_UseConns)
	{
		delete v;
	}
	m_UseConns.clear();
}


