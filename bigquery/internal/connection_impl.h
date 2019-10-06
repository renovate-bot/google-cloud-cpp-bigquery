#ifndef BIGQUERY_INTERNAL_CONNECTION_H_
#define BIGQUERY_INTERNAL_CONNECTION_H_

#include <memory>

#include "bigquery/connection.h"
#include "bigquery/internal/bigquery_read_stub.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

// An implementation of the Connection interface that sents requests
// to a read stub. This class acts as the point of entry for all
// client operations. This class should never contain
// transport-related logic (e.g., any gRPC-specific code).
class ConnectionImpl : public Connection {
 public:
  google::cloud::StatusOr<std::string> CreateSession(
      std::string parent_project_id, std::string table) override;

 private:
  friend std::shared_ptr<ConnectionImpl> MakeConnection(
      std::shared_ptr<BigQueryReadStub> read_stub);
  ConnectionImpl(std::shared_ptr<BigQueryReadStub> read_stub);

  std::shared_ptr<BigQueryReadStub> read_stub_;
};

std::shared_ptr<ConnectionImpl> MakeConnection(
    std::shared_ptr<BigQueryReadStub> read_stub);

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_INTERNAL_CONNECTION_H_
