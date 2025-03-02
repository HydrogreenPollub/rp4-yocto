The `telemetry.bb` recipe provides a `daemon` written in `C` responsible for receiving the data from all of the peripherals, as well as for sending it to the base station.

It also provides the appropriate **init script**.

The `deamon` is started, by the script we installed into the `/etc/init.d/` directory.