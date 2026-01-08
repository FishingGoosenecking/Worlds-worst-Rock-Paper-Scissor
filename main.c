//Rock paper scissor but worse written in C.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int gm,score,player1choice,player2choice,botchoice,player1score,player2score,botscore,beat;
    player1score = 0;
    player2score = 0;
    botscore = 0;
    printf("Welcome to Rock paper scissor\n");
    back:printf("Choose your gamemode");
    printf("\n1.PLayer VS Player\n2.Player VS Bot\n3.Exit game\n:");
    scanf("%d",&gm);
    if(gm == 1){
        printf("You choosed Player VS Player");
        printf("\n\n");
        goto player;
    } else if(gm == 2){
        printf("You choosed Player VS Bot");
        printf("\n\n");
        goto bot;
    } else if(gm == 3){
        exit:printf("\nExiting game");
        goto realexit;
    } else{
        printf("Invalid choice");
        goto back;
    }
    
    // player rps
    scoreback:
    player:printf("Insert the range of scores here (Max of 5 scores)\n:");
    scanf("%d",&score);
    if(score <= 5){
        printf("Score has setted to %d",score);
    }else{
        printf("Invalid score\n\n");
        goto scoreback;
    }//game start player
    scoreplayer:printf("\n\nPlayer 1 Turn\n");
    printf("\nRock 1\nPaper 2\nScissor 3\n:");
    scanf("%d",&player1choice);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Player 2 Turn\n\n");
    printf("Rock 1\nPaper 2\nScissor 3\n:");
    scanf("%d",&player2choice);
    //player1 rock
    if(player1choice == 1){
        if(player2choice == 1){
            goto draw;
        } else if(player2choice == 2){
            goto player2win;
        } else if(player2choice == 3){
            goto player1win;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
        //player1 paper
    }else if(player1choice == 2){
        if(player2choice == 1){
            goto player1win;
        }else if(player2choice == 2){
            goto draw;
        }else if(player2choice == 3){
            goto player2win;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
        //player1 scissor
    }else if(player1choice == 3){
        if(player2choice == 1){
            goto player2win;
        }else if(player2choice == 2){
            goto player1win;
        }else if(player2choice == 3){
            goto draw;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
    }else{
        printf("\nProgram has failed to calcurate :(\n");
        goto exit;
    }
    //score calculation
    player1win:printf("\nPlayer 1 has win\n\n");
    player1score = player1score + 1;
    printf("Score: Player1: %d Player2: %d",player1score,player2score);
    if(player1score == score){
        goto win;
    }else{
        goto scoreplayer;
    }

    player2win:printf("\nPlayer 2 has win\n\n");
    player2score = player2score + 1;
    printf("Score: Player1: %d Player2: %d",player1score,player2score);
    if(player2score == score){
        goto win;
    }else{
        goto scoreplayer;
    }

    draw:printf("\nBoth players have drawed, No one get score\n\n");
    goto scoreplayer;

    //win message
    win:
    if(player1score == score){
        printf("\n\n\n\n\n\n\n\nCongratulations!!!!\nPlayer 1 has win this game of Rock Paper Scissor!!!");
        printf("\nWith score of: Player1: %d Player2: %d",player1score,player2score);
        printf("\nGG\n");
        goto back;
        player1score = 0;
        player2score = 0;
    }else if(player2score == score){
        printf("\n\n\n\n\n\n\n\nCongratulations!!!!\nPlayer 2 has win this game of Rock Paper Scissor!!!");
        printf("\nWith score of: Player1: %d Player2: %d",player1score,player2score);
        printf("\nGG\n");
        player1score = 0;
        player2score = 0;
        goto back;
    }else{
        goto win;
    }















     // bot rps
    botscoreback:
    bot:printf("\nInsert the range of scores here (Max of 5 scores)\n:");
    scanf("%d",&score);
    if(score <= 5){
        printf("\nScore has setted to %d",score);
        goto scorebot;
    }else if (score == 0){
        printf("\nInvalid score\n\n");
        goto botscoreback;
    }else{
        printf("\ninvalid score\n\n");
    }
    //game start bot
    scorebot:printf("\nPlayer Turn");
    printf("\n\nRock 1\nPaper 2\nScissor 3\n:");
    scanf("%d",&player1choice);
    printf("\n");
    //bot random
    int upper = 3,lower = 1;
    srand(time(NULL));
    botchoice = (rand() % (upper - lower + 1)) + lower;
    printf("Bot has choosed: %d",botchoice);
    //player1 rock
    beat = 0;
    calc:if(player1choice == 1){
        if(botchoice == 1){
            goto botdraw;
        } else if(botchoice == 2){
            goto botwin;
        } else if(botchoice == 3){
            goto botplayer1win;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
        //player1 paper
    }else if(player1choice == 2){
        if(botchoice == 1){
            goto botplayer1win;
        }else if(botchoice == 2){
            goto botdraw;
        }else if(botchoice == 3){
            goto botwin;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
        //player1 scissor
    }else if(player1choice == 3){
        if(botchoice == 1){
            goto botwin;
        }else if(botchoice == 2){
            goto botplayer1win;
        }else if(botchoice == 3){
            goto botdraw;
        }else{
            printf("\nProgram has failed to calcurate :(\n");
            goto exit;
        }
    }else{
        printf("\nProgram has failed to calcurate :(\n");
        goto exit;
    }
    //score calculation
    botplayer1win:printf("\n\nPlayer 1 has win\n");
    player1score = player1score + 1;
    printf("Score: Player1: %d Bot: %d",player1score,botscore);
    if(player1score == score){
        goto botwinmessage;
    }else{
        goto scorebot;
    }

    botwin:printf("\n\nBot has win\n");
    botscore = botscore + 1;
    printf("Score: Player1: %d Bot: %d",player1score,botscore);
    if(botscore == score){
        goto botwinmessage;
    }else{
        goto scorebot;
    }

    botdraw:printf("\nBoth players have drawed, No one get score\n");
    goto scorebot;

    //win message
    botwinmessage:
    if(player1score == score){
        printf("\n\n\n\n\n\n\n\nCongratulations!!!!\nPlayer1 has win this game of Rock Paper Scissor!!!");
        printf("\nWith score of: Player1: %d Bot: %d",player1score,botscore);
        printf("\nGG\n");
        player1score = 0;
        botscore = 0;
        goto back;
    }else if(botscore == score){
        printf("\n\n\n\n\n\n\n\nCongratulations!!!!\nBot has win this game of Rock Paper Scissor!!!");
        printf("\nWith score of: Player1: %d Bot: %d",player1score,botscore);
        printf("\nGG\n");
        player1score = 0;
        botscore = 0;
        goto back; 
    }else{
        printf("\nProgram has failed to calcurate :(\n");
        goto exit;
    }
    realexit:printf("\nDone!");

}