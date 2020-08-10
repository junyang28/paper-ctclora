#include <stdio.h>
int main(){
	double rssi[15] = {3.705, 4.405, 5.005, 5.505, 6.205, 6.805, 7.405, 8.005, 8.605, 9.205, 10.805, 11.405, 12.605, 13.705, 14.405};
	//for(int i = 0; i < 15; i ++){printf("%lf ",rssi[i]);}
	//printf("\n");
	//int counter4, counter3, counter2, counter1 = 0;
	printf("=========\n");
	printf("=Level 4=\n");
	int counter4 = 0;
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			for(int k = 0; k < 15; k++){
				for(int l = 0; l < 15; l++){
					if(rssi[i] + rssi[j] + rssi[k] + rssi[l] <= 15.0){
						printf("%d %d %d %d\n", i, j, k, l);
						counter4++;
					}
				}
			}
		}
	}
	printf("%d\n", counter4);
	
	printf("=========\n");
	printf("=Level 3=\n");
	int counter3 = 0;
	for(int i = 0; i < 15; i++){
                for(int j = 0; j < 15; j++){
                        for(int k = 0; k < 15; k++){
                                //for(int l = 0; l < 15; l++){
                                        if(rssi[i] + rssi[j] + rssi[k] <= 15.0){
                                                printf("%d %d %d\n", i, j, k);
                                                counter3++;
                                        }
                                //}
                        }
                }
        }
        printf("%d\n", counter3);

	printf("=========\n");
        printf("=Level 2=\n");
	int counter2 = 0;
        for(int i = 0; i < 15; i++){
                for(int j = 0; j < 15; j++){
                        //for(int k = 0; k < 15; k++){
                                //for(int l = 0; l < 15; l++){
                                        if(rssi[i] + rssi[j] <= 15.0){
                                                printf("%d %d\n", i, j);
                                                counter2++;
                                        }
                                //}
                        //}
                }
        }
        printf("%d\n", counter2);

	printf("=========\n");
        printf("=Level 1=\n");
	int counter1 = 0;
        for(int i = 0; i < 15; i++){
                //for(int j = 0; j < 15; j++){
                        //for(int k = 0; k < 15; k++){
                                //for(int l = 0; l < 15; l++){
                                        //if(rssi[i] + rssi[j] <= 15.0){
                                                printf("%d\n", i);
                                                counter1++;
                                        //}
                                //}
                        //}
                //}
        }
        printf("%d\n", counter1);
	printf("=========\n");
	printf("Total Combination of RSSI is %d\n", counter4 + counter3 + counter2 + counter1);



	int new_count = 0;
	for(int i = 0; i < 15; i++){
		new_count++;
		for(int j = 0; j < 15; j++){
			if(rssi[i] + rssi[j] <= 15.0){
				//printf("%d %d %d %d\n", i, j, k, l);
				new_count++;
			}
			for(int k = 0; k < 15; k++){
				if(rssi[i] + rssi[j] + rssi[k] <= 15.0){
					//printf("%d %d %d %d\n", i, j, k, l);
					new_count++;
				}
				for(int l = 0; l < 15; l++){
					if(rssi[i] + rssi[j] + rssi[k] + rssi[l] <= 15.0){
						//printf("%d %d %d %d\n", i, j, k, l);
						new_count++;
					}
				}
			}
		}
	}


	printf("Total Combination of RSSI is %d\n", new_count);





	return 0;
}
