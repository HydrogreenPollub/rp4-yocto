DESCRIPTION = "Application to monitor the vehicle state and transmit the data to base station"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://telemetry \
    file://src/main.c \
    file://src/can.c \
    file://src/can.h \
    file://src/log.c \
    file://src/log.h \
    file://src/lora.c \
    file://src/lora.h \
    "

S = "${WORKDIR}/build"

inherit update-rc.d

INITSCRIPT_NAME = "telemetry"

# Avoid referencing TMPDIR
CFLAGS += "-fdebug-prefix-map=${TMPDIR}=."

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/src/main.c ${WORKDIR}/src/can.c ${WORKDIR}/src/log.c ${WORKDIR}/src/lora.c -o ${S}/telemetry
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