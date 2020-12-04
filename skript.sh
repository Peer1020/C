#!/bin/bash
for F in `ls *.c 2>/dev/null`; do
if [ -f "$F" ]; then
echo "$F"
fi
done 
