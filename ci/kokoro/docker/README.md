# Manually Running Continuous Integration Workflows

This guide will walk you through kicking off one of the continuous integration
workflows locally. We will first build a Docker image. Then, we will kick off
one of the workflows.

For simplicity, we assume the reader is on an Ubuntu workstation, though these
instructions can easily be adapted for other environments.

We will be using the Ubuntu Docker image and will kick of the "address
sanitizer" Bazel build. The instructions can be used for running other workflows
on different Docker images with minor modifications.

## Set Up

Install Docker:

```bash
sudo apt update && sudo apt install docker.io
```

## Build the Docker Image

From this repository's root, build the Docker image with all the development
tools needed to run the build.  You only need to do this once in your
workstation:

```bash
cd ci
sudo docker build . \
  --file kokoro/docker/Dockerfile.ubuntu \
  --tag gcpp-ci-ubuntu-18.04:latest
```

If you make changes to the Dockerfile, be sure to rebuild the image.

## Launch the Workflow

Run the CI build script. This compiles and tests the code just like the CI
system does:

```bash
ci/kokoro/docker/build.sh asan
```
