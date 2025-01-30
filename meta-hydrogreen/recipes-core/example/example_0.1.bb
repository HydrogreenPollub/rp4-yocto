SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "example recipe"

LICENSE = "MIT"

python do_display_banner() {
    bb.plain("============================");
    bb.plain("=          Hello!          =");
    bb.plain("============================");
}

addtask display_banner before do_build