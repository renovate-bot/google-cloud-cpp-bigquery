#ifndef BIGQUERY_VERSION_H_
#define BIGQUERY_VERSION_H_

#include <sstream>
#include <string>

#include "bigquery/version_info.h"
#include "google/cloud/version.h"

#define BIGUQERY_CLIENT_NS                              \
  GOOGLE_CLOUD_CPP_VEVAL(BIGQUERY_CLIENT_VERSION_MAJOR, \
                         BIGQUERY_CLIENT_VERSION_MINOR)

namespace bigquery {

// The inlined, versioned namespace for the client APIs.
//
// Applications may need to link multiple versions of the C++ client,
// for example, if they link a library that uses an older version of
// the client than they do.  This namespace is inlined, so
// applications can use `bigquery::Foo` in their source, but the
// symbols are versioned, e.g., the symbol becomes
// `bigquery::v1::Foo`.
inline namespace BIGUQERY_CLIENT_NS {
int constexpr VersionMajor() { return BIGQUERY_CLIENT_VERSION_MAJOR; }
int constexpr VersionMinor() { return BIGQUERY_CLIENT_VERSION_MINOR; }
int constexpr VersionPatch() { return BIGQUERY_CLIENT_VERSION_PATCH; }

// Returns a single integer representing the major, minor, and patch
// version.
int constexpr Version() {
  return 100 * (100 * VersionMajor() + VersionMinor()) + VersionPatch();
}

// Returns the version as a string in the form `MAJOR.MINOR.PATCH`.
std::string VersionString() {
  static std::string const kVersion = []() {
    std::ostringstream os;
    os << "v" << VersionMajor() << "." << VersionMinor() << "."
       << VersionPatch();
    return os.str();
  }();
  return kVersion;
}

}  // namespace BIGUQERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_VERSION_H_
