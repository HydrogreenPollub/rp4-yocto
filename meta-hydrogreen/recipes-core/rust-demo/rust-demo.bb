SUMMARY = "rust-demo"
DESCRIPTION = "A sample rust project built with yocto"
HOMEPAGE = "https://hydrogreen.pl"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit cargo

SRC_URI = " \
    file://Cargo.toml \
    file://Cargo.lock \
    file://src/ \
    crate://crates.io/libc/0.2.170 \
    crate://crates.io/termios/0.3.3 \
"

SRC_URI[libc-0.2.170.sha256sum] = "875b3680cb2f8f71bdcf9a30f38d48282f5d3c95cbf9b3fa57269bb5d5c06828"
SRC_URI[termios-0.3.3.sha256sum] = "411c5bf740737c7918b8b1fe232dca4dc9f8e754b8ad5e20966814001ed0ac6b"

S = "${WORKDIR}"