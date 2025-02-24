SUMMARY = "A custom image for rp-4"

LICENSE = "MIT"
COMPATIBLE_MACHINE = "^rpi$"

# TODO check if gpiod works and if it does, use it for rs485 setup
IMAGE_INSTALL:append = " packagegroup-rpi-test lora can-utils screen libgpiod telemetry"
IMAGE_FEATURES += "ssh-server-dropbear"

# TODO Fix avahi overwriting static ip
# For some reason avahi overwrites our static IP address, with its own link-local address
# There doesn't seem to be any information on changing its default address
# One solution might be to remove avahi from our build, since we're using static IP anyways.
# This however will require us to change the meta-raspberrypi layer to not include the packagegroup-base-zeroconf

inherit core-image
inherit extrausers

# Set filesystem size to 200MB
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

# Change root user password
#EXTRA_USERS_PARAMS = "\
#    usermod -P 'toor' root \
#    "