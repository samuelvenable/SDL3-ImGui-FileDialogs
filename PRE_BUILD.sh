#!/bin/sh
sh -c "cd \"${0%/*}/.cache/catalog/src_*/src/include\" && cp -fr \"SDL3\" \"${0%/*}/source/SDL3\"";
