DESCRIPTION = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/HydrogreenPollub/rp4-telemetry.git;branch=main;protocol=https"
SRCREV = "23931541ba502774940bc466305fc9afd3ba51ab"

S = "${WORKDIR}/git"

DEPENDS += " libgpiod"
RDEPENDS_${PN} += "libgpiod"

inherit update-rc.d

INITSCRIPT_NAME = "telemetry"

inherit cmake

do_install:append() {
    # Install init script
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/telemetry ${D}${sysconfdir}/init.d/telemetry
}