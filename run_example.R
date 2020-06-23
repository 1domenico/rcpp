library(Rcpp)

Rcpp::sourceCpp('~/R/cpp/example.cpp')

x <- cumsum1(1:10)
