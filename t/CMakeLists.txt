foreach(TEST
    001_version
    002_utf32_encoded_iterator
    003_utf8_encoded_iterator
    005_grapheme_cluster
    006_grapheme_iterator
    007_utf8_bounds
    008_filter
    009_canonical_decomposition_mapping
    010_canonical_decomposition
    011_canonical_combining_class
    012_normalization_form_d_utf32ne
    013_normalization_form_d_utf8
    014_canonical_composition_mapping
    015_normalization_form_c_utf8
    016_normalization_form_c_utf32ne
    017_compatibility_and_canonical_decomposition_mapping
    018_normalization_form_kd_utf32ne
    019_normalization_form_kc_utf32ne
    )
  add_executable(${TEST}.t ${TEST}.t.cpp)
  target_compile_options(${TEST}.t PUBLIC -std=c++1y)
  target_link_libraries(${TEST}.t u5e gtest gtest_main)
  add_test(${TEST} ${TEST}.t)
endforeach(TEST)
