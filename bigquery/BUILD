package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bigquery_client",
    hdrs = [
      "client.h",
      "connection.h",
    ],
    srcs = [
      "client.cc",
      "internal/bigquery_read_stub.cc",
      "internal/bigquery_read_stub.h",
      "internal/connection_impl.cc",
      "internal/connection_impl.h",
    ],
    deps = [
        "@com_github_googleapis_google_cloud_cpp//google/cloud:google_cloud_cpp_common",
	"@com_google_googleapis//:bigquery_protos",
    ],

)
