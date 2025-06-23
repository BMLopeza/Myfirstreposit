// Quiz Game

#include <stdio.h>
#include <ctype.h> // this one is used for adding the toupper fuctions to create uppercase

int main(){

    char questions[][100]={"What is C?\n",
                           "What is a char?\n",
                           "What is a array?\n",
                        }; // This is a 2D array a list of strings actually, each string is a question
                        // questions[][100] measn that multiple string (up to 100 charates each) we can also change this if we want to

char options[][100]= {"A. Is a character", "B. Is a letter of the alphabet", "C. Is a language programm\n",
                      "A. It's a fuction\n", "B. It's a variable", "C. It's a data type\n",
                      "A. It's stored the same data type", "B. It's stored different data types", "C. It's stored a single data type\n"};
                      //Declaration options up there
char answers[3] = { 'A', 'C', 'A'};
//Declaring the correct Answers

int numberofquestions = sizeof(questions)/ sizeof(questions[0]);

char guess;
int score = 0;

printf("QUIZ Game\n"); // to initiate the game

for(int i = 0; i <numberofquestions; i++){ // this loop repeats for each questions (3 times actually )
// i is the index of the current question so it's used to access to the questions and answers, 
    printf("****************************\n");
    printf("%s", questions[i]); //this is to printf the part of the questions
    printf("****************************\n");
    
    //This one is used to print the options available 
for(int j =(i * 4); j <(i *4) + 3; j++){
    printf("%s\n", options[j]);
}
// this one take a character input like 'A', 'B', 
printf("guess: ");
scanf("%c", &guess);
scanf("%*c"); // to clear the newline character from the input buffer

// this is used to convert the input to uppercase, in summary, it's to get either A, C, or B
// so if the user inputs 'a' it will be converted to 'A'
guess = toupper(guess);

//To check the answer: 
if (guess == answers[i]){ // i is used because yo
    printf("Correct!\n");
    score++; //if the answer is correct, we increase the score by 1;
} else{
    printf("Wrong!\n");
}
}
printf("****************************\n");
printf("Your score is: %d/%d", score, numberofquestions);
printf("\n****************************\n");


return 0;
}

/*Think of it like this:
Box Number (i)	Question	Answer in Box

0	           What is C?	        A
1	           What is a char?	    C
2	           What is an array? 	A

The program goes one box at a time — when it opens box 1 (i = 1),
it uses the question from box 1 and expects the answer from box 1 (answers[1]).*/