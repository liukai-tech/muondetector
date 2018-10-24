#!/bin/bash
rm dependencies.tmp 2> /dev/null
objdump -p $1 | grep NEEDED | awk '{print $2}' >> dependencies.tmp
rm packages.tmp 2> /dev/null
wait
while read p; do
dpkg -S $p | awk '{print $1}' >> packages.tmp 
done < dependencies.tmp
rm packages-dev.tmp 2> /dev/null
wait
cat packages.tmp | sed -n '/-dev/p' >> packages-dev.tmp
