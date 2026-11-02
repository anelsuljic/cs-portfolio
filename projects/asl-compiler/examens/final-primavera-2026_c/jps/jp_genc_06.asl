func equal(A: array[10] of float,
           B: array[10] of float) : bool
    return not (A<<B or B<<A);
endfunc

func main()
   var i,j,n: int
   var b: bool
   var A,B: array [10] of int
   var C,D: array [10] of char
   var X,Y: array [10] of float

   read n;
   while n!=999 do
      if n==888 then
         // 888 means arrays of int
         i = 0;
         while i<10 do
            read A[i]; X[9-i] = A[i]; i = i+1;
         endwhile
         i = 0;
         while i<10 do
            read B[i]; Y[9-i] = B[i]; i = i+1;
         endwhile
         if A << B then
            write "A smaller than B\n";
         else if not (B<<A) then
            write "A is equal than B\n";
         endif
         endif
            
         if equal(X,Y) then write "X == Y\n";
         else if X<<Y then write "X < Y\n";
         else write "X > Y\n";
         endif
         endif
      else
         // not 888 means arrays of char
         i=0;
         while i<10 do
            read C[i]; i=i+1;
         endwhile
         i=0;
         while i<10 do
            read D[i]; i=i+1;
         endwhile
  
         if C << D then
            write "C smaller than D\n";
         else if not (D << C) then
            write "C is equal than D\n";
         else
            write C[1]; write D[2]; write "\n";
         endif
         endif
      endif
      
      read n;
   endwhile
endfunc
