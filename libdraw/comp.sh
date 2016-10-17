echo "\n  ---start testout---" ;
gcc -c -x objective-c testout.m -Weverything ;
echo "\n  ---end testout---\n\n  ---start main---" ;
gcc testout.o main.c -framework AppKit -framework OpenGL -framework Metal;
echo "\n  ---end main---\n\n  ---start a.out---" ; 
./a.out ;
echo "\n  ---end a.out---\n" ;