DESCRIPTION = "RaspberryPi 4 Hydrogreen Packagegroup"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit packagegroup

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "^rpi$"

RDEPENDS:${PN} = "\
    can-utils \
    dropbear \
    libgpiod \
    lora \
    packagegroup-rpi-test \
    rust-demo \
    screen \
    telemetry \
"