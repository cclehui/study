#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc , char *argv[]){
    
    printf("xxxxxffffffxxxxxxx\n");
    
	/*
	GtkWidget *window;

	gtk_init(NULL , NULL);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);

	gtk_main();
	*/

	GtkWidget *window;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);

	gtk_main();

    return 1;
}