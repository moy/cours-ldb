      .section .data
un:   .int 1
...     ...
      .section .bss
      .lcomm tab,10
tab1: skip 10
---
      .text
main: pushl %ebp
	
