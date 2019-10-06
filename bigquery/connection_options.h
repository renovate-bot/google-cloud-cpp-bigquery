#ifndef BIGQUERY_CONNECTION_OPTIONS_H_
#define BIGQUERY_CONNECTION_OPTIONS_H_

#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

#include "bigquery/version.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class ConnectionOptions {
 public:
  ConnectionOptions();

  explicit ConnectionOptions(
      std::shared_ptr<grpc::ChannelCredentials> credentials);

  ConnectionOptions& set_credentials(
      std::shared_ptr<grpc::ChannelCredentials> credentials) {
    credentials_ = std::move(credentials);
    return *this;
  }

  std::shared_ptr<grpc::ChannelCredentials> credentials() const {
    return credentials_;
  }

  ConnectionOptions& set_bigquerystorage_endpoint(std::string endpoint) {
    bigquerystorage_endpoint_ = std::move(endpoint);
    return *this;
  }

  std::string const& bigquerystorage_endpoint() const {
    return bigquerystorage_endpoint_;
  }

  ConnectionOptions& add_user_agent_prefix(std::string prefix) {
    prefix += " ";
    prefix += user_agent_prefix_;
    user_agent_prefix_ = std::move(prefix);
    return *this;
  }

  std::string const& user_agent_prefix() const { return user_agent_prefix_; }

  grpc::ChannelArguments CreateChannelArguments() const;

 private:
  std::shared_ptr<grpc::ChannelCredentials> credentials_;
  std::string bigquerystorage_endpoint_;
  std::string user_agent_prefix_;
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_CONNECTION_OPTIONS_H_
