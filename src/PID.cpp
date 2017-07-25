#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  total_updates = 0;
  lowest_error = numeric_limits<double>::max();
  dp = {1.0, 1.0, 1.0};
  p = {this->Kp, this->Ki, this->Kd};
}

void PID::UpdateError(double cte) {
  // differential error
  d_error = cte - p_error;
  // prev error
  p_error = cte;
  // integral error
  i_error += cte;

  total_updates += 1;
}

double PID::TotalError() {
  double error = -(Kp*p_error) - (Kd*d_error) - (Ki*i_error);
  return error;
}

double PID::TwiddleError(double p []){
  double error = -(p[0]*p_error) - (p[1]*i_error) -(p[2]*d_error);
  error = (cte*cte + error*error) / total_updates;
  return error;
}

void PID::Twiddle(){
  double tol = 0.2;
  dp[0] = Kp/10.0;
  dp[1] = 0.0;
  dp[2] = Kd/10.0;
  int i = 0;

  // lowest estimate for error so far
  lowest_error = TwiddleError(p);

  while(dp[0] + dp[1] + dp[2] > tol) {
    cout << "Twiddle iteration: " << i << "; lowest error= " << lowest_error << endl;
    cout << "Kp " << p[0] << " Ki " << p[1] << " Kd " << Kd << endl;
    cout << "dKp " << dp[0] << " dKi " << dp[1] << " dKd " << dp[2] << endl;

    for(int j=0; j < p.size(); j++){
      p[j] += dp[j];

      double error = TwiddleError(p);
      error *= error;

      if(error < lowest_error){
	lowest_error = error;
	dp[j] *= 1.1;
      } else {
	p[j] -= 2*dp[j];
	error = TwiddleError(p);
	error *= error;

	if (error < lowest_error){
	  lowest_error = error;
	  dp[j] *= 1.1;
	}else {
	  p[j] += dp[j];
	  dp[j] *= 0.9;
	}
      }
    }
    i++;
  }

  Kp = p[0];
  Ki = p[1];
  Kd = p[2];

}
