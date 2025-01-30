SUMMARY = "A custom image for rp-4"

IMAGE_INSTALL += "lora"
IMAGE_FEATURES += "ssh-server-dropbear"

LICENSE = "MIT"

inherit core-image
inherit extrausers

# Set filesystem size to 200MB
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"
IMAGE_FSTYPES += "wic wic.gz"

# Change root user password
#EXTRA_USERS_PARAMS = "\
#    usermod -P 'toor' root \
#    "