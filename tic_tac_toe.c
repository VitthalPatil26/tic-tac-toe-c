#include <stdio.h>
#include <unistd.h>

int player1_score = 0;
int player2_score = 0;
int draw_count = 0;

/* Function declarations */
int check_winner(char board[]);
void display_board(char board[]);
void display_scoreboard(char player1[], char player2[], int player1_score, int player2_score, int draw_count);

int main(){
	
	/* Variables */
	char ch;
	char player1[20];
	char player2[20];

	/* Tic-Tac-Toe Board */
	char board[9];

	/* Position entered by the player */
	int position;

	/* turn = 1 -> player 1
	   turn = 2 -> player 2*/

	int turn = 1;

	/* Number of valid moves */
	int moves = 0;

	/* Initialize the board with positions 1 to 9 */
	
	board[0] = ' ';
	board[1] = ' ';
	board[2] = ' ';
	board[3] = ' ';
	board[4] = ' ';
	board[5] = ' ';
	board[6] = ' ';
	board[7] = ' ';
	board[8] = ' ';

	/* --------------------------------------------
	   Welcome screen
	   ------------------------------------------*/

	printf("\n");
	printf("==============================\n");
	printf("         TIC_TAC_TOE\n");
	printf("==============================\n");

	for(int i = 0; i < 3; i++){

		for(int j = 1; j <= 3; j++){

			printf("\r\033[KLoading");

			for(int k = 0; k < j; k++){

				printf(" .");
			}
			fflush(stdout);
			sleep(1);
		}
		
		if(i < 2){
			printf("\r\033[KLoading");
			fflush(stdout);
			sleep(1);
		}
	}
	printf("\n");

	/* --------------------------------------------
           Ask the user whether they want to play
           ------------------------------------------*/

	printf("Do you want to play (Y/N) : ");
	scanf(" %c",&ch);

	if(ch == 'Y' || ch == 'y'){
		
		/* Get player 1 name */

		printf("\n");	
		printf("Enter player1 name : ");
		scanf(" %[^\n]",player1);
	
		/* Get player 2 name */

		printf("Enter player2 name : ");
                scanf(" %[^\n]",player2);

		printf("\n");

		/* Display players name */

		printf("Player1 : %s\n", player1);
		printf("Player2 : %s\n", player2);

		printf("\n");

		/* Assign symbol */

		printf("[%s ---> X]  [%s ---> O]\n", player1, player2);
		printf("\n");
		
		/* -------------------------------------------------
           	   Outer loop

           	   This loop allows players to play multiple games.
           	   It continues when the user enters Y/y after a game.
           	   ------------------------------------------------- */

		do
		{
			/* Reset the game */

			 moves = 0;
			 turn = 1;

			 /* Reset the board */

			 board[0] = ' ';
        		 board[1] = ' ';
        		 board[2] = ' ';
        		 board[3] = ' ';
        		 board[4] = ' ';
        		 board[5] = ' ';
        		 board[6] = ' ';
        		 board[7] = ' ';
        		 board[8] = ' ';

		         /* Display the instruction */

			 printf("\n");
			 printf("NOTE : Enter 1 to 9 select box!\n\n");

			 /* Display the empty board */

			 display_board(board);

			/* -------------------------------------------------
               		   Main game loop

               		   Maximum 9 valid moves are possible.
               		   ------------------------------------------------- */

       
			while(moves < 9){

				 /* =================================================
                   		    PLAYER 1 TURN
                   		    ================================================= */

				if(turn == 1){
       					do
					{
						printf("\nEnter %s position[X] : ", player1);						
						scanf("%d",&position);
						
		
						/* Check whether position is between 1 and 9 */						
						if(position < 1 || position > 9){

							printf("Invalid Entry\n");

						}

						 /* Check whether position is already occupied */

						else if(board[position - 1] == 'X' || board[position - 1] == 'O'){

							printf("Position already occupied. Please try again...\n");

						}

						/* Valid position */

						else{
							/* Place X on the selected position */
							board[position - 1] = 'X';

							 /* Display updated board */
							display_board(board);

							/* Exit input validation loop */
							break;

						}
					}while(1);
				}

				/* =================================================
                   		   PLAYER 2 TURN
                   		   ================================================= */

				else{

					do
                			{
                        		printf("\nEnter %s position[O] : ", player2);
                        		scanf("%d",&position);

					/* Check whether position is between 1 and 9 */
                        		if(position < 1 || position > 9){
					
                                		printf("Invalid position!. Enter 1 to 9. \n");

                        		}

                        		else if(board[position - 1] == 'X' || board[position - 1] == 'O'){

                                		printf("Position already occupied. Please try again...\n");

                        		}
					
					/* Valid position */
                        		else{
			
		       			        /* Place O on the selected position */
                                		board[position - 1] = 'O';
				
						/* Display updated board */
						display_board(board);


                                                /* Exit input validation loop */
                                		break;

                        			}
                			}while(1);
			
				}

				 /* -------------------------------------------------
		                    Increase move count after a valid move
                 		    ------------------------------------------------- */

				moves++;

				 /* -------------------------------------------------
                   		    Check whether the current player has won
                   		    ------------------------------------------------- */

				if(check_winner(board))
				{
					if(turn == 1)
					{
						printf("Congrats %s!. You won 🎉\n\n", player1);
                                                
						player1_score++;
					}
					else{
						printf("Congrats %s!. You won 🎉\n\n", player2);

						player2_score++;

					}

					/* Game is over */
					break;
				}

				 /* -------------------------------------------------
                   		    Check for draw

                   		    If all 9 positions are filled and nobody won,
                   		    the game is a draw.
                   		    ------------------------------------------------- */

				if(moves == 9){
					printf("\nGame draw\n\n");

					draw_count++;

					break;
				}

				/* -------------------------------------------------
                   		   Change player turn

                   		   Player 1 -> Player 2
                   		   Player 2 -> Player 1
                   		   ------------------------------------------------- */

				if(turn == 1)
					turn = 2;
				else
					turn = 1;
			}/* End of while(moves < 9) */

			display_scoreboard(player1, player2, player1_score, player2_score, draw_count);

			/* -------------------------------------------------
               		   Ask whether players want another game
               		   ------------------------------------------------- */
			
			printf("Do you want to play again (Y/N) : ");
			scanf(" %c",&ch);

		}while(ch == 'Y' || ch == 'y');		
		
		 /* -------------------------------------------------
           		Exit message
           	    ------------------------------------------------- */
		printf("\nThank you for playing\n\n");
	}

	/* -------------------------------------------------
       		User doesn't want to play
       	   ------------------------------------------------- */

	else if(ch == 'N' || ch == 'n'){
		printf("Thank you for playing\n");
	}

	/* -------------------------------------------------
       	   Invalid choice
           ------------------------------------------------- */

	else{
		printf("Invalid choice!\n");
	}
	
	return 0;
}

