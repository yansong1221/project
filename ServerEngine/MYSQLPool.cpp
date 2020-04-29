
#include "MYSQLPool.h"
#include <mutex>
#include <thread>
#include <algorithm>

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
		auto p = std::make_shared<MYSQLConnection>();
		p->open(m_szDBAddr.c_str(), m_szUser.c_str(), m_szPassword.c_str(), m_szDBName.c_str(), m_wPort);
		m_Conns.push_back(p);
	}
}

std::shared_ptr<MYSQLConnection> CMYSQLPool::CreateMYSQLConn()
{
	std::unique_lock<SpinLock> ul(m_SpinLock);

	static int index = 0;

	for(int i = 0;i<m_Conns.size();++i)
	{
		index = (index + 1) % m_Conns.size();
		if(m_Conns[i].unique()) return m_Conns[i];
		
	}

	auto p = std::make_shared<MYSQLConnection>();
	p->open(m_szDBAddr.c_str(), m_szUser.c_str(), m_szPassword.c_str(), m_szDBName.c_str(), m_wPort);
	m_Conns.push_back(p);

	return p;
}

CMYSQLPool* CMYSQLPool::GetInstance()
{
	return m_pInstance;
}

void CMYSQLPool::UnInitialization()
{
	m_Conns.clear();
}


