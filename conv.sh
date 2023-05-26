#!/bin/bash

for file in *.h; do
    vim -c "set ff=unix" -c "wq" "$file"
done
