DESCRIPTION = "Expand root partition to fill SD card on first boot"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://S02resize-rootfs.sh"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${sysconfdir}/rc5.d
    install -m 0755 ${WORKDIR}/S02resize-rootfs.sh ${D}${sysconfdir}/rc5.d/S02resize-rootfs.sh
}
