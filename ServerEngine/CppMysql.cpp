
#include "CppMysql.h"

#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/errmsg.h>

MYSQLException::MYSQLException(int num, const std::string& str)
	:errorNum_(num),
	str_(str)
{

}


int MYSQLException::getErrorNum() const
{
	return errorNum_;
}

bool MYSQLException::IsConnectError() const
{
	if (errorNum_ == CR_SERVER_GONE_ERROR || errorNum_ == CR_SERVER_LOST)
	{
		return true;
	}

	return false;
}
const char* MYSQLException::what() const noexcept
{
	return str_.c_str();
}

MYSQLQuery::MYSQLQuery()
{
	m_MysqlRes = NULL;
	_field = NULL;
	_row = NULL;
	_row_count = 0;
	_field_count = 0;
}

MYSQLQuery::MYSQLQuery(MYSQLQuery& rQuery)
{
	*this = rQuery;
}

MYSQLQuery& MYSQLQuery::operator=(MYSQLQuery& rQuery)
{
	if (this == &rQuery)
	{
		return *this;
	}

	freeRes();

	m_MysqlRes = rQuery.m_MysqlRes;
	_row = NULL;
	_row_count = 0;
	_field_count = 0;
	_field = NULL;
	if ( m_MysqlRes != NULL )
	{
		//定位游标位置到第一个位置
		mysql_data_seek((MYSQL_RES*)m_MysqlRes, 0);
		_row =  mysql_fetch_row((MYSQL_RES*)m_MysqlRes );
		_row_count = (int)mysql_num_rows((MYSQL_RES*)m_MysqlRes );
		//得到字段数量
		_field_count = mysql_num_fields((MYSQL_RES*)m_MysqlRes );
	}
	rQuery.m_MysqlRes = NULL;
	rQuery._field = NULL;
	rQuery._row = NULL;
	rQuery._row_count = 0;
	rQuery._field_count = 0;
	return *this;
}

MYSQLQuery::~MYSQLQuery()
{
	freeRes();
}

void MYSQLQuery::freeRes()
{
	if ( m_MysqlRes != NULL )
	{
		mysql_free_result((MYSQL_RES*)m_MysqlRes);
		m_MysqlRes = NULL;
	}
}

bool MYSQLQuery::isRecordsetOpened() const
{
	return m_MysqlRes != NULL;
}

int MYSQLQuery::numRow()
{
	return _row_count;
}

int MYSQLQuery::numFields()
{
	return _field_count;
}

int MYSQLQuery::seekRow(int offerset)
{
	if (offerset < 0)
	{
		offerset = 0;
	}

	if (offerset >= _row_count)
	{
		offerset = _row_count - 1;
	}

	mysql_data_seek((MYSQL_RES*)m_MysqlRes, offerset);

	_row = mysql_fetch_row((MYSQL_RES*)m_MysqlRes);

	return offerset;
}

int MYSQLQuery::fieldIndex(const char* szField)
{
	if ( NULL == m_MysqlRes )
	{
		return -1;
	}

	if ( NULL == szField )
	{
		return -1;
	}

	mysql_field_seek((MYSQL_RES*)m_MysqlRes, 0);//定位到第0列
	int i = 0;
	while ( i < _field_count )
	{
		_field = mysql_fetch_field((MYSQL_RES*)m_MysqlRes );
		if ( _field != NULL && strcmp(((MYSQL_FIELD*)_field)->name, szField) == 0 )//找到
		{
			return i;
		}

		i++;
	}

	return -1;
}

const char* MYSQLQuery::fieldName(int nCol)
{
	if ( m_MysqlRes == NULL )
	{
		return NULL;
	}

	mysql_field_seek((MYSQL_RES*)m_MysqlRes, nCol);

	_field = mysql_fetch_field((MYSQL_RES*)m_MysqlRes);
	if ( _field != NULL )
	{
		return ((MYSQL_FIELD*)_field)->name;
	}

	return  NULL;
}

int MYSQLQuery::getIntField(int nField, int nNullValue/*=0*/)
{
	if ( NULL == m_MysqlRes )
	{
		return nNullValue;
	}

	if ( nField + 1 > (int)_field_count )
	{
		return nNullValue;
	}

	if ( NULL == _row )
	{
		return nNullValue;
	}

	return atoi(_row[nField]);
}

int MYSQLQuery::getIntField(const char* szField, int nNullValue/*=0*/)
{
	if ( NULL == m_MysqlRes || NULL == szField )
	{
		return nNullValue;
	}

	if ( NULL == _row )
	{
		return nNullValue;
	}

	const char* filed = getStringField(szField);
	if ( NULL == filed )
	{
		return nNullValue;
	}

	return atoi(filed);
}

