/*
 * Program2.c
 *
 *  Created on: Feb 8, 2023
 *      Author: h232m035
 */

void displayScores(int TD, int TP, int EP, int FG, int S){
	printf("%d TD + 2pt, ", TP);
	printf("%d TD + FG, ", EP);
	printf("%d TD, ", TD - TP - EP);
	printf("%d 3pt FG, ", FG);
	printf("%d Safety\n", S);
}

int main(){
	printf("Enter 0 or 1 to STOP\n");
	int running = 1;
	int scoreIn = 0;
	int foundScore = 0;
	while (running){
		printf("Enter the NFL score: ");
		scanf("%d", &scoreIn);
		printf("\n");
		if (scoreIn < 2){
			printf("Exiting program.");
			running = 0;
			break;
		}
		//now, run the program
		foundScore = 0;
		printf("possible combinations of scoring plays: ");
		for (int TDs = 0; TDs * 6 <= scoreIn; TDs++){
			//now, cycle through each combination of TD-after plays
			for (int EPs = 0; TDs * 6 + EPs <= scoreIn && EPs <= TDs; EPs++){
				for (int TPs = 0; TDs * 6 + EPs + 2 * TPs <= scoreIn && EPs + TPs <= TDs; TPs++){
					//get each combination of safeties
					for (int S = 0; TDs * 6 + EPs + TPs * 2 + S * 2 <= scoreIn; S++){
						//get each combination of field goals
						for (int FGs = 0; TDs * 6 + EPs + TPs * 2 + S * 2 + FGs * 3 <= scoreIn; FGs++){
							//check if the score is valid
							if (TDs * 6 + EPs + TPs * 2 + S * 2 + FGs * 3 == scoreIn){
								foundScore = 1;
								displayScores(TDs, TPs, EPs, FGs, S);
							}
						}
					}
				}
			}
		}

		if (!foundScore){
			printf("(no combination make this score.)");
		}
		printf("\n");
	}
}
