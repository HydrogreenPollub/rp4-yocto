#!/bin/sh

LOGDIR="/home/root/logs"

# Sync system clock from DS3231 RTC before anything else
hwclock -s

mkdir -p "$LOGDIR"

TIMESTAMP=$(date +%Y%m%d_%H%M%S)

n=0
for f in "$LOGDIR"/logs_*.log; do
    [ -f "$f" ] || continue
    num=${f##*/logs_}
    num=${num%%_*}
    case "$num" in
        ''|*[!0-9]*) continue ;;
    esac
    [ "$num" -gt "$n" ] && n=$num
done
n=$((n + 1))

LOGFILE="$LOGDIR/logs_${n}_${TIMESTAMP}.log"

(telemetry >> "$LOGFILE" 2>&1) &

exit 0
