# Remove zeroconf from packagegroup-base, so that we aren't including avahi in our build
RDEPENDS:packagegroup-base:remove = "packagegroup-base-zeroconf"