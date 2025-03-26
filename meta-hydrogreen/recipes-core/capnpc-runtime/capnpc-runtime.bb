DESCRIPTION = "Runtime library for capnp-c"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://gitlab.com/dkml/ext/c-capnproto.git;branch=main;protocol=https"
SRCREV = "659461cd3a216c10f3bbe7886e7c53ab39d690dd"

S = "${WORKDIR}/git"

inherit cmake

INSANE_SKIP_${PN} += " ldflags"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_SYSROOT_STRIP = "1"
SOLIBS = ".so"
FILES_SOLIBSDEV = ""

EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=${prefix} -DBUILD_TESTING=OFF"

FILES_${PN} += "/usr/lib/libCapnC_Runtime.so"
