DESCRIPTION = "Scripts for transmitting and receiving data via LoRa"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
    file://lora_transmitter.py \
    file://lora_receiver.py \
    "

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/lora_transmitter.py ${D}${bindir}/lora-transmitter
    install -m 0755 ${WORKDIR}/lora_receiver.py ${D}${bindir}/lora-receiver
}

FILES_${PN} += "${bindir}/lora-transmitter ${bindir}/lora-receiver"