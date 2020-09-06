# CoreWar

Проект CoreWar Школы 21 от Сбербанк

Цель проекта - написать ассемблер для игры CoreWar, а так же виртуальную машину для запуска игры. Более подробную информацию см. в файле [sbj/11_corewar.en.pdf](sbj/11_corewar.en.pdf).

На данный момент выполнено:
- [x] Ассемблер (100% завершено)
- [x] Виртуальная машина (100% завершено)
- [x] Визуализация (100% завершено)
- [ ] Дизассемблер?

Чтобы запустить программу, сперва выполните `make`.    
<details>
 <summary>Дополнительные параметры компиляции</summary>

 <code>make d</code> or <code>make debug</code> or <code>make DEBUGMODE=1</code> - собрать проект в режиме дебага

 <code>make rd</code> or <code>make redebug</code> or <code>make re DEBUGMODE=1</code> - пересобрать проект принудительно в режиме дебага (все файлы будут пересобраны заново)    
</details>

Чтобы запустить ассемблер, воспользуйтесь командой
```
./asm FILENAME
```
где `FILENAME` - файл в формате `.s`, содежащий исходный код Вашего чемпиона. Программа конвертирует его в файл `.cor`, необдимый для игры. Более подробно об этих файлах Вы можете узнать в файле [sbj/11_corewar.en.pdf](sbj/11_corewar.en.pdf).

Чтобы запустить виртуальную машину, выполните команду
```
./corewar [-d N -v N] [[-n number] <champion1.cor> <...>]
```
где `champion1.cor` - файл чемпиона в фломате `.cor`. Таких файлов может быть от одного до четырех (по умолчанию)    

<details>
 <summary>Дополнительные флаги виртуальной машины</summary>

 <ui>
  <li><code>-n N, -number N </code> - установить номер игрока, где N - число от 1 до 4 (при игре с 4 игроками). По умолчанию используется порядковый номер</li>
  <li><code>-d N, -dump N</code> - остановить игру после N циклов и сделать дамп памяти</li>
  <li><code>-v N</code> - переключить уровень печати, где N:
  <ul>
   <li>0 - Показать только представление кандидатов и сообщение о победе</li>
   <li>1 - Показать lives</li>
   <li>2 - Показать циклы</li>
   <li>4 - Показать операции</li>
   <li>8 - Показать смерти</li>
  </ul>
  (По умолчанию установлено 0)
  </li>
  <li><code>-curses</code> - запустить в режиме Ncurses (визуализация)</li>
 </ui>
</details>
Этот проект делали   

< credits >

2020 Moscow, Russia