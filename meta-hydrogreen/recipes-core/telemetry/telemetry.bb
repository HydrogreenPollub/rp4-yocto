DESCRIPTION = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://telemetry \
    file://src/main.c \
    "

S = "${WORKDIR}/build"

inherit update-rc.d

INITSCRIPT_NAME = "telemetry"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/src/main.c -o ${S}/telemetry
}

do_install() {
    # Install daemon executable
    install -d ${D}${bindir}
    install -m 0755 ${S}/telemetry ${D}${bindir}/

    # Install init script
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/telemetry ${D}${sysconfdir}/init.d/telemetry
}

FILES_${PN} += "${sysconfdir}/init.d/telemetry ${bindir}/telemetry"