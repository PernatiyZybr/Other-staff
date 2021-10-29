uses GraphABC;

var p,n,j,aa,i,tmp,tmp2,tmp_max,i_tmp,ii:integer;
var A,B:array of integer;
var s:string;

procedure draw_pic(A:array of integer);
begin
  var m:integer;
  lockdrawing;
    clearwindow;
    for m := 0 to n-1 do begin
      setpencolor(clMagenta);
      Circle(round(m*500/n),round((n+1-A[m])*500/n),1);
    end;
    redraw();
end;

begin
  p:=3;
  n:= round(power(10,p));
  A:= new integer[n];
  B:= new integer[n];
  write('Изначальный массив: ');
  for i := 0 to n-1 do begin
    A[i]:=random(0,n-1);
    B[i]:=A[i];
    write(A[i], ' ');
  end;
  writeln();
  tmp_max:=0;
  for i := 0 to n-1 do begin
    tmp_max:=0;
    for j:= i to n-1 do begin
      if A[j]>tmp_max then begin
        tmp_max := A[j];
        i_tmp := j;
      end;
    end;
    ii := i;
    tmp:=A[i];
    A[i]:=tmp_max;
    while ii < n-1 do begin
      ii += 1;
      if (ii < i_tmp) then begin
        tmp2:=A[ii];
        A[ii]:=tmp;
        tmp:=tmp2;
      end;
      if (ii = i_tmp) then begin
        A[ii]:=tmp;
      end;
    end;
    
    //Красивая картинка
    setwindowsize (500,500);
    draw_pic(A);
    
  end;
  setwindowsize (1000,600);
  clearwindow;
  draw_pic(A);
  SetFontColor(clGray);
  aa := 10;
  SetFontSize(aa);
  textout(5,510,'Упорядоченный массив');
  textout(5,550,'Изначальный массив');
  for i := 0 to n-1 do begin
    str(A[i],s);
    textout(5 + i*aa*p, 530, s);
    str(B[i],s);
    textout(5 + i*aa*p, 570, s);
  end;
  redraw();
end.