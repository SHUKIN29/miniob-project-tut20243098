#include "sql/executor/drop_table_executor.h"
#include "sql/stmt/drop_table_stmt.h"
#include "storage/db/db.h"

RC DropTableExecutor::execute(QuerySqlContext *sql_context) {
  if (sql_context == nullptr || sql_context->stmt_ == nullptr) {
    return RC::INVALID_ARGUMENT;
  }

  DropTableStmt *drop_table_stmt = static_cast<DropTableStmt *>(sql_context->stmt_);
  const char *db_name = drop_table_stmt->db_name_;
  const char *table_name = drop_table_stmt->table_name_;

  RC rc = drop_table(db_name, table_name);
  if (rc == RC::SUCCESS) {
    sql_context->set_response("Drop table success.");
  } else if (rc == RC::TABLE_NOT_FOUND) {
    sql_context->set_response("Drop table failed: table not found.");
  } else {
    sql_context->set_response("Drop table failed.");
  }

  return rc;
}
