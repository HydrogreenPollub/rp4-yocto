DESCRIPTION = "Installs scripts for transmitting and receiving data via LoRa"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://lora_transmitter.py \
    file://lora_receiver.py \
    "

S = "${WORKDIR}"

# TODO add python3-pyserial
RDEPENDS:${PN} += "python3-core python3-pyserial"

do_install() {
    install -d ${D}${bindir}

    # Add python3 shebang
    sed -i '1i#!/usr/bin/python3' ${WORKDIR}/lora_transmitter.py
    sed -i '1i#!/usr/bin/python3' ${WORKDIR}/lora_receiver.py

    # Install into binary directory
    install -m 0755 ${WORKDIR}/lora_transmitter.py ${D}${bindir}/lora-transmitter
    install -m 0755 ${WORKDIR}/lora_receiver.py ${D}${bindir}/lora-receiver
}

FILES_${PN} += "${bindir}/lora-transmitter ${bindir}/lora-receiver"