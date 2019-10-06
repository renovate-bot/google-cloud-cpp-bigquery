#ifndef BIGQUERY_INTERNAL_BIGQUERY_READ_STUB_H_
#define BIGQUERY_INTERNAL_BIGQUERY_READ_STUB_H_

#include <google/cloud/bigquery/storage/v1beta1/storage.pb.h>
#include <memory>

#include "bigquery/connection.h"
#include "bigquery/connection_options.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

/** BigQueryReadStub is a thin stub layer over the BigQuery Storage API that
 * hides the underlying transport stub, i.e., gRPC. */
class BigQueryReadStub {
 public:
  virtual ~BigQueryReadStub() = default;

  virtual google::cloud::StatusOr<
      google::cloud::bigquery::storage::v1beta1::ReadSession>
  CreateReadSession(
      google::cloud::bigquery::storage::v1beta1::CreateReadSessionRequest const&
          request) = 0;

 protected:
  BigQueryReadStub() = default;
};

std::shared_ptr<BigQueryReadStub> MakeDefaultBigQueryReadStub(
    ConnectionOptions const& options);

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_INTERNAL_BIGQUERY_READ_STUB_H_
