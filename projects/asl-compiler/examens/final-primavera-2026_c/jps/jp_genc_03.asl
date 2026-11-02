func f(M:array[10] of int) : int
  var i,k,n,t : int
  read t;
  n=0; i=0;
  while i<t+1 do
     i = i + 1;
     n = n + M[i+1];
     if i==4 then
        continue;
     endif
     i = i+1;
     if i>7 then
        break;
     endif
  endwhile
  return n;  
endfunc

func main()
  var i, j: int
  var x, y: float
  var A: array[10] of int
  var B: array[10] of float

  i=0;
  while i<20 do
     A[i] = i*3; B[i] = i*2.4;
     i = i+1;
     if i==10 then break; endif
  endwhile
  
  j = 1;
  while j<10 do
     if j<6 then
        x = j + A[j] + B[j];
        write "x="; write x; write '\n';
	if x>12 then
	   j = j+1; continue;
	endif
     endif
     y = j + A[j-1] + B[j-1];
     write "y="; write y; write '\n';
     j = j+1;
  endwhile
  
  write B[i-2] + f(A); write '\n';
endfunc