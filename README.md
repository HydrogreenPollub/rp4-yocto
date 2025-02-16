# yocto-rp4

This repository is a simple embedded linux system being built for the raspberry pi 4 using the yocto build system.

### BUILD
In order to build the `hydrogreen-image` run the following commands
``` bash
# Source bitbake
source poky/oe-init-build-env
# Build the image
bitbake hydrogreen-image
# Upload to sdcard
sudo bmaptool copy tmp/deploy/images/raspberrypi4-64/hydrogreen-image-raspberrypi4-64.rootfs.wic.bz2 /dev/sdc
```