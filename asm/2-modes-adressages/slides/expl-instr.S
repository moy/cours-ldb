iter:  cmpw $0,%ax  /* compare word */
       je   fin     /* jump if equal */
       shrw $1,%ax  /* shift right word */
       jnc  suite   /* jump if no carry */
       add  %dx,%ax /* add */
suite: shlw $1,%dx  /* shift left word */
       jmp  iter    /* jump inconditionnel */
fin:
