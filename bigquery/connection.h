#ifndef BIGQUERY_CONNECTION_H_
#define BIGQUERY_CONNECTION_H_

#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class Connection {
 public:
  virtual ~Connection() = default;

  virtual google::cloud::StatusOr<std::string> CreateSession(
      std::string parent_project_id, std::string table) = 0;
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_CONNECTION_H_
