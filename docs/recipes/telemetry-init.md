The `telemetry-init.bb` recipe provides an **rc script** that starts the telemetry application provided by the `telemetry.bb` recipe.

The application is started by an `rc script` we install into `/etc/rc5.d/S99telemetry-init.sh`. This starts the script in `RC Level 5`, which is used for `Multi-user with GUI` systems.