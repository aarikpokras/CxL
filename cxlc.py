#!/usr/bin/env python3
import subprocess as s
import os
import sys
import re

argv = sys.argv

filename = re.sub("\\..*", "", argv[1])

code = []
tp_file = []

with open(argv[1], 'r') as f:
  str_w = f.readlines()

for i in str_w:
  if (i.startswith("use")):
    module = i.replace("use@", "").replace("*!", "")
    f_module = module.replace("\n", "")
    tp_file.append(i.replace(f_module, "").replace("use@", "#include \"" + f_module + ".cxlbund/" + f_module + ".h").replace("*!", "\""))
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
    module = i.replace("use@", "").replace("*!", "")
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