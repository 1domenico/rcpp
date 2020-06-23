#include <Rcpp.h>
#include <numeric>
#include <math.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//




// [[Rcpp::export]]
NumericVector cumsum1(NumericVector x) {
  double acc = 0; // init an accumulator
  NumericVector res(x.size()); // init vector res with same size of x
  for (int i = 0; i<x.size(); i++) {
    acc += x[i];
    res[i] = acc;
  }
  return res;
}

// [[Rcpp::export]]
NumericVector cumsum2(NumericVector x) {
  double acc = 0; // init an accumulator
  NumericVector res(x.size()); // init vector res with same size of x
  for (int i = 0; i<x.size(); i++) {
    if (x[i]>0){
    acc += x[i];
      }
    res[i] = acc;
  }
  return res;
}

// [[Rcpp::export]]
int test_fun1(int a, 
              Nullable <IntegerVector> b = R_NilValue,
              Nullable <IntegerVector> c = R_NilValue){
  if (b.isNotNull() && c.isNotNull()){
    return 3;
  }else{
    if (b.isNotNull()){
    return 1;
    }else{
      if (c.isNotNull()){
        return 2;
      }
    }
  }
  return 0;
  
}



// [[Rcpp::export]]
NumericVector test_fun2(NumericVector a, 
                        NumericVector b ){ 
  //int n = a.size();
  // NumericVector c (1);
  // c[0] = fmin(a[0],b[0]);
  
  return cbind(a,b);
}


NumericVector internal_fun (NumericVector x){
  double acc = 0; // init an accumulator
  NumericVector res(x.size()); // init vector res with same size of x
  for (int i = 0; i<x.size(); i++) {
    acc += x[i];
    res[i] = acc;
  }
  return res;
}

// [[Rcpp::export]]
NumericVector test_fun3(NumericVector a ){ 
  int n = a.size();
  int m = 0;
  
  for (int j=0; j<n-1;j++){
    if(  fmod (a[j] ,2) ==0 ){
      m++;
    }
  }
  
  NumericVector c (m);
  
  for (int j=0; j<n-1;j++){
    c[j] = a[j] * 2;
  }
  //c = internal_fun(a);
  return c;
}



// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/* R
timesTwo(42)
*/
