DESCRIPTION = "Init script to run the telemetry daemon"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://S99telemetry-init.sh"
S = "${WORKDIR}"

DEPENDS += " telemetry"
RDEPENDS_${PN} += " telemetry"

do_install() {
    # Install init script
    install -d ${D}${sysconfdir}/rc5.d
    install -m 0755 ${WORKDIR}/S99telemetry-init.sh ${D}${sysconfdir}/rc5.d/S99telemetry-init.sh
}