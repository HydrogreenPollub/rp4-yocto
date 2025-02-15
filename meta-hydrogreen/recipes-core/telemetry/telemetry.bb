SUMMARY = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://main.c"

S = "${WORKDIR}/build"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/main.c -o ${S}/telemetry
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/telemetry ${D}${bindir}/
}