const char* MYSQLQuery::getStringField(int nField, const char* szNullValue/*=""*/)
{
	if ( NULL == m_MysqlRes )
	{
		return szNullValue;
	}

	if ( nField + 1 > (int)_field_count )
	{
		char buffer[512] = { 0 };
		sprintf(buffer, "out of range fieldIndex:%d", nField);
		throw MYSQLException(0, buffer);

		return szNullValue;
	}

	if ( NULL == _row )
	{
		return szNullValue;
	}

	if(_row[nField] == NULL)
	{
		return szNullValue;
	}

	return _row[nField];
}

const char* MYSQLQuery::getStringField(const char* szField, const char* szNullValue/*=""*/)
{
	if ( NULL == m_MysqlRes )
	{
		return szNullValue;
	}

	int nField = fieldIndex(szField);
	if ( nField == -1 )
	{
		char buffer[512] = { 0 };
		sprintf(buffer, "can't find fieldName %s", szField);
		throw MYSQLException(0, buffer);
	}

	return getStringField(nField, szNullValue);
}

int64_t MYSQLQuery::getInt64Field(int nField, int64_t nNullValue /*= 0*/)
{
	if ( NULL == m_MysqlRes )
	{
		return nNullValue;
	}

	if ( nField + 1 > (int)_field_count )
	{
		return nNullValue;
	}

	if ( NULL == _row )
	{
		return nNullValue;
	}

	return atoll(_row[nField]);
}

int64_t MYSQLQuery::getInt64Field(const char* szField, int64_t nNullValue /*= 0*/)
{
	if ( NULL == m_MysqlRes || NULL == szField )
	{
		return nNullValue;
	}

	if ( NULL == _row )
	{
		return nNullValue;
	}

	const char* filed = getStringField(szField);
	if ( NULL == filed )
	{
		return nNullValue;
	}

	return atoll(filed);
}

double MYSQLQuery::getFloatField(int nField, double fNullValue/*=0.0*/)
{
	const char* field = getStringField(nField);
	if ( NULL == field )
	{
		return fNullValue;
	}

	return atof(field);
}

double MYSQLQuery::getFloatField(const char* szField, double fNullValue/*=0.0*/)
{
	const char* field = getStringField(szField);
	if ( NULL == field )
	{
		return fNullValue;
	}

	return atof(field);
}

void MYSQLQuery::nextRow()
{
	if ( NULL == m_MysqlRes )
	{
		return;
	}

	_row = mysql_fetch_row((MYSQL_RES*)m_MysqlRes);
}

const unsigned char* MYSQLQuery::getBlobField(int nField, int& nLen)
{
	const unsigned char* pData = (const unsigned char*)getStringField(nField);
	if (NULL == pData)
	{
		return NULL;
	}

	unsigned   long*   FieldLength = mysql_fetch_lengths((MYSQL_RES*)m_MysqlRes);
	nLen = (int)FieldLength[nField];

	return pData;
}

const unsigned char* MYSQLQuery::getBlobField(const char* szField, int& nLen)
{
	if (NULL == m_MysqlRes)
	{
		return NULL;
	}

	int nField = fieldIndex(szField);
	if (nField == -1)
	{
		return NULL;
	}

	const unsigned char* pData = (const unsigned char*)getStringField(nField);
	if (NULL == pData)
	{
		return NULL;
	}

	unsigned   long*   FieldLength = mysql_fetch_lengths((MYSQL_RES*)m_MysqlRes);
	nLen = (int)FieldLength[nField];

	return pData;
}

bool MYSQLQuery::fieldIsNull(int nField)
{
	if (NULL == m_MysqlRes)
	{
		return NULL;
	}

	const unsigned char* pData = (const unsigned char*)getStringField(nField);
	if (NULL == pData)
	{
		return true;
	}

	return false;
}

bool MYSQLQuery::fieldIsNull(const char* szField)
{
	if (NULL == m_MysqlRes)
	{
		return NULL;
	}

	const unsigned char* pData = (const unsigned char*)getStringField(szField);
	if (NULL == pData)
	{
		return true;
	}

	return false;
}

bool MYSQLQuery::eof()
{
	return (_row == NULL);
}

MYSQLConnection::MYSQLConnection()
	:mysql_(NULL)
{

}

MYSQLConnection::~MYSQLConnection()
{
	if (mysql_ != NULL )
	{
		close();
	}
}

