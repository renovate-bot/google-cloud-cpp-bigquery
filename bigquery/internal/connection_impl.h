#ifndef BIGQUERY_INTERNAL_CONNECTION_H_
#define BIGQUERY_INTERNAL_CONNECTION_H_

#include <memory>

#include "bigquery/connection.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

class ConnectionImpl : public Connection {
 public:
  google::cloud::StatusOr<std::string> CreateSession(
      std::string table) override;
};

std::shared_ptr<ConnectionImpl> MakeConnection();

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_INTERNAL_CONNECTION_H_
