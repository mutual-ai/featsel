//
// SpecCMI.h -- definition of the class "SpecCMI".
//
//    This file is part of the featsel program
//    Copyright (C) 2017  Marcelo S. Reis
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

// Original algorithm published in:
//
// Nguyen, X.V. and Chan, J. and Romano, S. and Bailey, J. (2014).
// "Effective Global Approaches for Mutual Information Based Feature Selection".
// Proceedings of the 20th ACM SIGKDD International Conference
// on Knowledge Discovery and Data Mining (KDD 2014).


# ifndef SPECCMI_H_
# define SPECCMI_H_

# include "../global.h"
# include "../Solver.h"
# include "../ElementSubset.h"

# include "../functions/ConditionalMutualInformation.h"

// Precision of the Rayleigh quotient iteration.
//
# define EPSILON 0.001

// Maximum number of iterations of the Rayleigh quotient iteration algorithm.
// IMPORTANT: It seems that the original Xuan Vinh code (2014) indeed iterates
// only once!
//
# define MAX_NUM_ITER 100

// If true, print for each feature index its respective ranking.
//
# define PRINT_FEATURE_RANKING true

// If true, it prints the Q matrix.
//
# define PRINT_Q_MATRIX false

// If true, it stores the chain of best subset between
// 
// \emptyset <= X_1 <= \ldots <= X_k, |X_1| = 1, \ldots |X_k| = k.
//
# define PRINT_SUBSET_CHAIN false

// If true, it uses the GNU Octave to compute the dominant eigenvalue;
// otherwise it uses a local implementation of the Rayleigh algorithm.
//
# define USE_OCTAVE_API true

class SpecCMI : public Solver
{

private:

  // Cost function employed to build the Hessian Q matrix.
  //
  ConditionalMutualInformation * cmi;

  // Number of best-ranked features to be selected in order to compose the
  // output feature subset.
  //
  unsigned int k;

  // Symmetric matrix containing the pairwise conditional mutual information,
  // as described in Xuan Vinh et al. (2014).
  //
  double ** Q;

  // Compute the inverse of a matrix A using Gauss--Jordan elimination method.
  // To this end, it receives A augmented by the column vector b of size n,
  // and returns:
  //
  // * a pointer to a vector x, a solution for the linear equation Ax = b;
  // 
  // * NULL, if the matrix A is singular.
  //
  double * Gauss_Jordan_elimination (unsigned int n, double ** A);

  // It prints the Q matrix into STDOUT.
  //
  void print_Q_matrix (void);

  // Execute the Rayleigh quotient iteration algorithm on matrix Q,
  // with precision epsilon, maximum number of iterations max_num_iter and x as 
  // initial guess for a dominant eigenvector.
  //
  double * Rayleigh (double epsilon, double mu, double * x);

  // Alternative to the method above, that uses the "eigs" function in GNU
  // Octave to compute directly the dominant eigenvalue and returns a positive
  // eigenvector associated to it.
  //  
  double * Octave_dominant_eigenvalue (void);

public:

  // Default constructor.
  //
  SpecCMI ();


  // Constructor that loads the number k of best ranked features that should.
  // compose the feature subset.
  //
  SpecCMI (unsigned int number_of_features);


  // Default destructor.
  //
  virtual ~SpecCMI ();

  // Run the algorithm, getting up to 'max_size_of_minima_list' minima.
  //
  void get_minima_list (unsigned int);

  // Compute and return a unit-norm eigenvector whose corresponding eigenvalue 
  // is the dominant eigenvalue of Q, that is, the largest eigenvalue of Q.
  //
  double * rank_features ();

  // Compute the symmetric matrix Q of the quadratic term.
  //
  void compute_Q_matrix ();
  
  // Return the value Q[i][j].
  //
  double get_Q_matrix_value (unsigned int i, unsigned int j);

  // It stores 'value' into Q[i][j].
  //
  void put_Q_matrix_value (unsigned int i, unsigned int j, double value);

};

#endif /* SPECCMI_H_ */

