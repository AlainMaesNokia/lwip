#!/bin/bash

while read p; do
  patch -p1 < debian/patches/$p
done < debian/patches/series
