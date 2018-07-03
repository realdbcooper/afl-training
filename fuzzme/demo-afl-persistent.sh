#!/bin/sh
AFL_USE_ASAN=1 afl-fuzz -m none -i seed_corpus -o foo ./demo-afl-persistent
