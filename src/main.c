#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gfx.h"
#include "libs/Node/Node.h"
#include "libs/List/List.h"
#include "libs/Stack/Stack.h"
#include "libs/Queue/Queue.h"

#ifdef __unix__
#define clear system("clear")
#else
#define clear system("cls")
#endif

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define NODE_WIDTH 80
#define NODE_HEIGHT 50
#define TOTAL_WIDTH (NODE_WIDTH + 32)
#define TOTAL_HEIGHT NODE_HEIGHT

// Colors
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Purple "\033[0;34m"
#define Cyan "\033[0;36m"
#define Reset "\033[0m"
#define Bold "\033[1m"
#define GFX_CYAN 13, 171, 219
#define GFX_RED 226, 2, 17
#define GFX_GREEN 80, 250, 123
#define GFX_PURPLE 70, 55, 121
#define GFX_BLACK 5, 0, 16
#define GFX_WHITE 228, 226, 226

int mainMenu ();

void subMenu ( bool );

int operationsMenu ( int );

void viewList ( struct Node* );

void drawNode ( struct Node*, int, int );

void drawDNode ( struct dNode*, bool, int, int );

void drawList ( struct Node* );

void drawDList ( struct dNode* );


int main ( int argc, char** argv ) {
	int choice;
	gfx_init( WINDOW_WIDTH, WINDOW_HEIGHT, "Data Structures" );

	do {
		choice = mainMenu();
		switch ( choice ) {
			case 1: { // List Simply Linked
				int operation;
				setCircular( false );
				struct Node* node = NULL;
				do {
					clear;
					operation = operationsMenu( 1 );
					switch ( operation ) {
						case 1: { // Insertion
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( insertNodeInList( &node, value ) ) {
								printf( "%sInsertion successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sInsertion failed!%s\n", Red, Reset );
							}
							gfx_clear();
							drawList( node );
							gfx_paint();
							sleep( 1 );
						}
							break;
						case 2: { // Deletion
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( removeNodeFromList( &node, value ) ) {
								printf( "%sDeletion successful!%s\n", Green, Reset );

							}
							else {
								printf( "%sDeletion failed!%s\n", Red, Reset );
							}
							gfx_clear();
							drawList( node );
							gfx_paint();
							sleep( 1 );
						}
							break;
						case 3: { // Search
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( searchNodeInList( node, value ) ) {
								printf( "%sValue found!%s\n", Green, Reset );
								sleep( 1 );
							}
							else {
								printf( "%sValue doesn't found!%s\n", Red, Reset );
								sleep( 1 );
							}
						}
							break;
						default: {
							removeAllNodesFromList( &node );
						}
							break;
					} // End of switch
				} while ( operation != 4 );
				gfx_clear();
				gfx_paint();
				clear;
			}
				break; // End of List Simply Linked
			case 2: {
				int operation;
				struct Node* node = NULL;
				setCircular( true );
				do {
					clear;
					operation = operationsMenu( 2 );
					switch ( operation ) {
						case 1: { // Insertion
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( insertNodeInList( &node, value ) ) {
								printf( "%sInsertion successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sInsertion failed!%s\n", Red, Reset );
							}
							gfx_clear();
							drawList( node );
							gfx_paint();
							sleep( 1 );
						}
							break;
						case 2: { // Deletion
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( removeNodeFromList( &node, value ) ) {
								printf( "%sDeletion successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sDeletion failed!%s\n", Red, Reset );
							}
							gfx_clear();
							drawList( node );
							gfx_paint();
							sleep( 1 );
						}
							break;
						case 3: { // Search
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( searchNodeInList( node, value ) ) {
								printf( "%sValue found!%s\n", Green, Reset );
							}
							else {
								printf( "%sValue doesn't found!%s\n", Red, Reset );
							}
							sleep( 1 );
						}
							break;
						default: {
							clear;
						}
							break;
					}
				} while ( operation != 4 );
				removeAllNodesFromList( &node );
				gfx_clear();
				gfx_paint();
				setCircular( false );
			}
				break; // End of List Circularly Linked
			case 3: { // Doubly Linked
				setCircular( false );
				int operation;
				struct dNode* head = ( struct dNode* ) malloc( sizeof( struct dNode ) );
				gfx_clear();
				drawDList( head );
				gfx_paint();
				do {
					clear;
					operation = operationsMenu( 3 );
					switch ( operation ) {
						case 1: { // Insertion
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( insertDNodeInList( &head, value ) ) {
								printf( "%sInsertion successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sInsertion failed!%s\n", Red, Reset );
							}
						}
							break;
						case 2: { // Delete
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( removeDNodeFromList( &head, value ) ) {
								printf( "%sDeletion successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sDeletion failed!%s\n", Red, Reset );
							}
						}
							break;
						case 3: { // Search
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( searchDNodeInList( head, value ) ) {
								printf( "%sValue found!%s\n", Green, Reset );
							}
							else {
								printf( "%sValue doesn't found!%s\n", Red, Reset );
							}
						}
							break;
						default: {
							clear;
						}
							break;
					}
					gfx_clear();
					drawDList( head );
					gfx_paint();
					sleep( 1 );
				} while ( operation != 4 );
				free( head );
			}
				break; // End of Doubly Linked
			case 4: { // Stack
				int operation;
				struct Node* node = NULL;
				setCircular( false );
				do {
					clear;
					operation = operationsMenu( 4 );
					switch ( operation ) {
						case 1: {
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( pushStack( &node, value ) ) {
								printf( "%sPush successful!%s\n", Green, Reset );
								sleep( 1 );
							}
							else {
								printf( "%sPush failed!%s\n", Red, Reset );
								sleep( 1 );
							}
						}
							break;
						case 2: {
							int valuePopped = popStack( &node );
							if ( valuePopped != -1 ) {
								printf( "%sValue popped: %d%s\n", Green, valuePopped, Reset );
								sleep( 1 );
							}
							else {
								printf( "%sStack is empty!%s\n", Red, Reset );
								sleep( 1 );
							}
						}
							break;
						default: {
							removeAllNodesFromList( &node );
							gfx_clear();
						}
							break;
					}
					gfx_clear();
					drawList( node );
					gfx_paint();
				} while ( operation != 3 );
			}
				break; // End of Stack
			case 5: { // Queue
				int operation;
				struct Node* node = NULL;
				setCircular( false );
				do {
					clear;
					operation = operationsMenu( 5 );
					switch ( operation ) {
						case 1: {
							int value;
							printf( "%sEnter value: %s", Bold, Green );
							scanf( "%d", &value );
							if ( pushQueue( &node, value ) ) {
								printf( "%sPush successful!%s\n", Green, Reset );
							}
							else {
								printf( "%sPush failed!%s\n", Red, Reset );
							}
							gfx_clear();
							drawList( node );
							gfx_paint();
							sleep( 1 );
						}
							break;
						case 2: {
							int valuePopped = popQueue( &node );
							if ( valuePopped != -1 ) {
								printf( "%sValue popped: %d%s\n", Green, valuePopped, Reset );
								gfx_clear();
								drawList( node );
								gfx_paint();
								sleep( 1 );
							}
							else {
								printf( "%sQueue is empty!%s\n", Red, Reset );
								gfx_clear();
								drawList( node );
								gfx_paint();
								sleep( 1 );
							}
						}
							break;
						default: {
							removeAllNodesFromList( &node );
							gfx_clear();
						}
							break;
					}
				} while ( operation != 3 );
			}
				break; // End of Queue
			default: {
			}
		}
	} while ( choice != 6 );
	clear;
	gfx_quit();
	return 0;
}

