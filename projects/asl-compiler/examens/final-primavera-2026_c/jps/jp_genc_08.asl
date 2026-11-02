func mew (A: array[10] of float,
          B: array[15] of int) : float
    var i: int
    i = 0;
    while i<10 and A[i]<B[i] do
        write A[i];
        write " ";
        i = i+1;
    endwhile
    write " --\n";
    if i==10 then i=0; endif
    return A[i] + B[i];
endfunc

func main()
   var i,j,n: int
   var b: bool
   var A,B: array [15] of int
   var X: array [10] of float

   read n;
   while n!=999 do
       i = 0;
       while i<15 do read A[i]; i=i+1;
       endwhile
       i = 0;
       while i<10 do read X[i]; i=i+1;
       endwhile

       if A << X then
          write "A smaller than B\n";
       else if X << A then
          write "A is bigger than B\n";
       else
          write "A and B are equal\n";
       endif
       endif

       B = A;
       write A << B; write "\n";
       write B << X; write "\n";
       write not (B << X or X << B);
       write "\n";
       write mew(X,B); write "\n";
       
       read n;
   endwhile
endfunc
