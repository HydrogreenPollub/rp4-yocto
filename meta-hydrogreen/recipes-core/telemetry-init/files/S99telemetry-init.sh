#!/bin/sh

TIMESTAMP=$(date +%Y%m%d_%H%M%S)
LOGDIR="/home/root/logs"
LOGFILE="$LOGDIR/telemetry_$TIMESTAMP.log"

# Create the log directory if it doesn't exist
mkdir -p "$LOGDIR"

# Run telemetry with output redirected to the log file
# `setsid` allows it to run detached from the terminal
(telemetry >> "$LOGFILE" 2>&1) &

exit 0