int mainMenu () {
	int choice;
	clear;
	printf( Purple );
	printf( "┌──────────────────────────────────────────────────┐\n" );
	printf( "│                       MENU                       │\n" );
	printf( "├──────────────────────────────────────────────────┤\n" );
	printf( "│ " );
	printf( Cyan "1. List (Simply Linked)                          " );
	printf( Purple"│\n" );
	printf( "│ " );
	printf( Cyan "2. List (Circular Simply Linked)                 " );
	printf( Purple"│\n" );
	printf( "│ " );
	printf( Cyan "3. List (Doubly Linked)                          " );
	printf( Purple"│\n" );
	printf( "│ " );
	printf( Cyan "4. Stack                                         " );
	printf( Purple"│\n" );
	printf( "│ " );
	printf( Cyan "5. Queue                                         " );
	printf( Purple"│\n" );
	printf( "│ " );
	printf( Cyan "6. Exit                                          " );
	printf( Purple"│\n" );
	printf( "└──────────────────────────────────────────────────┘\n" );
	do {
		printf( Green );
		printf( "Enter your choice: " );
		scanf( "%d", &choice );
		if ( choice < 1 || choice > 6 ) {
			printf( Red );
			printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
			printf( Reset );
		}
	} while ( choice < 1 || choice > 6 );
	printf( Reset );
	return choice;
}

void subMenu ( bool isList ) {
	if ( isList ) {
		printf( Purple );
		printf( "│ " );
		printf( Cyan "1. Insert                                        " );
		printf( Purple"│\n" );
		printf( "│ " );
		printf( Cyan "2. Delete                                        " );
		printf( Purple"│\n" );
		printf( "│ " );
		printf( Cyan "3. Search                                        " );
		printf( Purple"│\n" );
		printf( "│ " );
		printf( Cyan "4. Back                                          " );
		printf( Purple"│\n" );
	}
	else {
		printf( Purple );
		printf( "│ " );
		printf( Cyan "1. Push                                          " );
		printf( Purple"│\n" );
		printf( "│ " );
		printf( Cyan "2. Pop                                           " );
		printf( Purple"│\n" );
		printf( "│ " );
		printf( Cyan "3. Back                                          " );
		printf( Purple"│\n" );
	}
}

