# rp4-yocto

This repository is a simple embedded linux system being built for the raspberry pi 4 using the yocto build system.

### BUILD
In order to build the `hydrogreen-image` run the following commands:
``` bash
# Source bitbake
source poky/oe-init-build-env
# Build the image
bitbake hydrogreen-image
# Upload to sdcard
sudo bmaptool copy tmp/deploy/images/raspberrypi4-64/hydrogreen-image-raspberrypi4-64.rootfs.wic.bz2 <sdcard_device_file>
```

**Ubuntu**
`Ubuntu` is not supported by the yocto project and needs an additional fix before compiling
```
sudo apparmor_parser -R /etc/apparmor.d/unprivileged_userns
```

### PROJECT OVERVIEW
The goal of the project is to collect vehicle data via `can` and `rs485`.
After that we send the data to the base station via `lora`. This is done using a program called `telemetry`.

### DOCUMENTATION
The project documentation is written in `Markdown` and can be viewed using `mkdocs` with the following commands:
``` bash
pip install mkdocs
mkdocs serve
```
