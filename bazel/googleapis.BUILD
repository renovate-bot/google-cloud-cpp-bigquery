# Copyright 2019 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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