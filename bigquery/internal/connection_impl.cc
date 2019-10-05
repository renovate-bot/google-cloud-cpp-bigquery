#include <google/cloud/bigquery/storage/v1beta1/storage.pb.h>
#include <memory>

#include "bigquery/internal/bigquery_read_stub.h"
#include "bigquery/internal/connection_impl.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

namespace bigquerystorage_proto = ::google::cloud::bigquery::storage::v1beta1;

using ::google::cloud::Status;
using ::google::cloud::StatusCode;
using ::google::cloud::StatusOr;

ConnectionImpl::ConnectionImpl(std::shared_ptr<BigQueryReadStub> read_stub)
    : read_stub_(read_stub) {}

StatusOr<std::string> ConnectionImpl::CreateSession(std::string table) {
  bigquerystorage_proto::CreateReadSessionRequest request;
  request.mutable_table_reference()->set_table_id(table);
  auto response = read_stub_->CreateReadSession(request);
  if (!response.ok()) {
    return response.status();
  }
  return response.value().name();
}

std::shared_ptr<ConnectionImpl> MakeConnection(
    std::shared_ptr<BigQueryReadStub> read_stub) {
  return std::shared_ptr<ConnectionImpl>(
      new ConnectionImpl(std::move(read_stub)));
}

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
