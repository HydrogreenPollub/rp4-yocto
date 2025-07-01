The `init-ifupdown_%.bbappend` file overwrites the recipe provided by `poky`.

The purpose of this recipe is to overwrite the network connection of the board.
This allows us to configure the `CAN` interface, as well as to set a `static IP`. 