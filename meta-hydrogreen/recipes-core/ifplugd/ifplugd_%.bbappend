FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://ifplugd"

do_install:append() {
    install -d ${D}${sysconfdir}/default
    install -m 0644 ${WORKDIR}/ifplugd ${D}${sysconfdir}/default/ifplugd
}

FILES:${PN} += "${sysconfdir}/default/ifplugd"
