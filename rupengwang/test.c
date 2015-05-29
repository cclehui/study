#include <stdio.h>
#include <gtk/gtk.h>

void close_window(char *data){
    printf("the window is closing...\ncall back data : %s \n" , data);
    gtk_main_quit();
}

GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      printf("%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

int main(int argc , char *argv[]){
    
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window) , "主窗口");
    gtk_window_set_default_size(GTK_WINDOW(window) , 400 , 200);
    gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER);
     gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("icon.png"));
    gtk_widget_show(window);

    //g_signal_connect_swapped(G_OBJECT(window) , "destroy" ,G_CALLBACK(gtk_main_quit) , NULL);
    g_signal_connect_swapped(G_OBJECT(window) , "destroy" ,G_CALLBACK(close_window) , "xdddddddddddddddd");

    gtk_main();

    return 1;
}