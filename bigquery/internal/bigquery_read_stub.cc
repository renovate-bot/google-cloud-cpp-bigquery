#include <google/cloud/bigquery/storage/v1beta1/storage.grpc.pb.h>
#include <google/cloud/bigquery/storage/v1beta1/storage.pb.h>
#include <memory>

#include <grpcpp/create_channel.h>

#include "bigquery/connection.h"
#include "bigquery/internal/bigquery_read_stub.h"
#include "google/cloud/grpc_utils/grpc_error_delegate.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

namespace {

namespace bigquerystorage_proto = ::google::cloud::bigquery::storage::v1beta1;

using ::google::cloud::Status;
using ::google::cloud::StatusCode;
using ::google::cloud::StatusOr;
using ::google::cloud::grpc_utils::MakeStatusFromRpcError;

class DefaultBigQueryReadStub : public BigQueryReadStub {
 public:
  explicit DefaultBigQueryReadStub(
      std::unique_ptr<bigquerystorage_proto::BigQueryStorage::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  google::cloud::StatusOr<bigquerystorage_proto::ReadSession> CreateReadSession(
      bigquerystorage_proto::CreateReadSessionRequest const& request) override;

 private:
  std::unique_ptr<bigquerystorage_proto::BigQueryStorage::StubInterface>
      grpc_stub_;
};

google::cloud::StatusOr<bigquerystorage_proto::ReadSession>
DefaultBigQueryReadStub::CreateReadSession(
    bigquerystorage_proto::CreateReadSessionRequest const& request) {
  bigquerystorage_proto::ReadSession response;
  grpc::ClientContext client_context;
  grpc::Status grpc_status =
      grpc_stub_->CreateReadSession(&client_context, request, &response);
  if (!grpc_status.ok()) {
    return MakeStatusFromRpcError(grpc_status);
  }
  return response;
}

}  // namespace

std::shared_ptr<BigQueryReadStub> MakeDefaultBigQueryReadStub() {
  // TODO(aryann): Create a ChannelOptions class.
  grpc::ChannelArguments channel_arguments;

  auto grpc_stub =
      bigquerystorage_proto::BigQueryStorage::NewStub(grpc::CreateCustomChannel(
          "bigquerystorage.googleapis.com", grpc::GoogleDefaultCredentials(),
          channel_arguments));

  return std::make_shared<DefaultBigQueryReadStub>(std::move(grpc_stub));
}

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
