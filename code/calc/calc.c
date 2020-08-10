#include <stdio.h>
#include <math.h>

double max(double a, double b){
	return a > b ? a : b;
}
double calc_payload_symbol(double pl, double sf, double cr){
	//return 8.0 + max((ceil((8 * (11 + pl) - 4 * sf + 24) / (4 * sf))) * cr , 0);
	return 8.0 + max((ceil((8 * (11 + pl) - 4 * 5 + 24) / (4 * 5))) * 4/5 , 0);
}


int main(){
	double pl, sf, cr, bw;
	double timeslot = 0.0882353;
	//printf("%lf\n", timeslot);
	while(1){
		//printf("\n");
		printf(">>input format:Payload SF CR BW\n");
		printf(">>input 5 if CR = 1 and CR fraction is 4/5\n");
		scanf("%lf %lf %lf %lf", &pl, &sf, &cr, &bw);
		double Npayload = calc_payload_symbol(pl, sf, cr);
		double Tsymbol = pow(2, sf) / bw;
		double Time_on_Air = (Npayload + 12.25) * Tsymbol;
		printf("Total theoretical time on air is \n%lf\n", Time_on_Air);
		double datapoint = Time_on_Air / timeslot;
		//printf("%lf\n", datapoint);
		printf("Probable data point will be \n%lf~%lf\n==========================================\n", floor(Time_on_Air/timeslot), ceil(Time_on_Air/timeslot));
	}
	return 0;
}




/*
Time on Air = T preamble + T payload
with
Tpreamble= (NbPreamble (8) + (symbols added by radio)4,25) x Tsymbol
and
Tpayload = NbPayloadSymbol x Tsymbol

Tsymbol = 2^SF/BW

NPayload = 8 + max(ceil((8*(8+pl)-4*sf+24)/4*sf)*cr, 0)
*/
