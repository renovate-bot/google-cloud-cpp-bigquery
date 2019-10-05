package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bigquery_client",
    hdrs = [
      "client.h",
      "connection.h",
    ],
    srcs = [
      "client.cc",
      "internal/connection_impl.h",
      "internal/connection_impl.cc",
    ],
    deps = [
        "@com_github_googleapis_google_cloud_cpp//google/cloud:google_cloud_cpp_common",
    ],

)
