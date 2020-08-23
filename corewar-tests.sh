make
if [ $? -ne 0 ]
then
  printf "ERROR!! Makefile build failed!\n"
  exit 1
fi
./asm helltrain.s
if [ $? -ne 0 ]
then
  printf "ERROR!! ASM run failed!\n"
  exit 1
fi
./corewar helltrain.cor helltrain.cor
if [ $? -ne 0 ]
then
  printf "ERROR!! corewar run failed!\n"
  exit 1
fi

#Не рабочий тест. Гитлаб не может его выполнить
#./corewar -curses helltrain.cor helltrain.cor
#if [ $? -ne 0 ]
#then
#  printf "ERROR!! corewar visual run failed!\n"
#  exit 1
#fi

printf "WOW!! all tests passed!! Congrats!\n"
exit 0
