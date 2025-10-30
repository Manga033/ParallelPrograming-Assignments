#ifndef SUM_ALGORITHMS_H
#define SUM_ALGORITHMS_H

double do_sum(double* restrict var, long ncells);
double do_ldsum(double* var, long ncells);
double do_pair_sum(double* var, long ncells);
double do_kahan_sum(double* var, long ncells);
double do_knuth_sum(double* var, long ncells);

#endif