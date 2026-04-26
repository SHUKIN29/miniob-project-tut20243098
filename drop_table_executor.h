#ifndef __DROP_TABLE_EXECUTOR_H__
#define __DROP_TABLE_EXECUTOR_H__

#include "sql/executor/command_executor.h"

class DropTableStmt;
class DropTableExecutor : public CommandExecutor
{
public:
  DropTableExecutor() = default;
  virtual ~DropTableExecutor() = default;

  RC execute(QuerySqlContext *sql_context) override;
};

#endif
