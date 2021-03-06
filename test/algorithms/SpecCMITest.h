// SpecCMITest.h automatically generated by bin/add_new_algorithm.pl
// in Wed Feb  8 05:39:58 2017.

//
// SpecCMITest.h -- definition of the namespace "SpecCMITest".
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

# ifndef SPECCMITEST_H_
# define SPECCMITEST_H_

# include "../../src/algorithms/SpecCMI.h"

# include "../../src/functions/Explicit.h"
# include "../../src/functions/ConditionalMutualInformation.h"

namespace SpecCMITest
{

  bool it_should_compute_the_Q_matrix ();

  bool it_should_return_a_correct_solution_for_the_example_in_NX_Vinh_et_al ();
  
  // bool it_should_converge_for_instances_with_hundreds_of_features ();

  // bool it_should_converge_for_instances_with_thousands_of_features ();

}

# endif /* SPECCMITEST_H_ */
