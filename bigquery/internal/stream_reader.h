#ifndef BIGQUERY_INTERNAL_STREAMING_READER_H_
#define BIGQUERY_INTERNAL_STREAMING_READER_H_

#include "bigquery/version.h"
#include "google/cloud/optional.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

// A class for representing a server stream that will return zero or
// more messages of type T. This class exists to hide away the details
// of the underlying transport stub, e.g., gRPC.
template <class T>
class StreamReader {
 public:
  virtual ~StreamReader() = default;

  // Reads the next value from the stream.
  //
  // If a value exists, an optional containing the value is returned.
  //
  // If the end of the stream is reached, an empty optional is
  // returned.
  //
  // Any non-OK status signals that something went wrong reading from
  // the stream.
  virtual google::cloud::StatusOr<google::cloud::optional<T>> NextValue() = 0;
};

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_INTERNAL_STREAMING_READER_H_
