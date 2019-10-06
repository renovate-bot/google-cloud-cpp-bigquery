#include "bigquery/version.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
std::string VersionString() {
  static std::string const kVersion = []() {
    std::ostringstream os;
    os << "v" << VersionMajor() << "." << VersionMinor() << "."
       << VersionPatch();
    return os.str();
  }();
  return kVersion;
}

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