void MYSQLConnection::open(const char* host, const char* user, const char* passwd, const char* db,
                       unsigned int port, const char* charSetName, unsigned long client_flag /*= 0*/)
{
	mysql_ = mysql_init(NULL);
	if (NULL == mysql_)
	{
		throw MYSQLException(0, "init mysql failed!");
	}

	if (0 != mysql_options((MYSQL*)mysql_, MYSQL_SET_CHARSET_NAME, charSetName))
	{
		throw MYSQLException(mysql_errno((MYSQL*)mysql_), mysql_error((MYSQL*)mysql_));
	}

	//如果连接失败，返回NULL。对于成功的连接，返回值与第1个参数的值相同。
	if ( NULL == mysql_real_connect((MYSQL*)mysql_, host, user, passwd, db, port, NULL, client_flag) )
	{
		throw MYSQLException(mysql_errno((MYSQL*)mysql_), mysql_error((MYSQL*)mysql_));
	}

	m_strHost		= host;
	m_strUser		= user;
	m_strPwd		= passwd;
	m_strDB			= db;
	m_nPort			= port;
	m_strCharSet	= charSetName;

	//选择制定的数据库失败
	//0表示成功，非0值表示出现错误。
	if ( mysql_select_db((MYSQL*)mysql_, db ) != 0 )
	{
		throw MYSQLException(mysql_errno((MYSQL*)mysql_), mysql_error((MYSQL*)mysql_));
	}
}

bool MYSQLConnection::setOpenParam(const char* host, const char* user, const char* passwd, const char* db, unsigned int port, const char* charSetName /*= "utf8"*/, unsigned long client_flag /*= 0*/)
{
	m_strHost = host;
	m_strUser = user;
	m_strPwd = passwd;
	m_strDB = db;
	m_nPort = port;
	m_strCharSet = charSetName;
	return true;
}

void MYSQLConnection::close()
{
	if ( mysql_ != NULL )
	{
		mysql_close((MYSQL*)mysql_);
		mysql_ = NULL;
	}
}

/* 处理返回多行的查询，返回影响的行数 */
MYSQLQuery& MYSQLConnection::querySQL(const char* sql)
{
	do 
	{
		if (mysql_ == nullptr) 
		{		
			fprintf(stderr, "尝试重新连接数据库");
			reconnect();
			continue;		
		}

		m_strLastSQL = sql;

		if (mysql_real_query((MYSQL*)mysql_, sql, (unsigned long)strlen(sql)) != 0)
		{
			if (mysql_errno((MYSQL*)mysql_) == CR_SERVER_GONE_ERROR || mysql_errno((MYSQL*)mysql_) == CR_SERVER_LOST)
			{
				fprintf(stderr, "尝试重新连接数据库");
				reconnect();
				continue;
			}

			throw MYSQLException(mysql_errno((MYSQL*)mysql_), mysql_error((MYSQL*)mysql_));
		}
	
		m_dbQuery.m_MysqlRes = mysql_store_result((MYSQL*)mysql_);
		return m_dbQuery;
		
	} while (true);		
}

/* 执行非返回结果查询 */
int MYSQLConnection::execSQL(const char* sql)
{
	do 
	{ 
		if (mysql_ == nullptr)
		{
			fprintf(stderr, "尝试重新连接数据库");
			reconnect();
			continue;
		}

		m_strLastSQL = sql;
		int nRet = mysql_real_query((MYSQL*)mysql_, sql, (unsigned long)strlen(sql));
		if (nRet == 0)
		{
			//得到受影响的行数
			return (int)mysql_affected_rows((MYSQL*)mysql_);
		}
		if (mysql_errno((MYSQL*)mysql_) == CR_SERVER_GONE_ERROR || mysql_errno((MYSQL*)mysql_) == CR_SERVER_LOST)
		{
			fprintf(stderr, "尝试重新连接数据库");
			reconnect();
			continue;
		}

		throw MYSQLException(mysql_errno((MYSQL*)mysql_), mysql_error((MYSQL*)mysql_));

	} while (true);
}

/* 测试mysql服务器是否存活 */
bool MYSQLConnection::ping()
{
	if (mysql_ == nullptr)
	{
		return false;
	}

	if( mysql_ping((MYSQL*)mysql_) == 0 )
	{
		return true;
	}

	return false;
}

/* 关闭mysql 服务器 */
bool MYSQLConnection::shutDown()
{
	if( mysql_shutdown((MYSQL*)mysql_, SHUTDOWN_DEFAULT) == 0 )
	{
		return true;
	}

	return false;
}

