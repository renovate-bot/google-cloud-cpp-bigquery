#include <google/cloud/bigquery/storage/v1beta1/storage.pb.h>
#include <memory>

#include "bigquery/internal/connection_impl.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

namespace bigquerystorage_proto = ::google::cloud::bigquery::storage::v1beta1;

using ::google::cloud::Status;
using ::google::cloud::StatusCode;
using ::google::cloud::StatusOr;

StatusOr<std::string> ConnectionImpl::CreateSession(std::string table) {
  bigquerystorage_proto::CreateReadSessionRequest request;
  request.mutable_table_reference()->set_table_id(table);

  return Status(StatusCode::kUnimplemented,
                "This function has not been implemented yet.");
}

std::shared_ptr<ConnectionImpl> MakeConnection() {
  return std::shared_ptr<ConnectionImpl>(new ConnectionImpl);
}

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
