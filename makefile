add.o:add.cpp
	g++ -c $<
delete.o:delete.cpp add.h
	g++ -c $<
dl.o:dl.cpp predict.h
	g++ -c $<
edit.o:edit.cpp add.h delete.h
	g++ -c $<
edit_menu.o:edit_menu.cpp add.h edit.h delete.h
	g++ -c $<
login.o:login.cpp add.h search.h edit.h delete.h sort.h menu_kid.h tasks_trigger.h
	g++ -c $<
menu_kid.o:menu_kid.cpp edit_menu.h search.h sort.h add.h predict.h dl.h tasks_trigger.h
	g++ -c $<
predict.o:predict.cpp delete.h dl.h
	g++ -c $<
search.o:search.cpp
	g++ -c $<
sort.o:sort.cpp delete.h add.h
	g++ -c $<
tasks_trigger.o:tasks_trigger.cpp add.h
	g++ -c $<
app:add.o delete.o dl.o edit.o edit_menu.o login.o menu_kid.o predict.o search.o sort.o tasks_trigger.o
	g++ $^ -o $@