/* 主要功能:重新启动mysql 服务器 */
bool MYSQLConnection::reboot()
{
	if(!mysql_reload((MYSQL*)mysql_))
	{
		return true;
	}

	return false;
}

void MYSQLConnection::reconnect()
{
	close();

	try
	{
		open(m_strHost.c_str(), m_strUser.c_str(), m_strPwd.c_str(), m_strDB.c_str(), m_nPort, m_strCharSet.c_str());
	}
	catch (const std::exception&)
	{
		reconnect();
	}
}

/*
* 说明:事务支持InnoDB or BDB表类型
*/
/* 主要功能:开始事务 */
bool MYSQLConnection::startTransaction()
{
	if(!mysql_real_query((MYSQL*)mysql_, "START TRANSACTION", (unsigned long)strlen("START TRANSACTION") ))
	{
		return true;
	}

	return false;
}

/* 主要功能:提交事务 */
bool MYSQLConnection::commit()
{
	if(!mysql_real_query((MYSQL*)mysql_, "COMMIT", (unsigned long)strlen("COMMIT") ) )
	{
		return true;
	}

	return false;
}

/* 主要功能:回滚事务 */
bool MYSQLConnection::rollback()
{
	if(!mysql_real_query((MYSQL*)mysql_, "ROLLBACK", (unsigned long)strlen("ROLLBACK") ) )
	{
		return true;
	}

	return false;
}

/* 得到客户信息 */
const char* MYSQLConnection::getClientInfo()
{
	return mysql_get_client_info();
}

/* 主要功能:得到客户版本信息 */
const unsigned long  MYSQLConnection::getClientVersion()
{
	return mysql_get_client_version();
}

/* 主要功能:得到主机信息 */
const char* MYSQLConnection::getHostInfo()
{
	return mysql_get_host_info((MYSQL*)mysql_);
}

/* 主要功能:得到服务器信息 */
const char* MYSQLConnection::GetServerInfo()
{
	return mysql_get_server_info((MYSQL*)mysql_);
}

const char* MYSQLConnection::GetErrorMsg()
{
	return m_strError.c_str();
}

/*主要功能:得到服务器版本信息*/
const unsigned long  MYSQLConnection::GetDBVersion()
{
	return mysql_get_server_version((MYSQL*)mysql_);
}

/*主要功能:得到 当前连接的默认字符集*/
const char*   MYSQLConnection::getCharacterSetName()
{
	return mysql_character_set_name((MYSQL*)mysql_);
}

/* 建立新数据库 */
int MYSQLConnection::createDB(const char* name)
{
	char temp[1024];
	snprintf(temp, 1024, "CREATE DATABASE %s", name);
	if(!mysql_real_query((MYSQL*)mysql_, temp, (unsigned long)strlen(temp)) )
	{
		return 0;
	}

	return -1;
}

/* 删除制定的数据库*/
int MYSQLConnection::dropDB(const char*  name)
{
	char temp[1024];

	snprintf(temp, 1024, "DROP DATABASE %s", name);
	if(!mysql_real_query((MYSQL*)mysql_, temp, (unsigned long)strlen(temp)) )
	{
		return 0;
	}

	return -1;
}

bool MYSQLConnection::changeCurDB(const char* name)
{
	if (mysql_ == NULL)
	{
		return false;
	}

	if (0 == mysql_select_db((MYSQL*)mysql_, name))
	{
		return true;
	}

	return false;
}

int64_t MYSQLConnection::getAutoIncrementID(const char* szTableName, const char* szDBName)
{
	if ((szTableName == NULL) || (szDBName == NULL))
	{
		return 0;
	}

	char strSql[1024];
	snprintf(strSql, 1024, "SELECT auto_increment FROM information_schema.tables where table_schema=\"%s\" and table_name=\"%s\"", szDBName, szTableName);
	
	try
	{
		return querySQL(strSql).getInt64Field(0);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

bool MYSQLConnection::setAutoIncrementID(int64_t nId, const char* szTableName, const char* szDBName)
{
	if ((szTableName == NULL) || (szDBName == NULL))
	{
		return false;
	}

	char strSql[1024];
	snprintf(strSql, 1024, "alter table %s.%s AUTO_INCREMENT=%lld;", szDBName, szTableName, nId);

	try
	{
		return execSQL(strSql) != 0;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

MYSQLQuery& MYSQLConnection::nextRecordset()
{
	if (mysql_ != nullptr)
	{
		mysql_next_result((MYSQL*)mysql_);
		m_dbQuery.m_MysqlRes = mysql_store_result((MYSQL*)mysql_);
	}
	return m_dbQuery;
}


