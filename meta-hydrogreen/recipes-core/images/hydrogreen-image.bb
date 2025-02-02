SUMMARY = "A custom image for rp-4"

LICENSE = "MIT"
COMPATIBLE_MACHINE = "^rpi$"

IMAGE_INSTALL:append = " packagegroup-rpi-test lora"
IMAGE_FEATURES += "ssh-server-dropbear"

inherit core-image
inherit extrausers

# Set filesystem size to 200MB
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

# Change root user password
#EXTRA_USERS_PARAMS = "\
#    usermod -P 'toor' root \
#    "