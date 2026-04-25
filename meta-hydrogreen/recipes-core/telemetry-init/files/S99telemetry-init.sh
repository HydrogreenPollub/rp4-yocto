#!/bin/sh

LOGDIR="/home/root/logs"

# Sync system clock from DS3231 RTC before anything else
hwclock -s

TIMESTAMP=$(date +%Y%m%d_%H%M%S)
LOGFILE="$LOGDIR/telemetry_$TIMESTAMP.log"

# Create the log directory if it doesn't exist
mkdir -p "$LOGDIR"

# Run telemetry with output redirected to the log file
# `setsid` allows it to run detached from the terminal
(telemetry >> "$LOGFILE" 2>&1) &

exit 0