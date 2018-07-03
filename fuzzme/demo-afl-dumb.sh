#!/bin/sh
afl-fuzz -n -i seed_corpus -o findings -- ./demo-afl @@
