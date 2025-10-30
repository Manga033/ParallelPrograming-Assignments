I have successfuly implemented from our book for Long Double, Pairwise, Kahan, and Knuth summation methods. In main.c I have added a generic test function for all these summation methods. This needed to be implemented so we could see the differences and compare all the methods. 

In the Makefile I have added -lm to allow the use of mathematical functions (pow, log2).

What can we conclude based on the tests: 
Long Double summation method produces errors. This is because it sums the numbers sequentially without any mechanism for error correction. 
Kahan and Knuth summation methods implement error compensation, which improves their accuracy. 
The Pairwise summation method also maintains accuracy by recursively splitting the sum into smaller parts, reducing the accumulation of rounding errors. 

The global sum problem presents a major problem that affects the parallelization. This finite-precision arithmetic is non-associative, meaning that the order in which numbers are summarized affects the result, but the parallel calculation is changing that order, which means that the result may not match the true sum. The worst case is adding floating-point numbers that are almost identical but with the different signs. 

Spreadsheet link: 

https://docs.google.com/spreadsheets/d/1_WZI7SQ46IlgbrQTdLU9K2ZDMoPkQdqn_qf3wEcJqGk/edit?usp=sharing