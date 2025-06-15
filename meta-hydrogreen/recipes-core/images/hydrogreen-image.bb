SUMMARY = "A custom image for rp-4"

LICENSE = "MIT"
COMPATIBLE_MACHINE = "^rpi$"

# TODO remove wpa_supplicant, since we aren't using wifi
# TODO remove bluetoothd, since we aren't using it
# TODO remove canutils and lora recipes once done with prototyping
# TODO set device file names statically using udev

IMAGE_INSTALL:append = " packagegroup-hydrogreen"
IMAGE_FEATURES:append = " x11-base allow-root-login"
IMAGE_FEATURES:remove = "package-management splash"

inherit core-image

# Set filesystem size to 200MB
IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

# Change root user password to "root" - required for ssh login
inherit extrausers
EXTRA_USERS_PARAMS = "usermod -p '\$6\$1oDk0l/RyCvNOwKl\$BegMi7xD58b1wYOgH9ILXGFRQRZgnDmfC2XS9DN8T/aHldOaoTUQ7S5aVdxFFHFbP9hmr7fjJaXdmrPqGfvcD1' root;"