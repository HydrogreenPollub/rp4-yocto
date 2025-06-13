DESCRIPTION = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "gitsm://github.com/HydrogreenPollub/rp4-telemetry.git;protocol=https;branch=main"
SRCREV = "${AUTOREV}"
PV = "1.0+git"

S = "${WORKDIR}/git"

DEPENDS += " \
    libgpiod (= 2.1.2) \
    capnproto (= 1.1.0) \
    boost"
RDEPENDS_${PN} += " \
    libgpiod (= 2.1.2) \
    capnproto (= 1.1.0) \
    boost"

inherit cmake

# Enable debug symbols
TARGET_CFLAGS += "-g"
# EXTRA_OECMAKE="-DCONFIG_GPS_9600=1" # Defines which GPS we're using

do_install() {
    # Install the executable
    install -d ${D}${bindir}
    install -m 0755 ${B}/telemetry ${D}${bindir}
}
