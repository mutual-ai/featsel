//============================================================================
//
//    featselTest.cpp -- Unit tests of the featsel classes.
//
//    This file is part of the featsel program
//    Copyright (C) 2016  Marcelo S. Reis
//
//
//   If you use featsel in your publication, we kindly ask you to acknowledge us
//   by citing the paper that describes this framework:
//
//   M.S. Reis, G. Estrela, C.E. Ferreira and J. Barrera
//   "featsel: A Framework for Benchmarking of
//   Feature Selection Algorithms and Cost Functions"
//   https://github.com/msreis/featsel
//
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
//============================================================================


// Special data structures
//
#include "ElementTest.h"
#include "ElementSetTest.h"
#include "ElementSubsetTest.h"
#include "CollectionTest.h"
#include "ROBDDTest.h"
#include "PartitionTest.h"
#include "PartitionNodeTest.h"

// Cost (objective) functions
//
#include "functions/ExplicitTest.h"
#include "functions/MeanConditionalEntropyTest.h"
#include "functions/HammingDistanceTest.h"
#include "functions/SubsetSumTest.h"
#include "functions/MutualInformationTest.h"
#include "functions/ConditionalMutualInformationTest.h"
#include "functions/PartCostTest.h"

// Solvers (algorithms)
//
#include "algorithms/UcurveBranchandBoundTest.h"
#include "algorithms/ExhaustiveSearchTest.h"
#include "algorithms/SFSTest.h"
#include "algorithms/SFFSTest.h"
#include "algorithms/PUCSTest.h"
#include "algorithms/UCurveSearchTest.h"
#include "algorithms/SpecCMITest.h"
#include "algorithms/UCurveToolBoxTest.h"

// Number of passed and failed tests
//
unsigned int number_of_passed_tests = 0;
unsigned int number_of_failed_tests = 0;

string current_class;

void result (string test_name, bool passed)
{
  cout << current_class << "::" << test_name;
  cout.flush ();

  if (passed)
  {
    cout << " OK\n";
    number_of_passed_tests++;
  }
  else
  {
    cout << " FAILED\n";
    number_of_failed_tests++;
  }
}

