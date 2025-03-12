The `telemetry.bb` recipe provides an application written in `C` responsible for receiving the data from all of the peripherals, as well as for sending it to the base station.

The source code of this application is stored in a [separate repository](https://github.com/HydrogreenPollub/rp4-telemetry).

Logs from the application are stored in `var/log/telemetry.log`.

The application is multithreaded and features a watchdog. Each peripheral has a separate thread. All of the **input** threads save their data to shared data structure, which is then transmitted by the **output** threads.