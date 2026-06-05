#!/bin/sh
cd "${0%/*}";
chmod u+x "./filedialogs/build.sh";
if [ `uname` = "Darwin" ]; then
  sudo xcode-select --install;
  if [ -f "/opt/local/bin/port" ]; then
    "./filedialogs/build.sh";
  else
    echo "MacPorts installation not found! Please download and install MacPorts first from www.macports.org";
  fi;
else
  "./filedialogs/build.sh";
fi;
