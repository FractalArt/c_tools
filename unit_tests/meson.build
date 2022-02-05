unit_tests = [
  'test_vec'
]

foreach t: unit_tests
  exe = executable(t, t + '.c',
                   include_directories: [include_dirs],
                   link_with: libs,
                   dependencies: deps)
  test(t, exe, suite : 'unit_test')
endforeach
