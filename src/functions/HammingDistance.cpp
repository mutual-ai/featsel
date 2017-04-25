//
// HammingDistance.cpp -- implementation of the class "HammingDistance".
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

#include "HammingDistance.h"


HammingDistance::HammingDistance (ElementSet * a_set)
{
  set = a_set;
}


HammingDistance::~HammingDistance ()
{
  // Empty destructor.
}


double HammingDistance::cost (ElementSubset * X)
{
  timeval begin, end;
  gettimeofday (& begin, NULL);
  double cost = 0;
  number_of_calls_of_cost_function++;

  //

  unsigned int i;
  Element * elem;

  if (! (X->get_set_cardinality() == 0))
  {
    for (i = 0; i < set->get_set_cardinality (); i++)
    {
      elem = set->get_element (i);
      if (((elem->get_element_value (0) == 1) && (!X->has_element (i))) ||
	  ((elem->get_element_value (0) == 0) && (X->has_element (i))))
        cost++;
    }
  }

  //

  gettimeofday (& end, NULL);
  elapsed_time_of_all_calls_of_the_cost_function += diff_us (end, begin);

  // Threshold is a maximum number of calls of the cost function
  //
  if ((has_max_number_of_calls_set) &&
      (number_of_calls_of_cost_function >=
       max_number_of_calls_of_cost_function))
    reached_threshold = true;

  return cost;
}
