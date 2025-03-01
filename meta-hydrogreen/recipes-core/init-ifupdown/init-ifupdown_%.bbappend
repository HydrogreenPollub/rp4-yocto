FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://assign-ip-eth0.sh"

do_install:append() {
    install -m 0755 ${WORKDIR}/assign-ip-eth0.sh ${D}${sysconfdir}/network/if-up.d/
}

RDEPENDS:${PN} += "bash"