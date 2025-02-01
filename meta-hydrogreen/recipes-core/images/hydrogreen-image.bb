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

# Rp4 specific changes
# TODO fix settings not being applied to config.txt
ENABLE_I2C = "1"
RPI_EXTRA_CONFIG = " \
    disable_splash=1 \
    max_usb_current=1 \
    "