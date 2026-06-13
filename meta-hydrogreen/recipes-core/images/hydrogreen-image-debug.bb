SUMMARY = "Debug image with development tools for on-device compilation"

require recipes-core/images/hydrogreen-image.bb

IMAGE_FEATURES:append = " tools-sdk dev-pkgs"

IMAGE_INSTALL:append = " cmake gdb git rsync openssh-sftp-server tar"

# dev-pkgs does not always pull -dev headers for transitive runtime deps (telemetry)
IMAGE_INSTALL:append = " capnproto-dev libgpiod-dev boost-dev"
