
foreach(EXAMPLE
    simple_iteration
    smallest_code
    truncate_on_codepoint
    truncate_on_grapheme
    grapheme_iteration
    normalization_form_d
    normalization_form_d_utf32
    normalization_form_c
    normalization_form_c_utf32
    normalization_form_kd
    normalization_form_kd_utf32
    normalization_form_kc
    normalization_form_kc_utf32
    )
  add_executable(${EXAMPLE} ${EXAMPLE}.cpp)
  target_compile_options(${EXAMPLE} PUBLIC -std=c++1y)
  target_link_libraries(${EXAMPLE} u5e)
endforeach(EXAMPLE)
