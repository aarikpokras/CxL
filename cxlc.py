#!/usr/bin/env python3
# import subprocess as s
import os
import sys
import re
import random

argv = sys.argv

if (len(argv) == 1):
  print(argv[0] + ": \033[1;37mError:\033[1;31m No input file passed\033[0m")
  sys.exit(1)

filename = re.sub("\\..*", "", argv[1])

code = []
tp_file = []

if (argv[1] != "--moo"):
  with open(argv[1], 'r') as f:
    str_w = f.readlines()
else:
  with open('lib/cow/config.txt', 'r') as f:
    ch = f.readlines()
    item = random.choice(ch)
    print(item)
    print("        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )N\n                ||----w |\n                ||     ||\n")
    sys.exit(0)

for i in str_w:
  if (i.startswith("use")):
    module = i.replace("use@", "")
    f_module = module.replace("\n", "")
    tp_file.append(i.replace(f_module, "").replace("use@", "#include \"" + f_module + ".cxlbund/" + f_module + ".h").replace("\n", "\"\n"))
  else:
    code.append(i)

with open(argv[1], 'w') as f:
  for i in tp_file:
    f.write(i)
  for i in code:
    f.write(i)

compre = "g++ -x c++ "

whatf = []

for i in str_w:
  if (i.startswith("use")):
    module = i.replace("use@", "")
    whatf.append(module.strip())

"""
move
"""

for i in whatf:
  os.system("cp -r lib/" + i + ".cxlbund .")
  compre += i + ".cxlbund/" + i + ".cpp "

compre += argv[1] + " -o " + filename

print(compre)

os.system(compre + " -std=c++17")

"""
change back
"""

includes = []
includes_rep = []
code_w = []
incs_raw = []

with open(argv[1], 'r') as f:
  w_ph = f.readlines()
  for i in w_ph:
    if (i.startswith("#include")):
      inc_ = i.replace("#include \"", "").replace("\"", "")
      inc = re.sub(".cxlbund.*", "", inc_)
      includes.append("use@" + inc)
      incs_raw.append(inc.strip())
    else:
      code_w.append(i)

with open(argv[1], 'w') as f:
  for i in includes:
    f.write(i)
  for i in code_w:
    f.write(i)

"""
destroy local cxlbunds
"""

for i in incs_raw:
  os.system("rm -r " + i + ".cxlbund")
