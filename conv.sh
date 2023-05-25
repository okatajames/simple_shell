#!/bin/bash

for file in *.c; do
    vim -c "set ff=unix" -c "wq" "$file"
done
