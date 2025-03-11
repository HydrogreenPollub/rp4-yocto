DESCRIPTION = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/HydrogreenPollub/rp4-telemetry.git;branch=main;protocol=https"
SRCREV = "82dcbdfbef0f2b2fc2e82dc991fd07ec61c1eb8b"

S = "${WORKDIR}/git"

DEPENDS += " libgpiod"
RDEPENDS_${PN} += "libgpiod"

inherit cmake

do_install() {
    # Install the executable
    install -d ${D}${bindir}
    install -m 0755 ${B}/telemetry ${D}${bindir}
}