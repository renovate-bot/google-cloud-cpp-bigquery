#ifndef BIGQUERY_CLIENT_H_
#define BIGQUERY_CLIENT_H_

#include <memory>

#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {

class Connection;

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

  friend bool operator!=(Client const& a, Client const& b) {
    return !(a == b);
  }

  google::cloud::StatusOr<std::string> CreateSession(std::string table);

 private:
  std::shared_ptr<Connection> conn_;
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_CLIENT_H_
