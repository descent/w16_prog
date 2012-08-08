#run c:\msvc\bin\msvcvars.bat first
w1.exe: w1.obj w1.def
	link w1,/align:16, NUL, /nod slibcew libw, w1.def
	rc w1.exe
w1.obj: w1.c
	cl -c -Gsw -Ow -W2 -I c:\msvc\include w1.c
