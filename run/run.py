#!/bin/env python3

import sys
import subprocess
import os.path


if len(sys.argv) != 2:
    sys.exit("few or too many arguments\nUsage:\n\t$ ./run.py <filename>")

compile_cmd = "g++ -std=c++17 -Wshadow -Wall -o {} {} -O2 -Wno-unused-result"
build_cmd = 'g++ -std=c++17 -Wshadow -Wall -o {} {} -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG'

filename = sys.argv[1]
if not os.path.exists(filename):
    sys.exit("Make sure file {} exists in this directory".format(filename))

parts = filename.split('.')
if len(parts) < 2:
    sys.exit("Invalid filename {}".format(filename))

basename = ".".join(parts[:-1])
ext = parts[-1]

if ext in ["cpp", "cc", "cxx"]:
    infile = "in" + basename
    if not os.path.exists(infile):
        sys.exit("Make sure input file {} exists in this directory".format(infile))

    cmd = build_cmd.format(basename, filename).split()
    subprocess.run(cmd)
    subprocess.run(["/bin/sh", "-c", "./{} < {}".format(basename, infile)])

sys.exit(1)
