#!/bin/bash
set -e

remote=${1:-htwk_imunix_perf}

uuid=""
if [ -f /proc/sys/kernel/random/uuid ]
then
    uuid=$(cat /proc/sys/kernel/random/uuid)
elif [ -x $(which uuidgen) ]
then
    uuid=$(uuidgen)
else
    echo "Cannot create uuid (used for cloning repo on remote). Neither 'uuidgen' nor '/proc/sys/kernel/random/uuid' are available."
    exit 1
fi

if [ -f ./build ]
then
    echo "Back up ./build to ./build~"
    mv build build~
fi

trap 'ssh -t "$remote" "rm -rf /tmp/$uuid"' EXIT

echo "Building project at $remote:/tmp/$uuid"

ssh -t "$remote" "pushd /tmp && git clone https://github.com/herrmanno/C827-rechnerarchitektur.git $uuid && pushd $uuid && bash build.sh && bash perf.sh"

echo "Build succeeded"
echo "Downloading artefacts"

scp -r "$remote:/tmp/$uuid/build/*" "./build/"

echo "Downloading artefacts succeeded"

echo "Removing remote directory"

ssh -t "$remote" "rm -rf /tmp/$uuid"

echo "Remote directory removed"

exit 0
