SUMMARY = "A custom image for rp-4"

LICENSE = "MIT"
COMPATIBLE_MACHINE = "^rpi$"

# TODO check if gpiod works and if it does, use it for rs485 setup
# TODO remove wpa_supplicant, since we aren't using wifi
# TODO remove bluetoothd, since we aren't using it
# TODO figure out why static IP isn't being applied
# TODO remove gdb once done with debugging
# TODO use cmdline.txt to remove lora from tty list (to not send garbage on boot)

IMAGE_INSTALL:append = " packagegroup-hydrogreen gdb"
IMAGE_FEATURES:remove = "package-management splash"

inherit core-image
inherit extrausers

# Set filesystem size to 200MB
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

# Change root user password
#EXTRA_USERS_PARAMS = "\
#    usermod -P 'toor' root \
#    "