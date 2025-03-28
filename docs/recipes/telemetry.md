The `telemetry.bb` recipe provides an application written in `C` responsible for receiving the data from all of the peripherals, as well as for sending it to the base station.

The source code of this application is stored in a [separate repository](https://github.com/HydrogreenPollub/rp4-telemetry).

Logs from the application are stored in `/var/log/telemetry.log`.

The application is multithreaded and features a watchdog. Each peripheral has a separate thread. All of the **input** threads save their data to shared data structure, which is then serialized to a **flatbuffer** and transmitted by the **output** threads.

The **flatbuffer** library that we settled on is a fork of **cap'n proto** called [c-capnproto](https://gitlab.com/dkml/ext/c-capnproto)