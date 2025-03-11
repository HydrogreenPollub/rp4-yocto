DESCRIPTION = "Init script to run the telemetry daemon"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://telemetry"
S = "${WORKDIR}"

DEPENDS += " telemetry"
RDEPENDS_${PN} += " telemetry"

inherit update-rc.d

INITSCRIPT_NAME = "telemetry"

do_install() {
    # Install init script
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/telemetry ${D}${sysconfdir}/init.d/telemetry
}