int operationsMenu ( int option ) {
	int choice;
	switch ( option ) {
		case 1: {
			printf( Purple );
			printf( "┌──────────────────────────────────────────────────┐\n" );
			printf( "│                 %sSimply Linked List%s               │\n", Bold, Purple );
			printf( "├──────────────────────────────────────────────────┤\n" );
			subMenu( true );
			printf( "└──────────────────────────────────────────────────┘\n" );
			do {
				printf( Green );
				printf( "Enter your choice: " );
				scanf( "%d", &choice );
				if ( choice < 1 || choice > 4 ) {
					printf( Red );
					printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
					printf( Reset );
				}
			} while ( choice < 1 || choice > 4 );
		}
			break;
		case 2: {
			printf( Purple );
			printf( "┌──────────────────────────────────────────────────┐\n" );
			printf( "│            %sCircular Simply Linked List%s           │\n", Bold, Purple );
			printf( "├──────────────────────────────────────────────────┤\n" );
			subMenu( true );
			printf( "└──────────────────────────────────────────────────┘\n" );
			do {
				printf( Green );
				printf( "Enter your choice: " );
				scanf( "%d", &choice );
				if ( choice < 1 || choice > 4 ) {
					printf( Red );
					printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
					printf( Reset );
				}
			} while ( choice < 1 || choice > 4 );
		}
			break;
		case 3: {
			printf( Purple );
			printf( "┌──────────────────────────────────────────────────┐\n" );
			printf( "│                 %sDoubly Linked List%s               │\n", Bold, Purple );
			printf( "├──────────────────────────────────────────────────┤\n" );
			subMenu( true );
			printf( "└──────────────────────────────────────────────────┘\n" );
			do {
				printf( Green );
				printf( "Enter your choice: " );
				scanf( "%d", &choice );
				if ( choice < 1 || choice > 4 ) {
					printf( Red );
					printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
					printf( Reset );
				}
			} while ( choice < 1 || choice > 4 );
		}
			break;
		case 4: {
			printf( Purple );
			printf( "┌──────────────────────────────────────────────────┐\n" );
			printf( "│                       %sStack%s                      │\n", Bold, Purple );
			printf( "├──────────────────────────────────────────────────┤\n" );
			subMenu( false );
			printf( "└──────────────────────────────────────────────────┘\n" );
			do {
				printf( Green );
				printf( "Enter your choice: " );
				scanf( "%d", &choice );
				if ( choice < 1 || choice > 4 ) {
					printf( Red );
					printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
					printf( Reset );
				}
			} while ( choice < 1 || choice > 4 );
		}
			break;
		case 5: {
			printf( Purple );
			printf( "┌──────────────────────────────────────────────────┐\n" );
			printf( "│                       %sQueue%s                      │\n", Bold, Purple );
			printf( "├──────────────────────────────────────────────────┤\n" );
			subMenu( false );
			printf( "└──────────────────────────────────────────────────┘\n" );
			do {
				printf( Green );
				printf( "Enter your choice: " );
				scanf( "%d", &choice );
				if ( choice < 1 || choice > 4 ) {
					printf( Red );
					printf( "%sInvalid choice. Please try again.%s\n", Bold, Green );
					printf( Reset );
				}
			} while ( choice < 1 || choice > 4 );
		}
	}

	return choice;
}

void viewList ( struct Node* node ) {
	if ( isCircular() ) {
		printf( "%s%d %s->", Cyan, node->value, Red );
		while ( node->next != node ) {
			printf( "%s%d %s-> ", Cyan, node->value, Red );
			node = node->next;
		}
		printf( "NULL\n" );
		return;
	}
	while ( node != NULL ) {
		printf( "%s%d%s -> ", Cyan, node->value, Red );
		node = node->next;
	}
	printf( "NULL%s\n", Reset );
}

void drawNode ( struct Node* node, int x, int y ) {
	if ( node == NULL ) { return; }
	char buffer[25];
	snprintf( buffer, 25, "%d", node->value );
	gfx_set_color( 208, 153, 255 );
	gfx_filled_rectangle( x, y, x + NODE_WIDTH - 20, y + NODE_HEIGHT );
	node->next == NULL ? gfx_set_color( 255, 85, 85 ) : gfx_set_color( 200, 200, 200 );
	gfx_filled_rectangle( x + NODE_WIDTH - 20, y, x + NODE_WIDTH, y + NODE_HEIGHT );
	gfx_set_color( 0, 0, 0 );
	gfx_text( x + 5, y + ( NODE_HEIGHT / 2 ) - 8, buffer );
}

void drawDNode ( struct dNode* node, bool isHead, int x, int y ) {
	if ( node == NULL ) { return; }
	char buffer[25];
	if ( isHead ) {
		gfx_set_color( 176, 152, 255 );
		gfx_filled_rectangle( ( WINDOW_WIDTH / 2 ) - ( NODE_WIDTH / 2 ), y, ( WINDOW_WIDTH / 2 ) - ( NODE_WIDTH / 2 ) + 15,
													y + NODE_HEIGHT );
		gfx_set_color( 113, 89, 193 );
		gfx_filled_rectangle( ( WINDOW_WIDTH / 2 ) - ( NODE_WIDTH / 2 ) + 15, y,
													( WINDOW_WIDTH / 2 ) + ( NODE_WIDTH / 2 ) + 15, y + NODE_HEIGHT );
		gfx_set_color( 255, 255, 255 );
		gfx_text( ( WINDOW_WIDTH / 2 ) - ( NODE_WIDTH / 2 ) + 36, y + ( NODE_HEIGHT / 2 ) - 8, "HEAD" );
		gfx_set_color( 176, 152, 255 );
		gfx_filled_rectangle( ( WINDOW_WIDTH / 2 ) + ( NODE_WIDTH / 2 ) + 15, y,
													( WINDOW_WIDTH / 2 ) + ( NODE_WIDTH / 2 ) + 30, y + NODE_HEIGHT );
	}
	else {
		int xTopLeft = x;
		int yTopLeft = y;
		int xBottonRight = x + 15;
		int yBottonRight = y + NODE_HEIGHT;
		gfx_set_color( GFX_PURPLE );
		gfx_filled_rectangle( xTopLeft, yTopLeft, xBottonRight, yBottonRight );
		xTopLeft += 15;
		xBottonRight += NODE_WIDTH;
		gfx_set_color( 200, 200, 200 );
		gfx_filled_rectangle( xTopLeft, yTopLeft, xBottonRight, yBottonRight );
		gfx_set_color( 0, 0, 0 );
		snprintf( buffer, 25, "%d", node->value );
		gfx_text( xTopLeft + 5, yTopLeft + ( NODE_HEIGHT / 2 ) - 8, buffer );
		xTopLeft += NODE_WIDTH;
		xBottonRight += 15;
		gfx_set_color( GFX_PURPLE );
		gfx_filled_rectangle( xTopLeft, yTopLeft, xBottonRight, yBottonRight );
	}
}

