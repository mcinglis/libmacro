#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset

path_to_name() {
    local x="${1%.*}"
    local y="${x##*/}"
    echo "$y"
}

main() {
    local dir="$(dirname "$0")"
    for src in "$dir/"*.c; do
        run_test "$dir" "$(path_to_name "$src")"
    done
}

run_test() {
    local dir="$1"
    local name="$2"
    if ( diff <($dir/$name 2>&1) "$dir/${name}.out" ); then
        echo "pass: $name"
    else
        echo "fail: $name"
        false
    fi
}

main "$@"

