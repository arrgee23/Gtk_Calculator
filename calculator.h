#ifndef CALCULATOR_H_   /* Include guard */
#define CALCUALTOR_H_

#include <string.h>
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

GtkWidget* text_field;

//gchar answer_buffer[200];



gchar* return_button_label(gint index);

void callback( GtkWidget *widget,gpointer data );

//void answer(gchar* buffer);

int return_symbol(char* text_field_buffer, int* index, char* symbol);

void make_string(char* text_field_buffer,char* dest1,char* dest2,int index);

void clearbuffer(char* text_field_buffer);

int calculation(char* text_field_buffer);

void apply_currect_operation(char* output,char symbol,double num1,double num2);

#endif
