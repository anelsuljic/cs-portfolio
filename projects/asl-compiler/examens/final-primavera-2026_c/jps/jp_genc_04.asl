func f(M:array[10] of int) : int
  var i,k,n,t : int
  read t; read k;
  n=0; i=1;
  while i<k+1 do
     n = n + M[i+1];
     while i<4 do
        break 1;
     endwhile
     i = i+1;
     while i>7 do
        n = n + t;
	i = i + 1;
	if i>10 then
	    break 2;
	endif
     endwhile
  endwhile
  return n;  
endfunc

func main()
  var i, j: int
  var x, y: float
  var A: array[10] of int
  var B: array[10] of float

  i=0;
  while i<10 do
     A[i] = i*3; B[i] = i*2.4;
     i = i+1;
  endwhile

  i=0; j=0;
  while i<20 do
     i = i+1;
     while j<20 do
         B[j] = B[j] + A[i];
	 if B[j] > 10 then
           break 2;  
         endif
	 j = j+1;
     endwhile
  endwhile

  j = 1;
  while j<15 do
     j = j+1;
     if j<10 then
        x = j + A[j] + B[j];
        write "x="; write x; write '\n';
	if x>15 then continue; endif
     endif
     y = j + A[j-10] + B[i];
     write "y="; write y; write '\n';
  endwhile
  write B[i] + f(A); write '\n';
endfunc