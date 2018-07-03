#!/bin/sh
afl-fuzz -i seed_corpus -o findings -- ./demo-afl @@