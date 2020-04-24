Const
  fi= 'ROWING.INP';
  fo= 'ROWING.OUT';
  maxn= 4000;

Var
  n: longint;
  h: extended;
  x, y: array[1..maxn] of extended;
  d: array[0..maxn+1] of extended;

Procedure reads;
Var
  i: longint;
Begin
  read(n,h);
  for i:= 1 to n do read(x[i],y[i]);
End;

Function max(a, b: extended): extended;
Begin
  if a> b then exit(a) else exit(b);
End;

Function dis(i, j: longint): extended;
Var
  tg: extended;
Begin
  if (i=0) and (j=n+1) then exit(h);
  if (i=n+1) and (j=0) then exit(h);
  if i= 0 then exit(h-y[j]);
  if j= 0 then exit(h-y[i]);
  if i= n+1 then exit(y[j]);
  if j= n+1 then exit(y[i]);
  exit(sqrt(sqr(x[i]-x[j])+ sqr(y[i]- y[j])));
End;

Procedure Process;
Var
  nu, i, j, p, v: longint;
  u: array[0..maxn+1] of longint;
Begin
  for i:= 1 to n do
    d[i]:= dis(0,i);
  d[n+1]:= h;
  for i:= 1 to n+1 do
    u[i]:= i;
  nU:= n+1;
  repeat
    i:= 1;
    for j:= 2 to nu do
      if d[u[i]]> d[u[j]] then i:= j;
    p:= u[i];
    u[i]:= u[nu];
    dec(nu);

    for i:= 1 to nu do
      begin
        v:= u[i];
        if d[v]> max(d[p],dis(v,p)) then d[v]:= max(d[p],dis(v,p));
      end;
  until p= n+1;
End;

Procedure result;
Begin
  writeln(trunc(d[n+1]));
End;

Begin
  assign(input,fi); reset(input);
  assign(output,fo); rewrite(output);
    reads;
    process;
    result;
  close(input); close(output);
End.
