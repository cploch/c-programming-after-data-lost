#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double computeBalance(double contribution, double rate_of_return, double balance){
  balance = balance + balance*rate_of_return + contribution;
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double balance = initial;
  for (int month = startAge; month < (startAge + working.months + retired.months); month ++){
    printf("Age %3d month %2d you have $%.2lf\n", month/12 , month%12, balance);
    if (month < (startAge + working.months) ){
      balance = computeBalance(working.contribution, working.rate_of_return, balance);
    }
    else{
      balance = computeBalance(retired.contribution, retired.rate_of_return, balance);
    }
  }
}

int main( ){

  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12; //per month

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12; //per month

  int  startAge = 327; //months
  double  initial = 21345; //dollars

  //compute retirement
  retirement(startAge, initial, working, retired);
  return 0;
}
