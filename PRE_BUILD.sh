#!/bin/sh
filename="$1";
fd="${filename%%_*}";
cp -fr "${0%/*}/.cache/catalog/src_${fd}*/src/include/SDL3" "${0%/*}/source/SDL3";
