#include "bigquery/client.h"

int main(int argc, char* argv[]) {
  bigquery::Client client(bigquery::MakeConnection());
  google::cloud::StatusOr<std::string> res = client.CreateSession("my-table");

  if (res.ok()) {
    std::cout << "Session name: " << res.value();
    return EXIT_SUCCESS;
  } else {
    std::cerr << "Session creation failed with error: " << res.status() << "\n";
    return EXIT_FAILURE;
  }
}
