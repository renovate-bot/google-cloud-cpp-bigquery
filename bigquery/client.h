#ifndef BIGQUERY_CLIENT_H_
#define BIGQUERY_CLIENT_H_

#include <memory>

#include "bigquery/connection.h"
#include "bigquery/connection_options.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class Client {
 public:
  explicit Client(std::shared_ptr<Connection> conn) : conn_(std::move(conn)) {}

  Client() = delete;

  // Client is copyable and movable.
  Client(Client const&) = default;
  Client& operator=(Client const&) = default;
  Client(Client&&) = default;
  Client& operator=(Client&&) = default;

  friend bool operator==(Client const& a, Client const& b) {
    return a.conn_ == b.conn_;
  }

  friend bool operator!=(Client const& a, Client const& b) { return !(a == b); }

  google::cloud::StatusOr<std::string> CreateSession(
      std::string parent_project_id, std::string table);

 private:
  std::shared_ptr<Connection> conn_;
};

std::shared_ptr<Connection> MakeConnection(ConnectionOptions const& options);

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_CLIENT_H_
