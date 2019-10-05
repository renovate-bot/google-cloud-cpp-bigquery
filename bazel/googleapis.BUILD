package(default_visibility = ["//visibility:public"])

load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

cc_proto_library(
    name = "bigquerystorage_cc_proto",
    deps = ["//google/cloud/bigquery/storage/v1beta1:bigquerystorage_proto"],
)

cc_grpc_library(
  name = "grpc_bigquerystorage_proto",
  srcs = ["//google/cloud/bigquery/storage/v1beta1:bigquerystorage_proto"],
  deps = [":bigquerystorage_cc_proto"],
  grpc_only = True,
)

cc_library(
  name = "bigquery_protos",
  deps = [
    ":grpc_bigquerystorage_proto",
    "@com_github_grpc_grpc//:grpc++",
    ],
  includes = ["."],
)

cc_library(
    name = "grpc_utils_protos",
    includes = [
        ".",
    ],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "//google/rpc:status_cc_proto",
    ],
)