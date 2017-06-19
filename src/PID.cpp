#include "PID.h"
#include <iostream>
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    //initialising coefficiants
    this->Kp=Kp;
    this->Ki=Ki;
    this->Kd=Kd;
    // initialising errors
    p_error=0.0;
    i_error = 0;
   	d_error = 0;
}

void PID::UpdateError(double cte) {
    
    //proportional error 
    this->p_error=this->Kp*(cte);

    //differential error
    double prev_cte=this->p_error; 
    this->d_error=this->Kd*(p_error-prev_cte);

    //integral error 
    this->i_error = this->Ki*(this->i_error +cte);
    //steering= -tau_p*cte-tau_d*cte_d-tau_i*int_cte

}

double PID::TotalError() {
    return -this->Kp*p_error-this->Kd*d_error-this->Ki*i_error;
}


