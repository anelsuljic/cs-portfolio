func mewIF(A: array[10] of int,
           B: array[10] of float) : float
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

func mewFI(A: array[10] of float,
           B: array[10] of int) : float
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
   var A: array [10] of int
   var X: array [10] of float

   read n;
   while n!=999 do
       i = 0;
       while i<10 do read A[i]; i=i+1;
       endwhile
       i = 0;
       while i<10 do read X[i]; i=i+1;
       endwhile
	
       if A << X then
          write "A smaller than X\n";
       else if X << A then
          write "A is bigger than X\n";
       else
          write "A and X are equal\n";
       endif
       endif

       write mewIF(A,X); write "\n";
       write mewFI(X,A); write "\n";
      
       read n;
   endwhile
endfunc
