import os
from os import listdir
from os.path import isfile, join

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
        print(x, '!')
        print('./valid/asm' + ' ' + x)
        os.system('./asm' + ' valid/' + x)
        os.system('mv ./valid/' + y +  ' tests/')
        os.system('./valid/asm' + ' valid/' + x)
        print('diff ' + 'valid/'  + x + ' tests/' + x)
        os.system('sudo ' +  'diff ' + 'valid/' + y + ' tests/' + y)
        # os.system('112450.az')
        ans = input()
        if ans:
            print(ans)
    os.system('rm -rf tests/*.cor')


# elif ans == 'v':
#     for x in onlyfiles:
#         if x[-3:] == '.cor':
#             os.system('./corewar' + ' ' + x)






