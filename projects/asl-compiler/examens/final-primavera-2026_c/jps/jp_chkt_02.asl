func f(i : bool,
       b:array[10] of int) : int
  var j,a : int
  write (a + b);
  a = a > 1;
  if b[i]>0 then
     break;
  else
     break 2;
  endif
endfunc

func main()
  var i, j: int
  var c1, c2: char
  var x, y: float
  var A: array[10] of int
  var B: array[10] of float
  var C: array[10] of char

  while i<10 do
     if A[i]%2 == 0 then
         continue;
     else
         i = i + 1;
         x = c1 * B[j];
	 if not i then
	    break 2;
	 endif
     endif

     while x != y/C[j*i]-A[c1] do
        if c1 != c2 then
           break 3;
        else
            break 2;
        endif
     endwhile
  endwhile

  continue;
  write y+x;
  
endfunc