/* =========================================================
   FUNCTION: check_winner()

   Purpose:
   Checks all 8 possible winning combinations.

   Returns:
       1 -> Winner found
       0 -> No winner
   ========================================================= */

int check_winner(char board[])
{
	/* -------------------------
           Check rows
       	   ------------------------- */

    	/* Row 1: 0 1 2 */
	
	if(board[0] != ' ' && board[0] == board[1] && board[1] == board[2])
		return 1;

	/* Row 2: 3 4 5 */
	if(board[3] != ' ' && board[3] == board[4] && board[4] == board[5])
                return 1;

	/* Row 3: 6 7 8 */
	if(board[6] != ' ' && board[6] == board[7] && board[7] == board[8])
                return 1;

	/* -------------------------
       	   Check columns
       	   ------------------------- */

    	/* Column 1: 0 3 6 */

	if(board[0] != ' ' && board[0] == board[3] && board[3] == board[6])
                return 1;

	/* Column 2: 1 4 7 */
	if(board[1] != ' ' && board[1] == board[4] && board[4] == board[7])
                return 1;

	/* Column 3: 2 5 8 */
	if(board[2] != ' ' && board[2] == board[5] && board[5] == board[8])
                return 1;

	 /* -------------------------
       	    Check diagonals
       	    ------------------------- */

        /* Diagonal 1: 0 4 8 */

	if(board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
                return 1;

	/* Diagonal 2: 2 4 6 */
	if(board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
                return 1;

	/* No winning combination found */
	return 0;
}

/* =========================================================
   FUNCTION: display_board()

   Purpose:
   Displays the current Tic-Tac-Toe board.
   ========================================================= */

void display_board(char board[])
{

	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n",board[0], board[1], board[2]);

	printf("|---|---|---|\n");
        printf("| %c | %c | %c |\n",board[3], board[4], board[5]);

	printf("|---|---|---|\n");
        printf("| %c | %c | %c |\n",board[6], board[7], board[8]);

	printf("|---|---|---|\n");

}

void display_scoreboard(char player1[], char player2[], int player1_score, int player2_score, int draw_count){

	printf("\n");
	printf("====================================\n");
	printf("            SCOREBOARD\n");
	printf("====================================\n");
	
	printf("%-15s : %d\n", player1, player1_score);
	printf("%-15s : %d\n", player2, player2_score);
	printf("%-15s : %d\n", "Draws", draw_count);

	printf("====================================\n");

}
