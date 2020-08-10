#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool distinguish(double x, double y){
	if(fabs(x - y) < 0.088){
		return false;
	}else{
		return true;
	}
}

int main(){
	double rssi[15] = {3.705, 4.405, 5.005, 5.505, 6.205, 6.805, 7.405, 8.005, 8.605, 9.205, 10.805, 11.405, 12.605, 13.705, 14.405};

	double rssi_combination[28];
	rssi_combination[0] = rssi[0] + rssi[0] + rssi[0];//0 0 0 (0)
	rssi_combination[1] = rssi[0] + rssi[0];//0 0 (0123456)
	rssi_combination[2] = rssi[0] + rssi[1];//0 1 (012345)
	rssi_combination[3] = rssi[0] + rssi[2];//0 2 (01234)
	rssi_combination[4] = rssi[0] + rssi[3];//0 3 (0123)
	rssi_combination[5] = rssi[0] + rssi[4];//0 4 (012)
	rssi_combination[6] = rssi[0] + rssi[5];//0 5 (01)
	rssi_combination[7] = rssi[0] + rssi[6];//0 6 (0)
	rssi_combination[8] = rssi[1] + rssi[1];//1 1 (0123)
	rssi_combination[9] = rssi[1] + rssi[2];//1 2 (0123)
	rssi_combination[10] = rssi[1] + rssi[3];//1 3 (012)
	rssi_combination[11] = rssi[1] + rssi[4];//1 4 (0)
	rssi_combination[12] = rssi[1] + rssi[5];//1 5 (0)
	rssi_combination[13] = rssi[2] + rssi[2];//2 2 (01)
	rssi_combination[14] = rssi[2] + rssi[3];//2 3 (01)
	rssi_combination[15] = rssi[2] + rssi[4];//2 4 (0)
	rssi_combination[16] = rssi[3] + rssi[3];//3 3 (0)
	rssi_combination[17] = rssi[0];//0 (0123456789\10)
	rssi_combination[18] = rssi[1];//1 (0123456789)
	rssi_combination[19] = rssi[2];//2 (0123456789)
	rssi_combination[20] = rssi[3];//3 (0123456789)
	rssi_combination[21] = rssi[4];//4 (012345678)
	rssi_combination[22] = rssi[5];//5 (01234567)
	rssi_combination[23] = rssi[6];//6 (0123456)
	rssi_combination[24] = rssi[7];//7 (012345)
	rssi_combination[25] = rssi[8];//8 (01234)
	rssi_combination[26] = rssi[9];//9 (0123)
	rssi_combination[27] = rssi[10];//10 (0)
	for(int i = 0; i < 28; i++){
		for(int j = i+1; j < 28; j++){
			if(!distinguish(rssi_combination[i], rssi_combination[j])){
				printf("The difference of combination %d and %d is %lf, which is smaller than 0.088\n", i, j, fabs(rssi_combination[i] - rssi_combination[j]));	
			}
		}
	}
	return 0;
}
