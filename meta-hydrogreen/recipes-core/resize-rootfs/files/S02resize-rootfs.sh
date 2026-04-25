#!/bin/sh

FLAGFILE="/etc/rootfs-resized"

[ -f "$FLAGFILE" ] && exit 0

parted -s /dev/mmcblk0 resizepart 2 100%
partx -u /dev/mmcblk0
resize2fs /dev/mmcblk0p2

touch "$FLAGFILE"