void drawList ( struct Node* node ) {
	if ( isCircular() ) {
		if ( node == NULL ) { return; }
		int x = 10, y = 10, count = 0, firstNodeX = ( TOTAL_WIDTH / 2 ) - 10, firstNodeY = ( TOTAL_HEIGHT ) + 12;
		struct Node* temp = node;
		// Draw first node
		while ( temp->next != node ) {
			drawNode( temp, x, y );
			gfx_set_color( 137, 0, 255 );
			gfx_filled_ellipse( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, 3, 4 );
			gfx_line( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			gfx_line( x + NODE_WIDTH + 24, ( y + NODE_HEIGHT / 2 ) - 5, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			gfx_line( x + NODE_WIDTH + 24, ( y + NODE_HEIGHT / 2 ) + 5, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			count++;
			if ( count % 7 == 0 ) {
				x = 10 + TOTAL_WIDTH;
				y += TOTAL_HEIGHT + 16;
				count++;
			}
			else {
				x += TOTAL_WIDTH + 1;
			}
			temp = temp->next;
		}
		drawNode( temp, x, y );
		gfx_set_color( 137, 0, 255 );
		gfx_filled_ellipse( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, 3, 4 );
		gfx_line( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, x + NODE_WIDTH + 16, y + NODE_HEIGHT / 2 );
		gfx_line( x + NODE_WIDTH + 16, y + NODE_HEIGHT / 2, x + NODE_WIDTH + 16,
							( y + NODE_HEIGHT / 2 ) + ( TOTAL_HEIGHT / 2 ) + 12 );
		gfx_line( x + NODE_WIDTH + 16, ( y + NODE_HEIGHT / 2 ) + ( TOTAL_HEIGHT / 2 ) + 12, firstNodeX,
							( y + NODE_HEIGHT / 2 ) + ( TOTAL_HEIGHT / 2 ) + 12 );
		gfx_line( firstNodeX, ( y + NODE_HEIGHT / 2 ) + ( TOTAL_HEIGHT / 2 ) + 12, firstNodeX, firstNodeY );
		gfx_line( firstNodeX, firstNodeY - 1, firstNodeX + 5, firstNodeY + 6 );
		gfx_line( firstNodeX, firstNodeY - 1, firstNodeX - 5, firstNodeY + 6 );

	}
	else {
		int x = 10, y = 10, count = 0;
		while ( node != NULL ) {
			drawNode( node, x, y );
			node->next == NULL ? gfx_set_color( 255, 15, 15 ) : gfx_set_color( 137, 0, 255 );
			gfx_filled_ellipse( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, 3, 4 );
			gfx_line( x + NODE_WIDTH - 8, y + NODE_HEIGHT / 2, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			gfx_line( x + NODE_WIDTH + 24, ( y + NODE_HEIGHT / 2 ) - 5, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			gfx_line( x + NODE_WIDTH + 24, ( y + NODE_HEIGHT / 2 ) + 5, x + NODE_WIDTH + 32, y + NODE_HEIGHT / 2 );
			count++;
			if ( count % 7 == 0 ) {
				x = 10;
				y += TOTAL_HEIGHT + 16;
			}
			else {
				x += TOTAL_WIDTH + 1;
			}
			node = node->next;
		}
	}
}

void drawDList ( struct dNode* head ) {
	gfx_set_color( GFX_WHITE );
	gfx_text( 10, 10, "SUBTITLE: " );
	gfx_set_color(GFX_GREEN);
	gfx_filled_rectangle(10, 32, 20, 42);
	gfx_text(25, 30, "Pointer to next node");
	gfx_set_color(GFX_CYAN);
	gfx_filled_rectangle(10, 46, 20, 56);
	gfx_text(25, 44, "Pointer to previous node");

	if ( head == NULL ) { return; }
	int x = ( WINDOW_WIDTH / 2 ) - ( NODE_WIDTH / 2 ), y = 10, count = 0, nNodes = 0;

	// Variables to help draw the list
	int xMiddleHead = ( WINDOW_WIDTH / 2 ), yMiddleHead = 10 + TOTAL_HEIGHT / 2;

	// Draw head
	drawDNode( head, true, 0, y );
	if ( head->next == NULL || head->prev == NULL ) { return; }
	count++;
	// Draw both sides
	struct dNode* left;
	struct dNode* right;

	y += TOTAL_HEIGHT + 24;

	// Counting the number of nodes
	for ( struct dNode* temp = head->next; temp != head; temp = temp->next ) {
		nNodes++;
	}
	size_t nNodesHalf = floor( nNodes / 2.0 ), i;

	if ( nNodes == 1 ) {
		drawDNode( head->next, false, x, y );

		// Draw arrows

		// Right side
		// Element to the right of head
		gfx_set_color( GFX_GREEN );
		gfx_filled_ellipse( x + NODE_WIDTH + 23, y + ( NODE_HEIGHT / 2 ) + 12, 3, 4 );
		gfx_line( x + NODE_WIDTH + 23,
							y + ( NODE_HEIGHT / 2 ) + 12,
							x + NODE_WIDTH + 54,
							y + ( NODE_HEIGHT / 2 ) + 12 );
		gfx_line( x + NODE_WIDTH + 54,
							y + ( NODE_HEIGHT / 2 ) + 12,
							x + NODE_WIDTH + 54,
							y - ( NODE_HEIGHT / 2 ) - 12 );
		gfx_line( x + NODE_WIDTH + 54,
							y - ( NODE_HEIGHT / 2 ) - 12,
							x + NODE_WIDTH + 32,
							y - ( NODE_HEIGHT / 2 ) - 12 );
		gfx_line( x + NODE_WIDTH + 31,
							y - ( NODE_HEIGHT / 2 ) - 12,
							x + NODE_WIDTH + 37,
							y - ( NODE_HEIGHT / 2 ) - 17 );
		gfx_line( x + NODE_WIDTH + 31,
							y - ( NODE_HEIGHT / 2 ) - 12,
							x + NODE_WIDTH + 37,
							y - ( NODE_HEIGHT / 2 ) - 7 );
		// Right of head to the right of element
		gfx_set_color( GFX_GREEN );
		gfx_filled_ellipse( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 8, yMiddleHead - 12, 3, 4 );
		gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 8,
							yMiddleHead - 12,
							xMiddleHead + ( TOTAL_WIDTH / 2 ) + 32,
							yMiddleHead - 12 );
		gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 32,
							yMiddleHead - 12,
							xMiddleHead + ( TOTAL_WIDTH / 2 ) + 32,
							yMiddleHead + y - 20 );
		gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 32,
							yMiddleHead + y - 20,
							xMiddleHead + ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20 );
		gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20,
							xMiddleHead + ( TOTAL_WIDTH / 2 ) + 20,
							yMiddleHead + y - 14 );
		gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20,
							xMiddleHead + ( TOTAL_WIDTH / 2 ) + 20,
							yMiddleHead + y - 26 );
		// Left side
		// Element to the left of head
		gfx_set_color( GFX_CYAN );
		gfx_filled_ellipse( x + ( NODE_WIDTH / 2 ) - 33, y + ( NODE_HEIGHT / 2 ) + 12, 3, 4 );
		gfx_line( x + ( NODE_WIDTH / 2 ) - 33,
							y + ( NODE_HEIGHT / 2 ) + 12,
							x - ( NODE_WIDTH / 2 ) + 16,
							y + ( NODE_HEIGHT / 2 ) + 12 );
		gfx_line( x - ( NODE_WIDTH / 2 ) + 16,
							y + ( NODE_HEIGHT / 2 ) + 12,
							x - ( NODE_WIDTH / 2 ) + 16,
							y - ( NODE_HEIGHT / 2 ) - 12 );
		gfx_line( x - ( NODE_WIDTH / 2 ) + 16,
							y - ( NODE_HEIGHT / 2 ) - 12,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 12,
							y - ( NODE_HEIGHT / 2 ) - 12 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 12,
							y - ( NODE_HEIGHT / 2 ) - 12,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 6,
							y - ( NODE_HEIGHT / 2 ) - 18 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 12,
							y - ( NODE_HEIGHT / 2 ) - 12,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 6,
							y - ( NODE_HEIGHT / 2 ) - 6 );
		// Left of head to the left of element
		gfx_set_color( GFX_CYAN );
		gfx_filled_ellipse( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 23, yMiddleHead - 12, 3, 4 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 23,
							yMiddleHead - 12,
							xMiddleHead - ( TOTAL_WIDTH / 2 ),
							yMiddleHead - 12 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ),
							yMiddleHead - 12,
							xMiddleHead - ( TOTAL_WIDTH / 2 ),
							yMiddleHead + y - 20 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ),
							yMiddleHead + y - 20,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 10,
							yMiddleHead + y - 14 );
		gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 15,
							yMiddleHead + y - 20,
							xMiddleHead - ( TOTAL_WIDTH / 2 ) + 10,
							yMiddleHead + y - 26 );

	}
	else {
		// Draw left side if have even number of nodes
		for ( i = 0, left = head->prev; i < nNodesHalf; i++, left = left->prev ) {
			drawDNode( left, false, x - TOTAL_WIDTH, y );
			// Draw lines that connect first node to the head
			if ( i == 0 ) {
				// head -> node
				gfx_set_color( GFX_CYAN );
				gfx_filled_ellipse( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 23, yMiddleHead - 12, 3, 4 );
				gfx_line( xMiddleHead - ( TOTAL_WIDTH / 2 ) + 23,
									yMiddleHead - 12,
									x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
									yMiddleHead - 12 );
				gfx_line( x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
									yMiddleHead - 12,
									x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
									y );
				gfx_line( x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
									y,
									x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 20,
									y - 6 );
				gfx_line( x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
									y,
									x - TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
									y - 6 );

				// Line to next node (head)
				// node -> head
				gfx_set_color( GFX_GREEN );
				gfx_filled_ellipse( x - 8, y + ( NODE_HEIGHT / 2 ) - 8, 3, 4 );
				gfx_line( x - 8,
									y + ( NODE_HEIGHT / 2 ) - 8,
									xMiddleHead - 8,
									y + ( NODE_HEIGHT / 2 ) - 8 );
				gfx_line( xMiddleHead - 8,
									y + ( NODE_HEIGHT / 2 ) - 8,
									xMiddleHead - 8,
									yMiddleHead + ( NODE_HEIGHT / 2 ) );
				gfx_line( xMiddleHead - 8,
									yMiddleHead + ( NODE_HEIGHT / 2 ),
									xMiddleHead - 12,
									yMiddleHead + ( NODE_HEIGHT / 2 ) + 6 );
				gfx_line( xMiddleHead - 8,
									yMiddleHead + ( NODE_HEIGHT / 2 ),
									xMiddleHead - 4,
									yMiddleHead + ( NODE_HEIGHT / 2 ) + 6 );
			}
			// Draw lines that connect nodes to each other when have more than 2 nodes
			if ( i > 0 ) {
				// node -> previous node
				gfx_set_color( GFX_CYAN );
				gfx_filled_ellipse( x - TOTAL_WIDTH + 6, ( y - NODE_HEIGHT - 24 ) + ( NODE_HEIGHT / 2 ) + 8, 3, 4 );
				gfx_line( x - TOTAL_WIDTH + 6,
									( y - NODE_HEIGHT - 24 ) + ( NODE_HEIGHT / 2 ) + 8,
									x - TOTAL_WIDTH - 14,
									( y - NODE_HEIGHT - 24 ) + ( NODE_HEIGHT / 2 ) + 8 );
				gfx_line( x - TOTAL_WIDTH - 14,
									( y - NODE_HEIGHT - 24 ) + ( NODE_HEIGHT / 2 ) + 8,
									x - TOTAL_WIDTH - 14,
									y + 12 );
				gfx_line( x - TOTAL_WIDTH - 14,
									y + 12,
									x - TOTAL_WIDTH - 2,
									y + 12 );
				gfx_line( x - TOTAL_WIDTH - 2,
									y + 12,
									x - TOTAL_WIDTH - 8,
									y + 16 );
				gfx_line( x - TOTAL_WIDTH - 2,
									y + 12,
									x - TOTAL_WIDTH - 8,
									y + 8 );

				// node -> next node
				gfx_set_color( GFX_GREEN );
				gfx_filled_ellipse( x - 8, y + ( NODE_HEIGHT / 2 ) - 12, 3, 4 );
				gfx_line( x - 8,
									y + ( NODE_HEIGHT / 2 ) - 12,
									x + 12,
									y + ( NODE_HEIGHT / 2 ) - 12 );
				gfx_line( x + 12,
									y + ( NODE_HEIGHT / 2 ) - 12,
									x + 12,
									y - NODE_HEIGHT + 12 );
				gfx_line( x + 12,
									y - NODE_HEIGHT + 12,
									x + 1,
									y - NODE_HEIGHT + 12 );
				gfx_line( x + 1,
									y - NODE_HEIGHT + 12,
									x + 7,
									y - NODE_HEIGHT + 16 );
				gfx_line( x + 1,
									y - NODE_HEIGHT + 12,
									x + 7,
									y - NODE_HEIGHT + 8 );
			}
			y += TOTAL_HEIGHT + 24;
			count++;
		}
		y = 10 + TOTAL_HEIGHT + 24;
		// Draw right side
		for ( i = 0, right = head->next; i < nNodesHalf; i++, right = right->next ) {
			drawDNode( right, false, x + TOTAL_WIDTH, y );
			if ( i == 0 ) {
				// head -> node
				gfx_set_color( GFX_GREEN );
				gfx_filled_ellipse( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 7, yMiddleHead - 12, 3, 4 );
				gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 7,
									yMiddleHead - 12,
									xMiddleHead + TOTAL_WIDTH + 12,
									yMiddleHead - 12 );
				gfx_line( xMiddleHead + TOTAL_WIDTH + 12,
									yMiddleHead - 12,
									xMiddleHead + TOTAL_WIDTH + 12,
									y - 1 );
				gfx_line( xMiddleHead + TOTAL_WIDTH + 12,
									y - 1,
									xMiddleHead + TOTAL_WIDTH + 16,
									y - 7 );
				gfx_line( xMiddleHead + TOTAL_WIDTH + 12,
									y - 1,
									xMiddleHead + TOTAL_WIDTH + 8,
									y - 7 );

				// node -> head
				gfx_set_color( GFX_CYAN );
				gfx_filled_ellipse( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 22, y + ( NODE_HEIGHT / 2 ) - 8, 3, 4 );
				gfx_line( xMiddleHead + ( TOTAL_WIDTH / 2 ) + 22,
									y + ( NODE_HEIGHT / 2 ) - 8,
									xMiddleHead + 28,
									y + ( NODE_HEIGHT / 2 ) - 8 );
				gfx_line( xMiddleHead + 28,
									y + ( NODE_HEIGHT / 2 ) - 8,
									xMiddleHead + 28,
									yMiddleHead + ( NODE_HEIGHT / 2 ) );
				gfx_line( xMiddleHead + 28,
									yMiddleHead + ( NODE_HEIGHT / 2 ),
									xMiddleHead + 33,
									yMiddleHead + ( NODE_HEIGHT / 2 ) + 6 );
				gfx_line( xMiddleHead + 28,
									yMiddleHead + ( NODE_HEIGHT / 2 ),
									xMiddleHead + 23,
									yMiddleHead + ( NODE_HEIGHT / 2 ) + 6 );
			}
			if(i > 0) {
				// Next node -> node
				gfx_set_color( GFX_GREEN );
				gfx_filled_ellipse( x + TOTAL_WIDTH + TOTAL_WIDTH - 8, y - ( NODE_HEIGHT / 2 ) - 12, 3, 4 );
				gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH - 8,
									y - ( NODE_HEIGHT / 2 ) - 12,
									x + TOTAL_WIDTH + TOTAL_WIDTH + 12,
									y - ( NODE_HEIGHT / 2 ) - 12 );
				gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH + 12,
									y - ( NODE_HEIGHT / 2 ) - 12,
									x + TOTAL_WIDTH + TOTAL_WIDTH + 12,
									y + 12 );
				gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH + 12,
									y + 12,
									x + TOTAL_WIDTH + TOTAL_WIDTH,
									y + 12 );
				gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH,
									y + 12,
									x + TOTAL_WIDTH + TOTAL_WIDTH + 6,
									y + 16 );
				gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH,
									y + 12,
									x + TOTAL_WIDTH + TOTAL_WIDTH + 6,
									y + 8 );

				// node -> previous node
				gfx_set_color( GFX_CYAN );
				gfx_filled_ellipse( x + TOTAL_WIDTH + 6, y + ( NODE_HEIGHT / 2 ) - 8, 3, 4 );
				gfx_line( x + TOTAL_WIDTH + 6,
									y + ( NODE_HEIGHT / 2 ) - 8,
									x + TOTAL_WIDTH - 18,
									y + ( NODE_HEIGHT / 2 ) - 8 );
				gfx_line( x + TOTAL_WIDTH - 18,
									y + ( NODE_HEIGHT / 2 ) - 8,
									x + TOTAL_WIDTH - 18,
									y - NODE_HEIGHT + 12 );
				gfx_line( x + TOTAL_WIDTH - 18,
									y - NODE_HEIGHT + 12,
									x + TOTAL_WIDTH - 1,
									y - NODE_HEIGHT + 12 );
				gfx_line( x + TOTAL_WIDTH - 1,
									y - NODE_HEIGHT + 12,
									x + TOTAL_WIDTH - 6,
									y - NODE_HEIGHT + 16 );
				gfx_line( x + TOTAL_WIDTH - 1,
									y - NODE_HEIGHT + 12,
									x + TOTAL_WIDTH - 6,
									y - NODE_HEIGHT + 8 );


			}
			y += TOTAL_HEIGHT + 24;
			count++;
		}

		// Draw last lines, for both odd and even number of nodes
		if ( nNodes % 2 != 0 ) {
			drawDNode( right, false, x, y );

			// previous node -> node
			gfx_set_color( GFX_CYAN );
			gfx_filled_ellipse( x - TOTAL_WIDTH + 6, y - NODE_HEIGHT + 12, 3, 4 );
			gfx_line( x - TOTAL_WIDTH + 6,
								y - NODE_HEIGHT + 12,
								x - TOTAL_WIDTH + 6,
								y + 12 );
			gfx_line( x - TOTAL_WIDTH + 6,
								y + 12,
								x - 1,
								y + 12 );
			gfx_line( x - 1,
								y + 12,
								x - 7,
								y + 16 );
			gfx_line( x - 1,
								y + 12,
								x - 7,
								y + 8 );
			// node -> previous node

			gfx_filled_ellipse( x + 6, y + ( NODE_HEIGHT / 2 ) + 12, 3, 4 );
			gfx_line( x + 6,
								y + ( NODE_HEIGHT / 2 ) + 12,
								x + 6,
								y + NODE_HEIGHT + 3 );
			gfx_line( x + 6,
								y + NODE_HEIGHT + 3,
								x + TOTAL_WIDTH + TOTAL_WIDTH / 2,
								y + NODE_HEIGHT + 3 );
			gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH / 2,
								y + NODE_HEIGHT + 3,
								x + TOTAL_WIDTH + TOTAL_WIDTH / 2,
								y - 23 );
			gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH / 2,
								y - 23,
								( x + TOTAL_WIDTH + TOTAL_WIDTH / 2 ) + 4,
								y - 17 );
			gfx_line( x + TOTAL_WIDTH + TOTAL_WIDTH / 2,
								y - 23,
								( x + TOTAL_WIDTH + TOTAL_WIDTH / 2 ) - 4,
								y - 17 );

			// node -> next node
			gfx_set_color( GFX_GREEN );
			gfx_filled_ellipse( x + TOTAL_WIDTH - 8, y + ( NODE_HEIGHT / 2 ) - 8, 3, 4 );
			gfx_line( x + TOTAL_WIDTH - 8,
								y + ( NODE_HEIGHT / 2 ) - 8,
								x + TOTAL_WIDTH + 3,
								y + ( NODE_HEIGHT / 2 ) - 8 );
			gfx_line( x + TOTAL_WIDTH + 3,
								y + ( NODE_HEIGHT / 2 ) - 8,
								x + TOTAL_WIDTH + 3,
								y - 12 );
			gfx_line( x + TOTAL_WIDTH + 3,
								y - 12,
								x - TOTAL_WIDTH / 2,
								y - 12 );
			gfx_line( x - TOTAL_WIDTH / 2,
								y - 12,
								x - TOTAL_WIDTH / 2,
								y - 23 );
			gfx_line( x - TOTAL_WIDTH / 2,
								y - 23,
								( x - TOTAL_WIDTH / 2 ) + 4,
								y - 17 );
			gfx_line( x - TOTAL_WIDTH / 2,
								y - 23,
								( x - TOTAL_WIDTH / 2 ) - 4,
								y - 17 );

			// next node -> node
			gfx_filled_ellipse( x + ( 2 * TOTAL_WIDTH ) - 8, ( y + ( NODE_HEIGHT / 2 ) + 12 ) - NODE_HEIGHT - 25, 3, 4 );
			gfx_line( x + ( 2 * TOTAL_WIDTH ) - 8,
								( y + ( NODE_HEIGHT / 2 ) + 12 ) - NODE_HEIGHT - 25,
								x + ( 2 * TOTAL_WIDTH ) - 8,
								( y + ( NODE_HEIGHT / 2 ) + 12 ) );
			gfx_line( x + ( 2 * TOTAL_WIDTH ) - 8,
								( y + ( NODE_HEIGHT / 2 ) + 12 ),
								x + TOTAL_WIDTH,
								( y + ( NODE_HEIGHT / 2 ) + 12 ) );
			gfx_line( x + TOTAL_WIDTH,
								y + ( NODE_HEIGHT / 2 ) + 12,
								x + TOTAL_WIDTH + 6,
								y + ( NODE_HEIGHT / 2 ) + 8 );
			gfx_line( x + TOTAL_WIDTH,
								y + ( NODE_HEIGHT / 2 ) + 12,
								x + TOTAL_WIDTH + 6,
								y + ( NODE_HEIGHT / 2 ) + 16 );
		}
		else {
			// Line to the next node when have an even number of nodes
			gfx_set_color( GFX_GREEN );
			gfx_filled_ellipse( x + ( 2 * TOTAL_WIDTH ) - 8, y - TOTAL_HEIGHT + 12, 3, 4 );
			gfx_line( x + ( 2 * TOTAL_WIDTH ) - 8,
								y - TOTAL_HEIGHT + 12,
								x + ( 2 * TOTAL_WIDTH ) + 8,
								y - TOTAL_HEIGHT + 12 );
			gfx_line( x + ( 2 * TOTAL_WIDTH ) + 8,
								y - TOTAL_HEIGHT + 12,
								x + ( 2 * TOTAL_WIDTH ) + 8,
								y - ( TOTAL_HEIGHT / 2 ) + 15 );
			gfx_line( x + ( 2 * TOTAL_WIDTH ) + 8,
								y - ( TOTAL_HEIGHT / 2 ) + 15,
								x - ( TOTAL_WIDTH / 2 ),
								y - ( TOTAL_HEIGHT / 2 ) + 15 );
			gfx_line( x - ( TOTAL_WIDTH / 2 ),
								y - ( TOTAL_HEIGHT / 2 ) + 15,
								x - ( TOTAL_WIDTH / 2 ),
								y - ( TOTAL_HEIGHT / 2 ) + 1 );
			gfx_line( x - ( TOTAL_WIDTH / 2 ),
								y - ( TOTAL_HEIGHT / 2 ) + 1,
								x - ( TOTAL_WIDTH / 2 ) - 4,
								y - ( TOTAL_HEIGHT / 2 ) + 7 );
			gfx_line( x - ( TOTAL_WIDTH / 2 ),
								y - ( TOTAL_HEIGHT / 2 ) + 1,
								x - ( TOTAL_WIDTH / 2 ) + 4,
								y - ( TOTAL_HEIGHT / 2 ) + 7 );

			// Line to previous node
			gfx_set_color( GFX_CYAN );
			gfx_filled_ellipse( x - TOTAL_WIDTH + 4, y - TOTAL_HEIGHT + 12, 3, 4 );
			gfx_line( x - TOTAL_WIDTH + 4,
								y - TOTAL_HEIGHT + 12,
								x - TOTAL_WIDTH - 14,
								y - TOTAL_HEIGHT + 12 );
			gfx_line( x - TOTAL_WIDTH - 14,
								y - TOTAL_HEIGHT + 12,
								x - TOTAL_WIDTH - 14,
								y - ( TOTAL_HEIGHT / 2 ) + 12 );
			gfx_line( x - TOTAL_WIDTH - 14,
								y - ( TOTAL_HEIGHT / 2 ) + 12,
								x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
								y - ( TOTAL_HEIGHT / 2 ) + 12 );
			gfx_line( x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
								y - ( TOTAL_HEIGHT / 2 ) + 12,
								x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
								y - ( TOTAL_HEIGHT / 2 ) );
			gfx_line( x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
								y - ( TOTAL_HEIGHT / 2 ),
								x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 16,
								y - ( TOTAL_HEIGHT / 2 ) + 6 );
			gfx_line( x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 12,
								y - ( TOTAL_HEIGHT / 2 ),
								x + TOTAL_WIDTH + ( NODE_WIDTH / 2 ) + 8,
								y - ( TOTAL_HEIGHT / 2 ) + 6 );
		}
	}
}