int main (void)
{
  cout << endl << "Starting Unit Tests... " << endl << endl;

  // Testing Class "Element"
  //
  current_class = "ElementTest";
  result ("an_element_should_have_a_name",
    ElementTest::an_element_should_have_a_name ());
  result ("a_new_element_should_not_have_added_values",
    ElementTest::a_new_element_should_not_have_added_values ());
  result ("an_element_without_all_values_added_should_allow_adding",
    ElementTest::an_element_without_all_values_added_should_allow_adding ());
  result ("an_element_with_all_values_added_should_not_allow_adding",
    ElementTest::an_element_with_all_values_added_should_not_allow_adding ());
  result ("an_added_value_should_be_found",
    ElementTest::an_added_value_should_be_found ());
  cout << endl;

  // Testing Class "ElementSet"
  //
  current_class = "ElementSetTest";
  result ("a_set_should_have_a_name",
    ElementSetTest::a_set_should_have_a_name ());
  result ("an_empty_set_should_not_have_elements",
    ElementSetTest::an_empty_set_should_not_have_elements ());
  result ("it_should_load_data_of_a_set_from_file",
    ElementSetTest::it_should_load_data_of_a_set_from_file ());
  result ("it_should_load_data_of_a_set_from_a_DAT_file",
    ElementSetTest::it_should_load_data_of_a_set_from_a_DAT_file ());
  result ("it_should_create_a_set_with_random_values",
    ElementSetTest::it_should_create_a_set_with_random_values ());
  result ("it_should_return_the_set_cardinality",
    ElementSetTest::it_should_return_the_set_cardinality ());
  result ("it_should_return_an_element_that_belongs_to_the_set",
    ElementSetTest::it_should_return_an_element_that_belongs_to_the_set ());
  result ("it_should_not_return_an_element_that_not_belongs_to_the_set",
    ElementSetTest::
    it_should_not_return_an_element_that_not_belongs_to_the_set ());
  result ("values_from_a_random_set_should_be_within_the_given_range",
    ElementSetTest::
    values_from_a_random_set_should_be_within_the_given_range ());
  cout << endl;

  // Testing Class "ElementSubset"
  //
  current_class = "ElementSubsetTest";
  result ("a_new_subset_should_be_an_empty_set",
    ElementSubsetTest::a_new_subset_should_be_an_empty_set ());
  result ("an_element_not_in_subset_should_be_added",
    ElementSubsetTest::an_element_not_in_subset_should_be_added ());
  result ("an_element_in_subset_should_be_removed",
    ElementSubsetTest::an_element_in_subset_should_be_removed ());
  result ("it_should_give_the_set_that_belongs_the_subset",
    ElementSubsetTest::it_should_give_the_set_that_belongs_the_subset ());
  result ("a_set_should_contains_its_subset",
    ElementSubsetTest::a_set_should_contains_its_subset ());
  result ("a_subset_should_be_contained_by_its_set",
    ElementSubsetTest::a_subset_should_be_contained_by_its_set ());
  result ("a_subset_should_be_successfully_cloned",
    ElementSubsetTest::a_subset_should_be_successfully_cloned ());
  result ("a_random_element_should_be_removed",
    ElementSubsetTest::a_random_element_should_be_removed ());
  result ("it_should_give_the_complement_of_the_set",
    ElementSubsetTest::it_should_give_the_complement_of_the_set ());
  cout << endl;

  // Testing Class "Collection"
  //
  current_class = "CollectionTest";
  result ("a_lower_covered_subset_should_be_found",
    CollectionTest::a_lower_covered_subset_should_be_found ());
  result ("a_non_lower_covered_subset_should_not_be_found",
    CollectionTest::a_non_lower_covered_subset_should_not_be_found ());
  result ("it_should_remove_lower_covered_subsets_in_a_collection",
    CollectionTest::it_should_remove_lower_covered_subsets_in_a_collection ());
  result ("the_evaluated_subset_should_not_be_deleted",
    CollectionTest::the_evaluated_subset_should_not_be_deleted ());
  result ("an_upper_covered_subset_should_be_found",
    CollectionTest::an_upper_covered_subset_should_be_found ());
  result ("a_non_upper_covered_subset_should_not_be_found",
    CollectionTest::a_non_upper_covered_subset_should_not_be_found ());
  result ("it_should_remove_upper_covered_subsets_in_a_collection",
    CollectionTest::it_should_remove_upper_covered_subsets_in_a_collection ());
  result ("it_should_copy_a_collection",
    CollectionTest::it_should_copy_a_collection ());
  cout << endl;

  // Testing Class "ROBDD"
  //
  current_class = "ROBDDTest";
  result ("ROBDDTest::a_new_robdd_has_only_a_terminal_node",
    ROBDDTest::a_new_robdd_has_only_a_terminal_node ());
  result ("ROBDDTest::the_union_of_a_new_robdd_with_itself_should_be_itself",
    ROBDDTest::the_union_of_a_new_robdd_with_itself_should_be_itself ());
  result ("ROBDDTest::the_union_of_all_subsets_must_be_the_function_1",
    ROBDDTest::the_union_of_all_subsets_must_be_the_function_1 ());
  result ("ROBDDTest::a_new_robdd_contais_no_subset",
    ROBDDTest::a_new_robdd_contais_no_subset ());
  result ("ROBDDTest::an_added_subset_must_be_covered",
    ROBDDTest::an_added_subset_must_be_covered ());
  result ("ROBDDTest::the_function_one_covers_all_subsets",
    ROBDDTest::the_function_one_covers_all_subsets ());
  result ("ROBDDTest::the_function_one_have_no_subset_evaluated_zero",
    ROBDDTest::the_function_one_have_no_subset_evaluated_zero ());
  result ("ROBDDTest::its_possible_to_get_a_random_subset_evaluated_zero",
    ROBDDTest::its_possible_to_get_a_random_subset_evaluated_zero ());
  result ("ROBDDTest::it_should_be_able_to_reduce_an_obdd",
    ROBDDTest::it_should_be_able_to_reduce_an_obdd ());
  result ("ROBDDTest::it_should_be_able_to_add_a_subset",
    ROBDDTest::it_should_be_able_to_add_a_subset ());
  cout << endl;

  // Testing Class Partition
  //
  current_class = "PartitionTest";
  result ("PartitionTest::it_should_create_the_fixed_elm_set",
    PartitionTest::it_should_create_the_fixed_elm_set ());
  result ("PartitionTest::it_should_create_the_unfixed_elm_set",
    PartitionTest::it_should_create_the_unfixed_elm_set ());
  cout << endl;

  // Testing Class PartitionNode
  current_class = "PartitionNodeTest";
  result ("PartitionNodeTest::it_map_subsets_correctly",
    PartitionNodeTest::it_map_subsets_correctly ());
  result ("PartitionNodeTest::it_should_check_upper_adjacent_parts",
    PartitionNodeTest::it_should_check_upper_adjacent_parts ());
  result ("PartitionNodeTest::it_should_return_the_least_subset",
    PartitionNodeTest::it_should_return_the_least_subset ());
  result ("PartitionNodeTest::it_should_return_the_greatest_subset",
    PartitionNodeTest::it_should_return_the_greatest_subset ());
  cout << endl;

  /*
  //Testing class "Explicit"
  //
  current_class = "ExplicitTest";
  result ("an_empty_set_should_have_cost_zero",
    ExplicitTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    ExplicitTest::it_should_add_and_retrieve_the_elapsed_time ());
  result ("it_should_works_with_an_explicitly_declared_cost_function",
    ExplicitTest::it_should_works_with_an_explicitly_declared_cost_function ());
  cout << endl;

  //Testing class "MeanConditionalEntropy"
  //
  current_class = "MeanConditionalEntropyTest";
  result ("an_empty_set_should_have_cost_zero",
    MeanConditionalEntropyTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    MeanConditionalEntropyTest::it_should_add_and_retrieve_the_elapsed_time ());
  result ("it_should_store_the_frequencies_of_the_samples",
    MeanConditionalEntropyTest::it_should_store_the_frequencies_of_the_samples ());
  result ("it_should_store_the_label_frequencies_of_the_samples",
    MeanConditionalEntropyTest::it_should_store_the_label_frequencies_of_the_samples ());
  result ("it_should_calculate_the_conditional_entropy",
    MeanConditionalEntropyTest::it_should_calculate_the_conditional_entropy ());
  result ("it_should_calculate_the_mean_conditional_entropy",
    MeanConditionalEntropyTest::it_should_calculate_the_mean_conditional_entropy ());
  cout << endl;

  //Testing class "HammingDistance"
  //
  current_class = "HammingDistanceTest";
  result ("an_empty_set_should_have_cost_zero",
    HammingDistanceTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    HammingDistanceTest::it_should_add_and_retrieve_the_elapsed_time ());
  result ("it_should_give_the_hamming_distance_cost_of_a_subset",
    HammingDistanceTest::it_should_give_the_hamming_distance_cost_of_a_subset ());
  cout << endl;

  //Testing class "SubsetSum"
  //
  current_class = "SubsetSumTest";
  result ("an_empty_set_should_have_cost_zero",
    SubsetSumTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    SubsetSumTest::it_should_add_and_retrieve_the_elapsed_time ());
  result ("it_should_give_the_subset_sum_cost_of_a_subset",
    SubsetSumTest::it_should_give_the_subset_sum_cost_of_a_subset ());
  cout << endl;

  //Testing class "MutualInformation"
  //
  current_class = "MutualInformationTest";
  result ("an_empty_set_should_have_cost_zero",
    MutualInformationTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    MutualInformationTest::it_should_add_and_retrieve_the_elapsed_time ());
  cout << endl;

  //Testing class "ConditionalMutualInformation"
  //
  current_class = "ConditionalMutualInformationTest";
  result ("an_empty_set_should_have_cost_zero",
    ConditionalMutualInformationTest::an_empty_set_should_have_cost_zero ());
  result ("it_should_add_and_retrieve_the_elapsed_time",
    ConditionalMutualInformationTest::it_should_add_and_retrieve_the_elapsed_time ());
  cout << endl;

  */

  // Testing Class UCurveToolBox
  current_class = "UCurveToolBoxTest";
  result ("UCurveToolBoxTest::it_should_not_update_lower_restriction_set_with_a_covered_subset", 
    UCurveToolBoxTest::it_should_not_update_lower_restriction_set_with_a_covered_subset ());
  result ("UCurveToolBoxTest::it_should_update_lower_restriction_set_with_an_outer_subset", 
    UCurveToolBoxTest::it_should_update_lower_restriction_set_with_an_outer_subset ());
  result ("UCurveToolBoxTest::it_should_not_update_upper_restriction_set_with_a_covered_subset", 
    UCurveToolBoxTest::it_should_not_update_upper_restriction_set_with_a_covered_subset ());
  result ("UCurveToolBoxTest::it_should_update_upper_restriction_set_with_an_outer_subset", 
    UCurveToolBoxTest::it_should_update_upper_restriction_set_with_an_outer_subset ());
  result ("UCurveToolBoxTest::it_should_get_a_maximal_subset", 
    UCurveToolBoxTest::it_should_get_a_maximal_subset ());
  cout << endl;

  //Testing class "UcurveBranchandBound"
  //
  current_class = "UcurveBranchandBoundTest";
  result ("a_lattice_with_constant_cost_should_be_totally_exausted",
    UcurveBranchandBoundTest::a_lattice_with_constant_cost_should_be_totally_exausted ());
  result ("it_should_find_a_global_minimum",
    UcurveBranchandBoundTest::it_should_find_a_global_minimum ());
  result ("it_should_converge_for_large_hamming_sets",
    UcurveBranchandBoundTest::it_should_converge_for_large_hamming_sets ());
  result ("it_should_converge_for_large_subset_sum_sets",
    UcurveBranchandBoundTest::it_should_converge_for_large_subset_sum_sets ());
  result ("it_should_store_all_the_visited_subsets",
    UcurveBranchandBoundTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    UcurveBranchandBoundTest::it_should_give_the_number_of_the_visited_subsets ());
  result ("it_should_always_give_the_correct_answer",
    UcurveBranchandBoundTest::it_should_always_give_the_correct_answer ());
  cout << endl;

  //Testing class "ExhaustiveSearch"
  //
  current_class = "ExhaustiveSearchTest";
  result ("a_lattice_with_constant_cost_should_be_totally_exausted",
    ExhaustiveSearchTest::a_lattice_with_constant_cost_should_be_totally_exausted ());
  result ("it_should_find_a_global_minimum",
    ExhaustiveSearchTest::it_should_find_a_global_minimum ());
  result ("it_should_store_all_the_visited_subsets",
    ExhaustiveSearchTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    ExhaustiveSearchTest::it_should_give_the_number_of_the_visited_subsets ());
  cout << endl;

  //Testing class "SFS"
  //
  current_class = "SFSTest";
  result ("it_should_find_a_local_minimum",
    SFSTest::it_should_find_a_local_minimum ());
  result ("it_should_store_all_the_visited_subsets",
    SFSTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    SFSTest::it_should_give_the_number_of_the_visited_subsets ());
  result ("it_should_converge_for_large_hamming_sets",
    SFSTest::it_should_converge_for_large_hamming_sets ());
  cout << endl;

  //Testing class "SFFS"
  //
  current_class = "SFFSTest";
  result ("it_should_add_the_best_element",
    SFFSTest::it_should_add_the_best_element ());
  result ("it_should_remove_the_worst_element",
    SFFSTest::it_should_remove_the_worst_element ());
  result ("it_should_find_a_local_minimum",
    SFFSTest::it_should_find_a_local_minimum ());
  result ("it_should_store_all_the_visited_subsets",
    SFFSTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    SFFSTest::it_should_give_the_number_of_the_visited_subsets ());
  result ("it_should_converge_for_large_hamming_sets",
    SFFSTest::it_should_converge_for_large_hamming_sets ());
  cout << endl;

  //Testing class "PUCS"
  //
  current_class = "PUCSTest";
  result ("it_should_store_all_the_visited_subsets",
    PUCSTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    PUCSTest::it_should_give_the_number_of_the_visited_subsets ());
  cout << endl;

  //Testing class "UCurveSearch"
  //
  current_class = "UCurveSearchTest";
  result ("it_should_store_all_the_visited_subsets",
    UCurveSearchTest::it_should_store_all_the_visited_subsets ());
  result ("it_should_give_the_number_of_the_visited_subsets",
    UCurveSearchTest::it_should_give_the_number_of_the_visited_subsets ());
  cout << endl;

  //Testing class "SpecCMI"
  //
  current_class = "SpecCMITest";
  result ("it_should_compute_the_Q_matrix",
    SpecCMITest::it_should_compute_the_Q_matrix ());
  result ("it_should_return_a_correct_solution_for_the_example_in_NX_Vinh_et_al",
    SpecCMITest::it_should_return_a_correct_solution_for_the_example_in_NX_Vinh_et_al ());
  result ("it_should_converge_for_instances_with_hundreds_of_features",
    SpecCMITest::it_should_converge_for_instances_with_hundreds_of_features ());
  result ("it_should_converge_for_instances_with_thousands_of_features",
    SpecCMITest::it_should_converge_for_instances_with_thousands_of_features ());
  cout << endl;


  // Summary of the executed tests
  //
  cout << "Total " << number_of_passed_tests + number_of_failed_tests <<
  " test(s), ";
  cout << number_of_passed_tests << " test(s) passed, " <<
  number_of_failed_tests;
  cout << " test(s) failed." << endl << endl;

  // End of tests
  //
  return EXIT_SUCCESS;
}
