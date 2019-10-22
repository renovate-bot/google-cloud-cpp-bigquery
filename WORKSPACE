workspace(name = "com_github_googleapis_google_cloud_cpp_bigquery")

load("//bazel:google_cloud_cpp_bigquery_deps.bzl", "google_cloud_cpp_bigquery_deps")

google_cloud_cpp_bigquery_deps()

# Configure @com_google_googleapis to only compile C++ and gRPC libraries.
load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,  # C++ support is only "Partially implemented", roll our own.
    grpc = True,
)

# Have to manually call the corresponding function for google-cloud-cpp and
# gRPC:
#   https://github.com/bazelbuild/bazel/issues/1550

load("@com_github_googleapis_google_cloud_cpp_common//bazel:google_cloud_cpp_common_deps.bzl", "google_cloud_cpp_common_deps")

google_cloud_cpp_common_deps()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

# Call the workspace dependency functions defined, but not invoked, in grpc_deps.bzl.
load("@upb//bazel:workspace_deps.bzl", "upb_deps")

upb_deps()

load("@build_bazel_rules_apple//apple:repositories.bzl", "apple_rules_dependencies")

apple_rules_dependencies()

load("@build_bazel_apple_support//lib:repositories.bzl", "apple_support_dependencies")

apple_support_dependencies()
