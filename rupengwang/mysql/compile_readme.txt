
gcc -o temp.exe temp.c -IC:\Program Files\MySQL\MySQL Server 5.6\include\mysql.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\my_alloc.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\my_list.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\mysql_com.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\mysql_time.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\mysql_version.h -IC:\Program Files\MySQL\MySQL Server 5.6\include\typelib.h 


gcc -o temp.exe temp.c -IC:/Program Files/MySQL/MySQL Server 5.6/include -LC:/Program Files/MySQL/MySQL Server 5.6/lib

gcc -o temp.exe temp.c -IC:/"Program Files"/MySQL/"MySQL Server 5.6"/include -L. -lmysql

gcc -o temp.exe temp.c -IC:/"Program Files"/MySQL/"MySQL Server 5.6"/include "/MT" "/Zi" "/O2" "/Ob1" "/D" "NDEBUG" "/EHsc" "-DDBUG_OFF" 