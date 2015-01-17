#!/bin/bash

set -o errexit
set -o pipefail
set -o nounset

main() {
    local dir="$(dirname "$0")"
    run_test "$dir" alloc
    run_test "$dir" assert
    run_test "$dir" debug
    run_test "$dir" logic
    run_test "$dir" minmax
    run_test "$dir" nelem
    run_test "$dir" require
    run_test "$dir" slice
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

