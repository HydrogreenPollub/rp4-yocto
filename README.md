# rp4-yocto

This repository is a simple embedded linux system being built for the raspberry pi 4 using the yocto build system.

### BUILD
There are two image targets:
- `hydrogreen-image` — release, lightweight
- `hydrogreen-image-debug` — includes on-device build tools (cmake, gdb, git) for CLion remote development

``` bash
# Source bitbake
source poky/oe-init-build-env
# Build release image
bitbake hydrogreen-image
# Build debug image (larger, includes dev tools)
bitbake hydrogreen-image-debug
# Upload to sdcard
sudo bmaptool copy tmp/deploy/images/raspberrypi4-64/hydrogreen-image-raspberrypi4-64.rootfs.wic.bz2 <sdcard_device_file>
```

**Ubuntu / Mint**

Not supported by the yocto project and needs an additional fix before compiling:
```
sudo apparmor_parser -R /etc/apparmor.d/unprivileged_userns
```

### FIRST BOOT — RTC SETUP
On first boot the RTC has no time set. SSH in and set it once:
``` bash
date -s "YYYY-MM-DD HH:MM:SS"
hwclock -w
```
After this the time is preserved across power cycles.

### PROJECT OVERVIEW
The goal of the project is to collect vehicle data via `can` and `rs485`.
After that we send the data to the base station via `lora`. This is done using a program called [telemetry](https://github.com/HydrogreenPollub/rp4-telemetry).

### DOCUMENTATION
The project documentation is written in `Markdown` and can be viewed using `mkdocs` with the following commands:
``` bash
pip install mkdocs
mkdocs serve
```

It is also documented as part of an engineering degree publication under `docs/latex/`.
This can be built using the `build.sh` script after installing the right latex dependencies.
