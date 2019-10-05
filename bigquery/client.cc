#include <memory>

#include "bigquery/client.h"
#include "bigquery/connection.h"
#include "bigquery/internal/connection_impl.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
using ::google::cloud::StatusOr;

StatusOr<std::string> Client::CreateSession(std::string parent_project_id,
                                            std::string table) {
  return conn_->CreateSession(parent_project_id, table);
}

std::shared_ptr<Connection> MakeConnection() {
  std::shared_ptr<internal::BigQueryReadStub> stub =
      internal::MakeDefaultBigQueryReadStub();
  return internal::MakeConnection(std::move(stub));
}

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
