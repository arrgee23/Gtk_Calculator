/***************************************************************************************
# Still to implement
3. stopping keyboard input or better if merging them with click input. Now it displays 
    valid results only for mouse click inputs.
4. anything more u can spot. Given it is IMPORTANT and EASY TO IMPLEMENT

***************************************************************************************/

#include<gtk/gtk.h>
#include "calculator.h" 
#include <ctype.h>
#include <stdlib.h>

//buffer to store the inputs in the text field
gchar text_field_buffer[200];
GtkWidget* text_field;

int main(int argc,char* argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window,*button;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Calculator");
	gtk_window_set_default_size(GTK_WINDOW(window),200,240);
	
	GtkWidget* table;
	table = gtk_table_new(6,5,FALSE);
	gtk_table_set_col_spacings(GTK_TABLE(table),6);
	gtk_table_set_row_spacings(GTK_TABLE(table),6);

	text_field = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table),text_field,0,3,0,1);

	button = gtk_button_new_with_label("AC");
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_HALF);
	gtk_table_attach_defaults(GTK_TABLE(table),button,3,4,0,1);
	g_signal_connect (G_OBJECT (button), "clicked",G_CALLBACK (callback), "AC");

	int i,j;
	gchar* button_label;
	for(i=0;i<4;++i)
		for(j=0;j<4;j++)
		{
			button_label = return_button_label(10*i+j);
			button = gtk_button_new_with_label(button_label);
			
			gtk_table_attach_defaults(GTK_TABLE(table),button,j,j+1,i+1,i+1+1);
			//callback func here
			g_signal_connect (G_OBJECT (button), "clicked",G_CALLBACK (callback), button_label);
		}
	

	gtk_container_add(GTK_CONTAINER(window),table);
	gtk_widget_show_all(window);

	g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
	// set an icon
	gtk_window_set_icon_from_file (GTK_WINDOW(window),"calculator_icon.jpg",NULL);

	gtk_main();

	
	return 0;
}

