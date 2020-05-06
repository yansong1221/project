﻿#ifndef __MYSQL_HELPER_H__
#define __MYSQL_HELPER_H__

#include "ServerEngine.h"

#include <exception>
#include <string>

class ENGINE_API MYSQLException : public std::exception
{
public:
	MYSQLException(int num, const std::string& str);

	int getErrorNum() const;
	bool IsConnectError() const;

	virtual const char* what() const noexcept;
private:
	int errorNum_;
	std::string str_;
};


class ENGINE_API MYSQLQuery
{
	friend class MYSQLConnection;
public:
	MYSQLQuery();

	//当执行拷贝构造函数后，括号里的类已经无效，不能再使用
	MYSQLQuery(MYSQLQuery& rQuery);

	// 当执行赋值构造函数后， = 右边的类已经无效，不能再使用
	MYSQLQuery& operator=(MYSQLQuery& rQuery);

	virtual ~MYSQLQuery();

	int numRow();

	int numFields();

	int fieldIndex(const char* szField);

	//0...n-1列
	const char* fieldName(int nCol);

	int seekRow(int offerset);
	int getIntField(int nField, int nNullValue = 0);
	int getIntField(const char* szField, int nNullValue = 0);

	int64_t getInt64Field(int nField, int64_t nNullValue = 0);
	int64_t getInt64Field(const char* szField, int64_t nNullValue = 0);

	double getFloatField(int nField, double fNullValue = 0.0);
	double getFloatField(const char* szField, double fNullValue = 0.0);

	//0...n-1列
	const char* getStringField(int nField, const char* szNullValue = "");
	const char* getStringField(const char* szField, const char* szNullValue = "");

	const unsigned char* getBlobField(int nField, int& nLen);
	const unsigned char* getBlobField(const char* szField, int& nLen);

	bool fieldIsNull(int nField);
	bool fieldIsNull(const char* szField);

	bool eof();
	void nextRow();

	void freeRes();

	bool isRecordsetOpened() const;

private:
	void*	m_MysqlRes;
	void*	_field;
	char **  _row;
	int   _row_count;
	int   _field_count;
};

class ENGINE_API MYSQLConnection
{
public:
	MYSQLConnection();
	virtual ~MYSQLConnection();

	void open(const char* host, const char* user, const char* passwd, const char* db,
	          unsigned int port, const char* charSetName = "utf8mb4", unsigned long client_flag = (1UL << 16));

	bool setOpenParam(const char* host, const char* user, const char* passwd, const char* db,
	                  unsigned int port, const char* charSetName = "utf8mb4", unsigned long client_flag = (1UL << 16));

	void close();

	/* 处理返回多行的查询，返回影响的行数 */
	//返回引用是因为在CppMySQLQuery的赋值构造函数中要把成员变量_mysql_res置为空
	MYSQLQuery& querySQL(const char* sql);

	/* 执行非返回结果查询 */
	int execSQL(const char* sql);

	/* 测试mysql服务器是否存活 */
	bool ping();

	/* 关闭mysql 服务器 */
	bool shutDown();

	/* 主要功能:重新启动mysql 服务器 */
	bool reboot();

	/* 主要功能:重新连接mysql 服务器 */
	void reconnect();

	/*说明:事务支持InnoDB or BDB表类型*/
	/* 主要功能:开始事务 */
	bool startTransaction();

	/* 主要功能:提交事务 */
	bool commit();

	/* 主要功能:回滚事务 */
	bool rollback();

	/* 得到客户信息 */
	const char* getClientInfo();

	/* 主要功能:得到客户版本信息 */
	const unsigned long  getClientVersion();

	/* 主要功能:得到主机信息 */
	const char* getHostInfo();

	/* 主要功能:得到服务器信息 */
	const char* GetServerInfo();

	const char* GetErrorMsg();

	/*主要功能:得到服务器版本信息*/
	const unsigned long  GetDBVersion();

	/*主要功能:得到 当前连接的默认字符集*/
	const char*   getCharacterSetName();

	/* 建立新数据库 */
	int createDB(const char* name);

	/* 删除制定的数据库*/
	int dropDB(const char* name);

	/*修改当前的数据库*/
	bool changeCurDB(const char* name);

	int64_t getAutoIncrementID(const char* szTableName, const char* szDBName);

	bool  setAutoIncrementID(int64_t nId, const char* szTableName, const char* szDBName);

	MYSQLQuery& nextRecordset();

	void freeRes();

private:
	MYSQLConnection(const MYSQLConnection& db);
	MYSQLConnection& operator=(const MYSQLConnection& db);

private:
	/* msyql 连接句柄 */
	void* mysql_;

	MYSQLQuery m_dbQuery;

	int          m_nErrno;
	std::string  m_strError;


	std::string  m_strHost;
	std::string  m_strUser;
	std::string  m_strPwd;
	std::string  m_strDB;
	std::string  m_strCharSet; //字符集
	int          m_nPort;

	std::string m_strLastSQL;
};

#endif //__MYSQL_HELPER_H__