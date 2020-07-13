import os
from os import listdir
from os.path import isfile, join
import sys

cmd = 'ls'
os.system(cmd)

print('chose path')
mypath = input()
print(mypath)
for x in listdir(mypath):
    print(x, isfile(join(mypath,x)))
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
print('assemble or vm(chose a or v)')
ans = input()
if ans == 'a':
    cors = [y[:-2] + '.cor'  for y in onlyfiles if y[-2:] == '.s']
    sources = [x for x in onlyfiles if x[-2:] == '.s']
    for x, y in zip(sources, cors):
        os.system('./asm' + ' ' + mypath + x)
        os.system('mv ' + mypath + y +  ' tests/')
        os.system(mypath + 'asm' + ' ' + mypath + x)
        print('diff ' + mypath  + y + ' tests/' + y)
        os.system('diff ' + mypath + y + ' tests/' + y)






